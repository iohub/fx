; ModuleID = '../examples/fib.c'
source_filename = "../examples/fib.c"

define i32 @fib(i32 %x) {
entry:
  %y = alloca i32
  %x1 = alloca i32
  %fib_retvar = alloca i32
  store i32 %x, i32* %x1
  %0 = load i32, i32* %x1
  %1 = icmp sle i32 %0, 0
  br i1 %1, label %_then, label %_end

_then:                                            ; preds = %entry
  store i32 0, i32* %fib_retvar
  br label %_ret

_end:                                             ; preds = %entry
  %2 = load i32, i32* %x1
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %_then2, label %_end3

_then2:                                           ; preds = %_end
  store i32 1, i32* %fib_retvar
  br label %_ret

_end3:                                            ; preds = %_end
  %4 = load i32, i32* %x1
  %add = sub i32 %4, 10
  %5 = load i32, i32* %y
  store i32 %add, i32 %5
  %6 = load i32, i32* %x1
  %sub = fsub i32 %6, 1
  %7 = call i32 @fib(i32 %sub)
  %8 = load i32, i32* %x1
  %sub4 = fsub i32 %8, 2
  %9 = call i32 @fib(i32 %sub4)
  %add5 = fadd i32 %7, %9
  store i32 %add5, i32* %fib_retvar
  br label %_ret

_ret:                                             ; preds = %_end3, %_then2, %_then
  %10 = load i32, i32* %fib_retvar
  ret i32 %10
}

define i32 @main() {
entry:
  %main_retvar = alloca i32
  %0 = call i32 @fib(i32 5)
  store i32 %0, i32* %main_retvar
  br label %_ret

_ret:                                             ; preds = %entry
  %1 = load i32, i32* %main_retvar
  ret i32 %1
}
