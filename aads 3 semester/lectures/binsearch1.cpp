#include <cstdint>
#include <iostream>
#include <cmath>

double f(double x) {
  return x * x - 5;
}

bool isEqual(double a, double b) {
  return std::abs(a - b) < 1e-9;
}

int main() {
  double left = 0;
  double right = 1e9;
  for (int i = 1; i < 50; ++i) {
    double mid = (left + right) / 2;
    if (isEqual(left, right) || isEqual(f(mid), 0)) break;
    if (f(left) * f(mid) > 0) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << (left + right) / 2;
}
