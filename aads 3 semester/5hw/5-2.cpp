//#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

int a, b, c, d;

double f(double x) {
  return a*x*x*x + b*x*x + c*x + d;
  //return x * x - 5;
}

bool isEqual(double a, double b) {
  if (a > b) {
    return (a - b) < 1e-9;
  }
  else {
    return (b - a) < 1e-12;
  }
  
  //return std::abs(a - b) < 1e-12;
}

int main() {
  std::cin >> a >> b >> c >> d;
  double left = -1e9;
  double right = 1e9;
  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
    d = -d;
  }
  for (int i = 1; i < 150; ++i) {
    double mid = (left + right) / 2;
    if (isEqual(left, right) || isEqual(f(mid), 0)) {
      break;
    }
    if (f(left) * f(mid) > 0) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << std::setprecision(6) << (left + right) / 2;
}
