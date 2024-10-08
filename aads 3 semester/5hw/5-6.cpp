#include <iostream>

int main() {
  long long a = 0;
  long long b = 0;
  long long k = 0;
  long long m = 0;
  long long x = 0;
  std::cin >> a >> k >> b >> m >> x;

  long long left = 0;
  long long right = 1e18;
  while (left + 1 < right) {
    long long mid = (right + left) / 2;
    if ((mid - mid / k) * a + (mid - mid / m) * b >= x) {
      right = mid;
    }
    else {
      left = mid;
    }
    std::cout << "it " << left << ' ' << right << ' ' << mid << std::endl;
  }
  std::cout << left;
  return 0;
}