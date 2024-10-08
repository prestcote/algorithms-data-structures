#include <iostream>
#include <iomanip>
#include <cmath>
//#include <cstdlib>

double f(double x) {
  return x * x * x - 3 * x * x + 3 * x - 1;
}

bool equal(double a, double b) {
  return std::abs(a - b) < 0.0000000001;
}

int main() {
  double left = -1e9;
  double right = 1e9;
  for (int i = 0; i < 100; i++) {
    double mid = (left + right) / 2;
    if (equal(left, right) || equal(f(mid), 0)) {
      break;
    }
    if (f(left) * f(mid) > 0) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << std::setprecision(9) << (left + right) / 2;
}