#include <iostream>

int main() {
  double x = 3;
  double left = 0;
  double right = 3;

  for (int i = 0; i < 50; i++) {
    double mid = (left + right) / 2;
    if (mid * mid * mid < x) {
      left = mid;
    }
    else {
      right = mid;
    }
  }

  std::cout << (left + right) / 2;
}