#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long long n = 0;
  std::cin >> n;
  long long r = 0;
  long long p = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> p;
    r += p;
  }
  long long sum = (n + 1) * (n + 2) / 2;
  std::cout << sum - r;
  return 0;
}
