; ModuleID = 'runtime_str.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [14 x i8] c"runtime error\00", align 1
@stdin = external global %struct._IO_FILE*, align 8

; Function Attrs: nounwind uwtable
define i8* @getString(i8* %s) #0 {
  %1 = alloca i8*, align 8
  %sLen = alloca i64, align 8
  %buf = alloca i8*, align 8
  %refCnt = alloca i32*, align 8
  %bufStr = alloca i8*, align 8
  store i8* %s, i8** %1, align 8
  %2 = load i8*, i8** %1, align 8
  %3 = call i64 @strlen(i8* %2) #5
  store i64 %3, i64* %sLen, align 8
  %4 = load i64, i64* %sLen, align 8
  %5 = add i64 %4, 1
  %6 = add i64 %5, 4
  %7 = call noalias i8* @malloc(i64 %6) #6
  store i8* %7, i8** %buf, align 8
  %8 = load i8*, i8** %buf, align 8
  %9 = bitcast i8* %8 to i32*
  store i32* %9, i32** %refCnt, align 8
  %10 = load i32*, i32** %refCnt, align 8
  store i32 1, i32* %10, align 4
  %11 = load i32*, i32** %refCnt, align 8
  %12 = getelementptr inbounds i32, i32* %11, i64 1
  store i32* %12, i32** %refCnt, align 8
  %13 = load i32*, i32** %refCnt, align 8
  %14 = bitcast i32* %13 to i8*
  store i8* %14, i8** %bufStr, align 8
  %15 = load i8*, i8** %bufStr, align 8
  %16 = load i8*, i8** %1, align 8
  %17 = call i8* @strcpy(i8* %15, i8* %16) #6
  %18 = load i8*, i8** %bufStr, align 8
  ret i8* %18
}

; Function Attrs: nounwind readonly
declare i64 @strlen(i8*) #1

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #2

; Function Attrs: nounwind
declare i8* @strcpy(i8*, i8*) #2

; Function Attrs: nounwind uwtable
define void @refString(i8* %s) #0 {
  %1 = alloca i8*, align 8
  %sLen = alloca i64, align 8
  %refCnt = alloca i32*, align 8
  store i8* %s, i8** %1, align 8
  %2 = load i8*, i8** %1, align 8
  %3 = call i64 @strlen(i8* %2) #5
  store i64 %3, i64* %sLen, align 8
  %4 = load i64, i64* %sLen, align 8
  %5 = icmp ne i64 %4, 0
  br i1 %5, label %6, label %14

; <label>:6                                       ; preds = %0
  %7 = load i8*, i8** %1, align 8
  %8 = bitcast i8* %7 to i32*
  store i32* %8, i32** %refCnt, align 8
  %9 = load i32*, i32** %refCnt, align 8
  %10 = getelementptr inbounds i32, i32* %9, i64 -1
  store i32* %10, i32** %refCnt, align 8
  %11 = load i32*, i32** %refCnt, align 8
  %12 = load i32, i32* %11, align 4
  %13 = add nsw i32 %12, 1
  store i32 %13, i32* %11, align 4
  br label %14

; <label>:14                                      ; preds = %6, %0
  ret void
}

; Function Attrs: nounwind uwtable
define void @derefString(i8* %s) #0 {
  %1 = alloca i8*, align 8
  %sLen = alloca i64, align 8
  %refCnt = alloca i32*, align 8
  store i8* %s, i8** %1, align 8
  %2 = load i8*, i8** %1, align 8
  %3 = call i64 @strlen(i8* %2) #5
  store i64 %3, i64* %sLen, align 8
  %4 = load i64, i64* %sLen, align 8
  %5 = icmp ne i64 %4, 0
  br i1 %5, label %6, label %22

; <label>:6                                       ; preds = %0
  %7 = load i8*, i8** %1, align 8
  %8 = bitcast i8* %7 to i32*
  store i32* %8, i32** %refCnt, align 8
  %9 = load i32*, i32** %refCnt, align 8
  %10 = getelementptr inbounds i32, i32* %9, i64 -1
  store i32* %10, i32** %refCnt, align 8
  %11 = load i32*, i32** %refCnt, align 8
  %12 = load i32, i32* %11, align 4
  %13 = sub nsw i32 %12, 1
  store i32 %13, i32* %11, align 4
  %14 = load i32*, i32** %refCnt, align 8
  %15 = load i32, i32* %14, align 4
  %16 = icmp sle i32 %15, 0
  br i1 %16, label %17, label %21

; <label>:17                                      ; preds = %6
  %18 = load i32*, i32** %refCnt, align 8
  %19 = bitcast i32* %18 to i8*
  store i8* %19, i8** %1, align 8
  %20 = load i8*, i8** %1, align 8
  call void @free(i8* %20) #6
  br label %21

; <label>:21                                      ; preds = %17, %6
  br label %22

; <label>:22                                      ; preds = %21, %0
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #2

; Function Attrs: nounwind uwtable
define void @printInt(i32 %x) #0 {
  %1 = alloca i32, align 4
  store i32 %x, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %2)
  ret void
}

declare i32 @printf(i8*, ...) #3

; Function Attrs: nounwind uwtable
define void @printString(i8* %s) #0 {
  %1 = alloca i8*, align 8
  store i8* %s, i8** %1, align 8
  %2 = load i8*, i8** %1, align 8
  %3 = call i32 @puts(i8* %2)
  ret void
}

declare i32 @puts(i8*) #3

; Function Attrs: nounwind uwtable
define void @error() #0 {
  %1 = call i32 @puts(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.1, i32 0, i32 0))
  call void @exit(i32 1) #7
  unreachable
                                                  ; No predecessors!
  ret void
}

; Function Attrs: noreturn nounwind
declare void @exit(i32) #4

; Function Attrs: nounwind uwtable
define i32 @readInt() #0 {
  %x = alloca i32, align 4
  %1 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32* %x)
  %2 = load i32, i32* %x, align 4
  ret i32 %2
}

declare i32 @__isoc99_scanf(i8*, ...) #3

; Function Attrs: nounwind uwtable
define i8* @readString() #0 {
  %line = alloca i8*, align 8
  %linecap = alloca i64, align 8
  %lp = alloca i8*, align 8
  %ret = alloca i8*, align 8
  store i8* null, i8** %line, align 8
  store i64 0, i64* %linecap, align 8
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stdin, align 8
  %2 = call i64 @getline(i8** %line, i64* %linecap, %struct._IO_FILE* %1)
  %3 = load i8*, i8** %line, align 8
  store i8* %3, i8** %lp, align 8
  br label %4

; <label>:4                                       ; preds = %9, %0
  %5 = load i8*, i8** %lp, align 8
  %6 = load i8, i8* %5, align 1
  %7 = sext i8 %6 to i32
  %8 = icmp ne i32 %7, 10
  br i1 %8, label %9, label %12

; <label>:9                                       ; preds = %4
  %10 = load i8*, i8** %lp, align 8
  %11 = getelementptr inbounds i8, i8* %10, i32 1
  store i8* %11, i8** %lp, align 8
  br label %4

; <label>:12                                      ; preds = %4
  %13 = load i8*, i8** %lp, align 8
  store i8 0, i8* %13, align 1
  %14 = load i8*, i8** %line, align 8
  %15 = call i8* @getString(i8* %14)
  store i8* %15, i8** %ret, align 8
  %16 = load i8*, i8** %line, align 8
  call void @free(i8* %16) #6
  %17 = load i8*, i8** %ret, align 8
  ret i8* %17
}

declare i64 @getline(i8**, i64*, %struct._IO_FILE*) #3

; Function Attrs: nounwind uwtable
define i8* @concatStrings(i8* %s1, i8* %s2) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %s1Len = alloca i64, align 8
  %s2Len = alloca i64, align 8
  %buf = alloca i8*, align 8
  %ret = alloca i8*, align 8
  store i8* %s1, i8** %1, align 8
  store i8* %s2, i8** %2, align 8
  %3 = load i8*, i8** %1, align 8
  %4 = call i64 @strlen(i8* %3) #5
  store i64 %4, i64* %s1Len, align 8
  %5 = load i8*, i8** %2, align 8
  %6 = call i64 @strlen(i8* %5) #5
  store i64 %6, i64* %s2Len, align 8
  %7 = load i64, i64* %s1Len, align 8
  %8 = load i64, i64* %s2Len, align 8
  %9 = add i64 %7, %8
  %10 = add i64 %9, 1
  %11 = call noalias i8* @malloc(i64 %10) #6
  store i8* %11, i8** %buf, align 8
  %12 = load i8*, i8** %buf, align 8
  %13 = load i8*, i8** %1, align 8
  %14 = call i8* @strcpy(i8* %12, i8* %13) #6
  %15 = load i8*, i8** %buf, align 8
  %16 = load i8*, i8** %2, align 8
  %17 = call i8* @strcat(i8* %15, i8* %16) #6
  %18 = load i8*, i8** %buf, align 8
  %19 = call i8* @getString(i8* %18)
  store i8* %19, i8** %ret, align 8
  %20 = load i8*, i8** %buf, align 8
  call void @free(i8* %20) #6
  %21 = load i8*, i8** %ret, align 8
  ret i8* %21
}

; Function Attrs: nounwind
declare i8* @strcat(i8*, i8*) #2

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readonly "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind readonly }
attributes #6 = { nounwind }
attributes #7 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (tags/RELEASE_370/final)"}
