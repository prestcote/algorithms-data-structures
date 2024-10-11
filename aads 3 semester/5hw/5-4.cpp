#include <iostream>
#include <algorithm>

int main() {
  long long w = 0;
  long long h = 0;
  long long n = 0;
  long long left = 1;
  std::cin >> w >> h >> n;
  long long right = 1000000000;
  while (left + 1 < right) {
    long long mid = (left + right) / 2;
    if (((mid / w) * (mid / h)) < n) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << right;
  return 0;
}