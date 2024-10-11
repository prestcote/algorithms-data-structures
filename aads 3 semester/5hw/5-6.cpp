#include <iostream>
#include <cstdint>

int main() {
  unsigned long int a = 0;
  unsigned long int b = 0;
  unsigned long int k = 0;
  unsigned long int m = 0;
  unsigned long int x = 0;
  std::cin >> a >> k >> b >> m >> x;

  //__int128_t left = 0;
  unsigned long int left = 0;
  //__int128_t right = 1e18 + 1;
  unsigned long int right = 1e18 + 1;
  while (left + 1 < right) {
    //__int128_t mid = (right + left) / 2;
    unsigned long int mid = (right + left) / 2;
    if ((mid - mid / k) * a + (mid - mid / m) * b >= x) {
      right = mid;
    }
    else {
      left = mid;
    }
    //std::cout << "it " << left << ' ' << right << ' ' << mid << std::endl;
  }
  std::cout << (long long)right;
  return 0;
}