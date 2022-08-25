
int fib(int x) {
  if (x <= 0) {
      return 0;
  }
  if (x == 1) {
      return 1;
  }
  return fib(x-1) + fib(x-2);
}

@kernel int add(int y) {
    matrix m<int>(100, 2);
    int y1 = y + 10;
    y1 = y1 + 100;
    return y1;
}

int main() {

    return fib(5);
}

