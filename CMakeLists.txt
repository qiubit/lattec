cmake_minimum_required(VERSION 3.8)
project(Latte)

set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Find / install antlr4-runtime
include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

# Find LLVM
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs core)

# Compile src/runtime/runtime.c to get platform-specific LLVM IR
execute_process(
        COMMAND bash -c "mkdir -p ${CMAKE_CURRENT_SOURCE_DIR}/lib; clang -emit-llvm -S ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/runtime.c -o ${CMAKE_CURRENT_SOURCE_DIR}/lib/runtime.ll"
        RESULT_VARIABLE RUNTIME_ERR
)
if (RUNTIME_ERR)
        message(FATAL_ERROR "Runtime compile failure. Make sure you have clang installed.")
endif()

add_executable(lattec src/main.cpp src/Context.cpp src/Context.h src/types/Type.cpp src/types/Type.h src/types/IntType.cpp src/types/IntType.h src/types/ClassType.cpp src/types/ClassType.h src/registries/TypeRegistry.cpp src/registries/TypeRegistry.h src/types/BooleanType.cpp src/types/BooleanType.h src/types/FunctionType.cpp src/types/FunctionType.h src/types/NamedType.cpp src/types/NamedType.h src/IdEnv.cpp src/IdEnv.h src/IdEnvEntry.cpp src/IdEnvEntry.h src/scopes/GlobalScope.cpp src/scopes/GlobalScope.h src/scopes/FunctionScope.cpp src/scopes/FunctionScope.h src/scopes/ClassScope.cpp src/scopes/ClassScope.h src/scopes/BlockScope.cpp src/scopes/BlockScope.h src/ClassScopeEnv.cpp src/ClassScopeEnv.h src/types/BytePtrType.cpp src/types/BytePtrType.h src/parser/LatteBaseListener.h src/parser/LatteBaseListener.cpp src/parser/LatteBaseVisitor.h src/parser/LatteBaseVisitor.cpp src/parser/LatteLexer.h src/parser/LatteLexer.cpp src/parser/LatteListener.h src/parser/LatteListener.cpp src/parser/LatteParser.h src/parser/LatteParser.cpp src/parser/LatteVisitor.h src/parser/LatteVisitor.cpp src/types/StringType.cpp src/types/StringType.h src/types/VoidType.cpp src/types/VoidType.h src/visitors/GlobalScopeVisitor.cpp src/visitors/GlobalScopeVisitor.h src/parser/LatteErrorListener.cpp src/parser/LatteErrorListener.h src/registries/ScopeRegistry.cpp src/registries/ScopeRegistry.h src/visitors/FunctionScopeVisitor.cpp src/visitors/FunctionScopeVisitor.h src/ExprEnv.cpp src/ExprEnv.h src/operations/Op.cpp src/operations/Op.h src/operations/NewOp.cpp src/operations/NewOp.h src/operations/IntNegOp.cpp src/operations/IntNegOp.h src/operations/BooleanNotOp.cpp src/operations/BooleanNotOp.h src/operations/TypedNullOp.cpp src/operations/TypedNullOp.h src/operations/BooleanAndOp.cpp src/operations/BooleanAndOp.h src/operations/BooleanOrOp.cpp src/operations/BooleanOrOp.h src/operations/BooleanEqOp.cpp src/operations/BooleanEqOp.h src/operations/IntEqOp.cpp src/operations/IntEqOp.h src/operations/PtrEqOp.cpp src/operations/PtrEqOp.h src/operations/BooleanNeqOp.cpp src/operations/BooleanNeqOp.h src/operations/IntNeqOp.cpp src/operations/IntNeqOp.h src/operations/PtrNeqOp.cpp src/operations/PtrNeqOp.h src/operations/IntGtOp.cpp src/operations/IntGtOp.h src/operations/IntGeqOp.cpp src/operations/IntGeqOp.h src/operations/IntLtOp.cpp src/operations/IntLtOp.h src/operations/IntLeqOp.cpp src/operations/IntLeqOp.h src/operations/StringAddOp.cpp src/operations/StringAddOp.h src/operations/IntAddOp.cpp src/operations/IntAddOp.h src/operations/IntMulOp.cpp src/operations/IntMulOp.h src/operations/IntDivOp.cpp src/operations/IntDivOp.h src/operations/IntModOp.cpp src/operations/IntModOp.h src/operations/ConstIntOp.cpp src/operations/ConstIntOp.h src/operations/ConstBooleanOp.cpp src/operations/ConstBooleanOp.h src/operations/ConstStringOp.cpp src/operations/ConstStringOp.h src/operations/ClassFunCallOp.cpp src/operations/ClassFunCallOp.h src/operations/ClassIdOp.cpp src/operations/ClassIdOp.h src/operations/VarOp.cpp src/operations/VarOp.h src/operations/ClassVarOp.cpp src/operations/ClassVarOp.h src/scopes/Scope.cpp src/scopes/Scope.h src/visitors/CodegenVisitor.cpp src/visitors/CodegenVisitor.h src/types/ArrayType.cpp src/types/ArrayType.h)

target_link_libraries(lattec
        PUBLIC
        antlr4_static
        ${llvm_libs}
)

set_target_properties(lattec
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

add_custom_command(TARGET lattec POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/bash/latc_llvm ${CMAKE_SOURCE_DIR}/latc_llvm
)
