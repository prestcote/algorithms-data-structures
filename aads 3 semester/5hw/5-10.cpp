#include <iostream>

int main() {
  std::string half;
  std::string pos;
  int left = 0;
  int right = 0;
  std::cout << 0;
  std::cin >> pos >> half;
  std::string og_half = half;
  std::string og_pos = pos;
  if (half == "main") {
    left = 1;
    right = 36;
  }
  else {
    left = 37;
    right = 54;
  }
  while (left + 1 < right) {
    int mid = (left + right);
    if (og_half == "main") {
      std::cout << mid;
      std::cin >> pos >> half;
    }

  }
}