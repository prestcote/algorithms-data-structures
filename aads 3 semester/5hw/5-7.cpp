#include <iostream>
#include <vector>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  std::vector<int> lens(n);
  for (auto& v : lens) {
    std::cin >> v;
  }
  long long left = 0;
  long long right = 1000000000;
  while (left + 1 < right) {
    long long mid = (left + right) / 2;
    long long count = 0;
    for (auto& v : lens) {
      count += v / mid;
    }
    if (count >= k) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << left;
  return 0;
}