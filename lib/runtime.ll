; ModuleID = 'runtime_str.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.12.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [14 x i8] c"runtime error\00", align 1
@__stdinp = external global %struct.__sFILE*, align 8

; Function Attrs: nounwind ssp uwtable
define i8* @getString(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i32*, align 8
  %6 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %7 = load i8*, i8** %2, align 8
  %8 = call i64 @strlen(i8* %7)
  store i64 %8, i64* %3, align 8
  %9 = load i64, i64* %3, align 8
  %10 = add i64 %9, 1
  %11 = add i64 %10, 4
  %12 = call i8* @malloc(i64 %11)
  store i8* %12, i8** %4, align 8
  %13 = load i8*, i8** %4, align 8
  %14 = bitcast i8* %13 to i32*
  store i32* %14, i32** %5, align 8
  %15 = load i32*, i32** %5, align 8
  store i32 1, i32* %15, align 4
  %16 = load i32*, i32** %5, align 8
  %17 = getelementptr inbounds i32, i32* %16, i64 1
  store i32* %17, i32** %5, align 8
  %18 = load i32*, i32** %5, align 8
  %19 = bitcast i32* %18 to i8*
  store i8* %19, i8** %6, align 8
  %20 = load i8*, i8** %6, align 8
  %21 = load i8*, i8** %2, align 8
  %22 = load i8*, i8** %6, align 8
  %23 = call i64 @llvm.objectsize.i64.p0i8(i8* %22, i1 false)
  %24 = call i8* @__strcpy_chk(i8* %20, i8* %21, i64 %23) #5
  %25 = load i8*, i8** %6, align 8
  ret i8* %25
}

declare i64 @strlen(i8*) #1

declare i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i8* @__strcpy_chk(i8*, i8*, i64) #2

; Function Attrs: nounwind readnone
declare i64 @llvm.objectsize.i64.p0i8(i8*, i1) #3

; Function Attrs: nounwind ssp uwtable
define void @refString(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i32*, align 8
  store i8* %0, i8** %2, align 8
  %5 = load i8*, i8** %2, align 8
  %6 = call i64 @strlen(i8* %5)
  store i64 %6, i64* %3, align 8
  %7 = load i64, i64* %3, align 8
  %8 = icmp ne i64 %7, 0
  br i1 %8, label %9, label %17

; <label>:9:                                      ; preds = %1
  %10 = load i8*, i8** %2, align 8
  %11 = bitcast i8* %10 to i32*
  store i32* %11, i32** %4, align 8
  %12 = load i32*, i32** %4, align 8
  %13 = getelementptr inbounds i32, i32* %12, i64 -1
  store i32* %13, i32** %4, align 8
  %14 = load i32*, i32** %4, align 8
  %15 = load i32, i32* %14, align 4
  %16 = add nsw i32 %15, 1
  store i32 %16, i32* %14, align 4
  br label %17

; <label>:17:                                     ; preds = %9, %1
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @derefString(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i32*, align 8
  store i8* %0, i8** %2, align 8
  %5 = load i8*, i8** %2, align 8
  %6 = call i64 @strlen(i8* %5)
  store i64 %6, i64* %3, align 8
  %7 = load i64, i64* %3, align 8
  %8 = icmp ne i64 %7, 0
  br i1 %8, label %9, label %25

; <label>:9:                                      ; preds = %1
  %10 = load i8*, i8** %2, align 8
  %11 = bitcast i8* %10 to i32*
  store i32* %11, i32** %4, align 8
  %12 = load i32*, i32** %4, align 8
  %13 = getelementptr inbounds i32, i32* %12, i64 -1
  store i32* %13, i32** %4, align 8
  %14 = load i32*, i32** %4, align 8
  %15 = load i32, i32* %14, align 4
  %16 = sub nsw i32 %15, 1
  store i32 %16, i32* %14, align 4
  %17 = load i32*, i32** %4, align 8
  %18 = load i32, i32* %17, align 4
  %19 = icmp sle i32 %18, 0
  br i1 %19, label %20, label %24

; <label>:20:                                     ; preds = %9
  %21 = load i32*, i32** %4, align 8
  %22 = bitcast i32* %21 to i8*
  store i8* %22, i8** %2, align 8
  %23 = load i8*, i8** %2, align 8
  call void @free(i8* %23)
  br label %24

; <label>:24:                                     ; preds = %20, %9
  br label %25

; <label>:25:                                     ; preds = %24, %1
  ret void
}

declare void @free(i8*) #1

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
  call void @exit(i32 1) #6
  unreachable
                                                  ; No predecessors!
  ret void
}

; Function Attrs: noreturn
declare void @exit(i32) #4

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
  %4 = alloca i8*, align 8
  store i8* null, i8** %1, align 8
  store i64 0, i64* %2, align 8
  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stdinp, align 8
  %6 = call i64 @getline(i8** %1, i64* %2, %struct.__sFILE* %5)
  %7 = load i8*, i8** %1, align 8
  store i8* %7, i8** %3, align 8
  br label %8

; <label>:8:                                      ; preds = %13, %0
  %9 = load i8*, i8** %3, align 8
  %10 = load i8, i8* %9, align 1
  %11 = sext i8 %10 to i32
  %12 = icmp ne i32 %11, 10
  br i1 %12, label %13, label %16

; <label>:13:                                     ; preds = %8
  %14 = load i8*, i8** %3, align 8
  %15 = getelementptr inbounds i8, i8* %14, i32 1
  store i8* %15, i8** %3, align 8
  br label %8

; <label>:16:                                     ; preds = %8
  %17 = load i8*, i8** %3, align 8
  store i8 0, i8* %17, align 1
  %18 = load i8*, i8** %1, align 8
  %19 = call i8* @getString(i8* %18)
  store i8* %19, i8** %4, align 8
  %20 = load i8*, i8** %1, align 8
  call void @free(i8* %20)
  %21 = load i8*, i8** %4, align 8
  ret i8* %21
}

declare i64 @getline(i8**, i64*, %struct.__sFILE*) #1

; Function Attrs: nounwind ssp uwtable
define i8* @concatStrings(i8*, i8*) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i64, align 8
  %7 = alloca i8*, align 8
  %8 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  store i8* %1, i8** %4, align 8
  %9 = load i8*, i8** %3, align 8
  %10 = call i64 @strlen(i8* %9)
  store i64 %10, i64* %5, align 8
  %11 = load i8*, i8** %4, align 8
  %12 = call i64 @strlen(i8* %11)
  store i64 %12, i64* %6, align 8
  %13 = load i64, i64* %5, align 8
  %14 = load i64, i64* %6, align 8
  %15 = add i64 %13, %14
  %16 = add i64 %15, 1
  %17 = call i8* @malloc(i64 %16)
  store i8* %17, i8** %7, align 8
  %18 = load i8*, i8** %7, align 8
  %19 = load i8*, i8** %3, align 8
  %20 = load i8*, i8** %7, align 8
  %21 = call i64 @llvm.objectsize.i64.p0i8(i8* %20, i1 false)
  %22 = call i8* @__strcpy_chk(i8* %18, i8* %19, i64 %21) #5
  %23 = load i8*, i8** %7, align 8
  %24 = load i8*, i8** %4, align 8
  %25 = load i8*, i8** %7, align 8
  %26 = call i64 @llvm.objectsize.i64.p0i8(i8* %25, i1 false)
  %27 = call i8* @__strcat_chk(i8* %23, i8* %24, i64 %26) #5
  %28 = load i8*, i8** %7, align 8
  %29 = call i8* @getString(i8* %28)
  store i8* %29, i8** %8, align 8
  %30 = load i8*, i8** %7, align 8
  call void @free(i8* %30)
  %31 = load i8*, i8** %8, align 8
  ret i8* %31
}

; Function Attrs: nounwind
declare i8* @__strcat_chk(i8*, i8*, i64) #2

attributes #0 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readnone }
attributes #4 = { noreturn "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind }
attributes #6 = { noreturn }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.9.0 "}
