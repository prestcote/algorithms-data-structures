#include <iostream>
#include <vector>

int main() {
  std::vector <long long> fib(1001);
  fib[0] = 1;
  fib[1] = 1;
  for (long i = 2; i < fib.size(); i++) {
    fib[i] = (fib[i - 2] + fib[i - 1])%10;
  }
  long long n = 0;
  std::cin >> n;
  long long k = fib[n];
  std::cout << k;
}