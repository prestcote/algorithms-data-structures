#include <iostream>

int a, b, c, d;

double f(double x) {
  return a*x*x*x + b*x*x + c*x + d;
}

bool equal(double a, double b) {
  return std::abs(a - b) < 1e-9;
}

int main() {
  double left = 0;
  double right = 1e9;
  std::cin >> a >> b >> c >> d;
  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
    d = -d;
  }
  std::cout << a;
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