; ModuleID = 'runtime.c'

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [14 x i8] c"runtime error\00", align 1
@.str.2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@__stdinp = external global %struct.__sFILE*, align 8
@.str.3 = private unnamed_addr constant [7 x i8] c"Siema \00", align 1
@.str.4 = private unnamed_addr constant [6 x i8] c"eniu!\00", align 1

; Function Attrs: nounwind ssp uwtable
define void @printInt(i32) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %3)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind ssp uwtable
define void @printString(i8*) #0 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load i8*, i8** %2, align 8
  %4 = call i32 @puts(i8* %3)
  ret void
}

declare i32 @puts(i8*) #1

; Function Attrs: nounwind ssp uwtable
define void @error() #0 {
  %1 = call i32 @puts(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable
                                                  ; No predecessors!
  ret void
}

; Function Attrs: noreturn
declare void @exit(i32) #2

; Function Attrs: nounwind ssp uwtable
define i32 @readInt() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32* %1)
  %3 = load i32, i32* %1, align 4
  ret i32 %3
}

declare i32 @scanf(i8*, ...) #1

; Function Attrs: nounwind ssp uwtable
define i8* @readString() #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  store i8* null, i8** %1, align 8
  store i64 0, i64* %2, align 8
  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stdinp, align 8
  %5 = call i64 @getline(i8** %1, i64* %2, %struct.__sFILE* %4)
  %6 = load i8*, i8** %1, align 8
  store i8* %6, i8** %3, align 8
  br label %7

; <label>:7:                                      ; preds = %12, %0
  %8 = load i8*, i8** %3, align 8
  %9 = load i8, i8* %8, align 1
  %10 = sext i8 %9 to i32
  %11 = icmp ne i32 %10, 10
  br i1 %11, label %12, label %15

; <label>:12:                                     ; preds = %7
  %13 = load i8*, i8** %3, align 8
  %14 = getelementptr inbounds i8, i8* %13, i32 1
  store i8* %14, i8** %3, align 8
  br label %7

; <label>:15:                                     ; preds = %7
  %16 = load i8*, i8** %3, align 8
  store i8 0, i8* %16, align 1
  %17 = load i8*, i8** %1, align 8
  ret i8* %17
}

declare i64 @getline(i8**, i64*, %struct.__sFILE*) #1

; Function Attrs: nounwind ssp uwtable
define i8* @concatStrings(i8*, i8*) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i64, align 8
  %7 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  store i8* %1, i8** %4, align 8
  %8 = load i8*, i8** %3, align 8
  %9 = call i64 @strlen(i8* %8)
  store i64 %9, i64* %5, align 8
  %10 = load i8*, i8** %4, align 8
  %11 = call i64 @strlen(i8* %10)
  store i64 %11, i64* %6, align 8
  %12 = load i64, i64* %5, align 8
  %13 = load i64, i64* %6, align 8
  %14 = add i64 %12, %13
  %15 = add i64 %14, 1
  %16 = call i8* @malloc(i64 %15)
  store i8* %16, i8** %7, align 8
  %17 = load i8*, i8** %7, align 8
  %18 = load i8*, i8** %3, align 8
  %19 = load i8*, i8** %7, align 8
  %20 = call i64 @llvm.objectsize.i64.p0i8(i8* %19, i1 false)
  %21 = call i8* @__strcpy_chk(i8* %17, i8* %18, i64 %20) #6
  %22 = load i8*, i8** %7, align 8
  %23 = load i8*, i8** %4, align 8
  %24 = load i8*, i8** %7, align 8
  %25 = call i64 @llvm.objectsize.i64.p0i8(i8* %24, i1 false)
  %26 = call i8* @__strcat_chk(i8* %22, i8* %23, i64 %25) #6
  %27 = load i8*, i8** %7, align 8
  ret i8* %27
}

declare i64 @strlen(i8*) #1

declare i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i8* @__strcpy_chk(i8*, i8*, i64) #3

; Function Attrs: nounwind readnone
declare i64 @llvm.objectsize.i64.p0i8(i8*, i1) #4

; Function Attrs: nounwind
declare i8* @__strcat_chk(i8*, i8*, i64) #3

