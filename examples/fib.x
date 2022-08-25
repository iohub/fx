
int fib(int x) {
  if (x <= 0) {
      return 0;
  }
  if (x == 1) {
      return 1;
  }
  return fib(x-1) + fib(x-2);
}

@kernel void add(int y) {
    matrix m<int>(100, 2);
    int y1 = y + 10;
    y1 = y1 + 100;
}

@kernel void sub(int y2) {
    y2 = y2 - 100;
}

int main() {

    return fib(5);
}

