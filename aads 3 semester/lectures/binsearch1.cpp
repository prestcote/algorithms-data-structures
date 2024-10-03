#include <iostream>

double f(double x) {
  return x * x - 5;
}

bool equal(double a, double b) {
  return abs(a - b) < 1e-9;
}

int main() {
  double left = 0;
  double right = 1e9;
  for (int i = 0; i < 50; i++) {
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
  std::cout << (left + right) / 2;
}