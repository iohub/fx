
def DemoFor(float x, float y) float {
    for ( x; y;) {
        x - y
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
    int z
    10 + 2.5
    z + DemoFor(10, 12)
    return fib(8)
}

