
def cond_1(float x) bool {
  return x > 10.0
}

def foo(float x, float y) float {
  for ( ; cond_1(x); ;) {
      x = x + x
  }
  for ( ; x < 20.0; ;) {
      x = x + y
  }
  return x
}

def fib(int x) int {
  if (x <= 0) {
      return 0
  }
  if (x == 1) {
      return 1
  }
  return fib(x-1) + fib(x-2)
}

def test_else_1(float x) float {
  if (x > 10.0) { x = x + 1.0 }
  else { x = x + 2.0 }

  return x
}

def main() int {
  let z = 10.0
  let a = foo(1.0, 2.0 + foo(3.0, 4.0)) + 10.0
  return fib(9)
}

