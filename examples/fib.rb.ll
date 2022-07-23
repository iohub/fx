; ModuleID = '../examples/fib.rb'
source_filename = "../examples/fib.rb"

define i32 @fib(i32 %x) {
entry:
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

_ret:                                             ; preds = %_then2, %_then
  %4 = load i32, i32* %fib_retvar
  ret i32 %4
}
