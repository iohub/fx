
int fib(int x) {
  if (x <= 0) {
      return 0;
  }
  if (x == 1) {
      return 1;
  }
  return fib(x-1) + fib(x-2);
}

int add(int x) {
    int val = x + 10;
    val = val + 100;
    return val;
}

int main() {

    return fib(5);
}

