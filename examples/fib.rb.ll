; ModuleID = '../examples/fib.rb'
source_filename = "../examples/fib.rb"

define i32 @fib(i32 %x) {
entry:
  %x1 = alloca i32
  store i32 %x, i32* %x1
  %0 = load i32, i32* %x1
  %1 = icmp sle i32 %0, 0
  br i1 %1, label %then, label %ifcont

then:                                             ; preds = %entry
  ret i32 0

ifcont:                                           ; preds = %then, %entry
  %2 = load i32, i32* %x1
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %then2, label %ifcont3

then2:                                            ; preds = %ifcont
  ret i32 1

ifcont3:                                          ; preds = %then2, %ifcont
  %4 = load i32, i32* %x1
  %add = sub i32 %4, 1
  %5 = call i32 @fib(i32 %add)
  %6 = load i32, i32* %x1
  %add4 = sub i32 %6, 2
  %7 = call i32 @fib(i32 %add4)
  %add5 = add i32 %5, %7
  ret i32 %add5
}

define i32 @main() {
entry:
  %z = alloca i32
  store i32 8, i32* %z
  %0 = load i32, i32* %z
  %1 = call i32 @fib(i32 5)
  %add = add i32 %0, %1
  store i32 %add, i32* %z
  %2 = load i32, i32* %z
  %3 = call i32 @fib(i32 %2)
  ret i32 %3
}
