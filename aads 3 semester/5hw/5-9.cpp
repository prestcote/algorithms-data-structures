#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  std::vector<long long> vec(n);
  long long x = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    vec[i] = x;
  }
  std::sort(vec.begin(), vec.end());
  long long left = 0;
  long long right = 1e18 / k + 1;
  while (left < right) {
    long long mid = (left + right) / 2;
    long long count = 0;
    long long len = -1e9-10;
    for (int i = 0; i < n; i++) {
      if (len < vec[i]) {
        len = vec[i] + mid;
        count += 1;
      }
    }
    if (count > k) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  std::cout << left;
  return 0;
}