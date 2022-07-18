; ModuleID = '../examples/demo.rb'
source_filename = "../examples/demo.rb"

define i1 @conditional(float %x) {
entry:
  %x1 = alloca float
  %conditional_retvar = alloca i1
  store float %x, float* %x1
  %0 = load float, float* %x1
  %1 = fcmp ogt float %0, 1.000000e+01
  store i1 %1, i1* %conditional_retvar
  br label %_ret

_ret:                                             ; preds = %entry
  %2 = load i1, i1* %conditional_retvar
  ret i1 %2
}

define float @foo(float %x, float %y) {
entry:
  %y2 = alloca float
  %x1 = alloca float
  %foo_retvar = alloca float
  store float %x, float* %x1
  store float %y, float* %y2
  %0 = load float, float* %x1
  %1 = call i1 @conditional(float %0)
  br i1 %1, label %_loop, label %_loop_end

_ret:                                             ; preds = %_loop_end5
  %2 = load float, float* %foo_retvar
  ret float %2

_loop:                                            ; preds = %_loop, %entry
  %3 = load float, float* %x1
  %4 = load float, float* %x1
  %add = fadd float %3, %4
  store float %add, float* %x1
  %5 = load float, float* %x1
  %6 = call i1 @conditional(float %5)
  br i1 %6, label %_loop, label %_loop_end

_loop_end:                                        ; preds = %_loop, %entry
  %7 = load float, float* %x1
  %8 = fcmp olt float %7, 2.000000e+01
  br i1 %8, label %_loop3, label %_loop_end5

_loop3:                                           ; preds = %_loop3, %_loop_end
  %9 = load float, float* %x1
  %10 = load float, float* %y2
  %add4 = fadd float %9, %10
  store float %add4, float* %x1
  %11 = load float, float* %x1
  %12 = fcmp olt float %11, 2.000000e+01
  br i1 %12, label %_loop3, label %_loop_end5

_loop_end5:                                       ; preds = %_loop3, %_loop_end
  %13 = load float, float* %x1
  store float %13, float* %foo_retvar
  br label %_ret
}

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

define float @else1(float %x) {
entry:
  %x1 = alloca float
  %else1_retvar = alloca float
  store float %x, float* %x1
  %0 = load float, float* %x1
  %1 = fcmp ogt float %0, 1.000000e+01
  br i1 %1, label %_then, label %_else

_then:                                            ; preds = %entry
  %2 = load float, float* %x1
  %add = fadd float %2, 1.000000e+00
  store float %add, float* %x1
  br label %_end

_else:                                            ; preds = %entry
  %3 = load float, float* %x1
  %add2 = fadd float %3, 2.000000e+00
  store float %add2, float* %x1
  br label %_end

_end:                                             ; preds = %_else, %_then
  %4 = load float, float* %x1
  store float %4, float* %else1_retvar
  br label %_ret

_ret:                                             ; preds = %_end
  %5 = load float, float* %else1_retvar
  ret float %5
}

define i32 @main() {
entry:
  %z = alloca float
  %main_retvar = alloca i32
  %0 = load float, float* %z
  %1 = call float @foo(float 3.000000e+00, float 4.000000e+00)
  %add = fadd float 2.000000e+00, %1
  %2 = call float @foo(float 1.000000e+00, float %add)
  %add1 = fadd float %0, %2
  store float %add1, float* %z
  %3 = call i32 @fib(i32 9)
  store i32 %3, i32* %main_retvar
  br label %_ret

_ret:                                             ; preds = %entry
  %4 = load i32, i32* %main_retvar
  ret i32 %4
}
