; ModuleID = '../examples/fib.rb'
source_filename = "../examples/fib.rb"

define i32 @fib(i32 %x) {
entry:
  %x1 = alloca i32
  %retvar = alloca i32
  store i32 %x, i32* %x1
  %0 = load i32, i32* %x1
  %1 = icmp sle i32 %0, 0
  br i1 %1, label %_then, label %_end

_then:                                            ; preds = %entry
  store i32 0, i32* %retvar
  br label %_ret

_end:                                             ; preds = %_then, %entry
  %2 = load i32, i32* %x1
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %_then2, label %_end3

_then2:                                           ; preds = %_end
  store i32 1, i32* %retvar
  br label %_ret

_end3:                                            ; preds = %_then2, %_end
  %4 = load i32, i32* %x1
  %add = sub i32 %4, 1
  %5 = call i32 @fib(i32 %add)
  %6 = load i32, i32* %x1
  %add4 = sub i32 %6, 2
  %7 = call i32 @fib(i32 %add4)
  %add5 = add i32 %5, %7
  store i32 %add5, i32* %retvar
  br label %_ret

_ret:                                             ; preds = %_end3, %_then2, %_then
  %8 = load i32, i32* %retvar
  ret i32 %8
}

define i32 @main() {
entry:
  %z = alloca i32
  %retvar = alloca i32
  store i32 8, i32* %z
  %0 = load i32, i32* %z
  %1 = call i32 @fib(i32 5)
  %add = add i32 %0, %1
  store i32 %add, i32* %z
  %2 = load i32, i32* %z
  %3 = call i32 @fib(i32 %2)
  store i32 %3, i32* %retvar
  br label %_ret

_ret:                                             ; preds = %entry
  %4 = load i32, i32* %retvar
  ret i32 %4
}
