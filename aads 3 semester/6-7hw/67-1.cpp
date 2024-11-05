#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> fib(n+1);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < fib.size(); i++) {
    fib[i] = ((fib[i - 1] % 10) + (fib[i - 2] % 10)) % 10;
  }
  std::cout << fib[n];
}