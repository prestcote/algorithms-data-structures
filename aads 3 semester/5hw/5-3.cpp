#include <iostream>
#include <algorithm>

int main() {
  long long w;
  long long h;
  long long n;
  long long l = 1;
  std::cin >> w >> h >> n;
  long long r = 1e8;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if ((n / w) * (n / h) < mid) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  std::cout << r;
}