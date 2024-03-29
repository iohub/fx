; ModuleID = '../../examples/fib.x'
source_filename = "../../examples/fib.x"

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
  %4 = load i32, i32* %x1
  %add = sub i32 %4, 1
  %5 = call i32 @fib(i32 %add)
  %6 = load i32, i32* %x1
  %add4 = sub i32 %6, 2
  %7 = call i32 @fib(i32 %add4)
  %add5 = add i32 %5, %7
  store i32 %add5, i32* %fib_retvar
  br label %_ret

_ret:                                             ; preds = %_end3, %_then2, %_then
  %8 = load i32, i32* %fib_retvar
  ret i32 %8
}

define void @add(i32 %y) {
entry:
  %y12 = alloca i32
  %y1 = alloca i32
  store i32 %y, i32* %y1
  %0 = load i32, i32* %y1
  %add = add i32 %0, 10
  store i32 %add, i32* %y12
  %1 = load i32, i32* %y12
  %add3 = add i32 %1, 100
  store i32 %add3, i32* %y12
  ret void
}

define void @sub(i32 %y2) {
entry:
  %y21 = alloca i32
  store i32 %y2, i32* %y21
  %0 = load i32, i32* %y21
  %add = sub i32 %0, 100
  store i32 %add, i32* %y21
  ret void
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

!nvvm.annotations = !{!0, !1}

!0 = !{void (i32)* @add, !"kernel", i32 1}
!1 = !{void (i32)* @sub, !"kernel", i32 1}
