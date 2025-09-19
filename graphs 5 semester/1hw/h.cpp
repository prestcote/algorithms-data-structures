#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  int a = 0;
  int b = 0;
  int num = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> num;
    a ^= num & (~b);
    b ^= num & (~a);
  }
  if (a != 0) {
    std::cout << a << ' ' << 1;
  }
  else {
    std::cout << b << ' ' << 2;
  }
}