
int fib(int x) {
  if (x <= 0) {
      return 0;
  }
  if (x == 1) {
      return 1;
  }
  int y;
  y = x - 10;
  return fib(x-1) + fib(x-2);
}

int main() {

    return fib(5);
}

