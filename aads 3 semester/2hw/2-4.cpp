#include <iostream>
#include <vector>

int main() {
  std::vector <long long> fib(10001);
  fib[0] = 1;
  fib[1] = 1;
  for (long long i = 2; i < fib.size(); i++) {
    fib[i] = (fib[i - 2] + fib[i - 1]) % (1000000 + 3);
  }
  long long n = 0;
  std::cin >> n;
  long long k = fib[n];
  std::cout << k;
}