cmake_minimum_required(VERSION 3.9)
project(Latte)

set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

find_library(ANTLR4_RUNTIME
        antlr4-runtime
        PATHS ${CMAKE_SOURCE_DIR}/lib
        NO_DEFAULT_PATH
        )

if (NOT ANTLR4_RUNTIME)
    message(FATAL_ERROR "antlr4-runtime not found")
endif()

include_directories(include)

add_executable(lattec src/main.cpp src/Context.cpp src/Context.h src/ClassMetadata.cpp src/ClassMetadata.h src/types/Type.cpp src/types/Type.h src/types/IntType.cpp src/types/IntType.h src/types/ClassType.cpp src/types/ClassType.h src/registries/TypeRegistry.cpp src/registries/TypeRegistry.h src/types/BooleanType.cpp src/types/BooleanType.h src/types/FunctionType.cpp src/types/FunctionType.h src/types/NamedType.cpp src/types/NamedType.h src/IdEnv.cpp src/IdEnv.h src/IdEnvEntry.cpp src/IdEnvEntry.h src/scopes/GlobalScope.cpp src/scopes/GlobalScope.h src/scopes/FunctionScope.cpp src/scopes/FunctionScope.h src/scopes/ClassScope.cpp src/scopes/ClassScope.h src/scopes/BlockScope.cpp src/scopes/BlockScope.h src/ClassScopeEnv.cpp src/ClassScopeEnv.h src/types/BytePtrType.cpp src/types/BytePtrType.h src/parser/LatteBaseListener.h src/parser/LatteBaseListener.cpp src/parser/LatteBaseVisitor.h src/parser/LatteBaseVisitor.cpp src/parser/LatteLexer.h src/parser/LatteLexer.cpp src/parser/LatteListener.h src/parser/LatteListener.cpp src/parser/LatteParser.h src/parser/LatteParser.cpp src/parser/LatteVisitor.h src/parser/LatteVisitor.cpp src/types/StringType.cpp src/types/StringType.h src/types/VoidType.cpp src/types/VoidType.h src/visitors/GlobalScopeVisitor.cpp src/visitors/GlobalScopeVisitor.h src/parser/LatteErrorListener.cpp src/parser/LatteErrorListener.h src/registries/ScopeRegistry.cpp src/registries/ScopeRegistry.h)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs core)

target_link_libraries(lattec
        PRIVATE
        ${llvm_libs}
        ${ANTLR4_RUNTIME}
)
