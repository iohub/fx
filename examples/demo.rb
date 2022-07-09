
def foo(float x, float y) float {
    for ( x; y;) {
        if (x > 10.0) {
            x + 1.0
        } else {
          x = x + 2
        }
    }
    for ( ; ; ) {}
    for (x; y; z;) {}
    return 10.5
}

def ErrType() float { return "ok" }

def fib(int x) int {
    if (x == 0) {
        return 1
    }
    return fib(x-1)
}

def main() int {
    float z
    z + foo(10, 12)
    return fib(9)
}

