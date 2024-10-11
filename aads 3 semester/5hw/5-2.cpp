//#include <cstdlib>
#include <iostream>
#include <cmath>

int a, b, c, d;
double epsilon = 1e-8;

double f(double x) {
  return a*x*x*x + b*x*x + c*x + d;
  //return x * x - 5;
}

int main() {
  std::cin >> a >> b >> c >> d;
  double left = -2000;
  double right = 2000;
  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
    d = -d;
  }
  double mid = right;
  while (left+epsilon < right) {
    mid = (left + right) / 2;
    if (f(left) * f(mid) > 0) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  std::cout << mid;
}
