#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <cmath>


double f(double x) {
  return 6 * x * x * x * x + 7 * x * x * x - 8 * x * x - 9 * x + 1;
}

double polinom(double Xi, std::vector<double> x, std::vector<double>y) {
  double def = 0;
  for (int i = 0; i < 8; i++) {
    double p = 1;
    for (int j = 0; j < 8; j++) {
      if (i != j) {
        p *= (Xi - x[j]) / (x[i] - x[j]);
      }
    }
    def += p*y[i];
  }
  return def;
}

int main() {
  setlocale(LC_ALL, "Russian");

  std::vector<double> x = { -2.046, -2, -1.17084, -0.43703, 0.10266, 0.73287, 1.941, 2 };
  std::vector<double>y(8);
  
  for (int i = 0; i < 8; i++) {
    y[i] = f(x[i]);
  }

  double x1 = -1.487;
  double x2 = 1.047;
  double x3 = 1.2215;

  std::cout << std::setprecision(20);
  std::cout << "\nx1 = " << x1 << " f(x1) = " << f(x1) << " g(x1) = " << polinom(x1, x, y) << "|f(x1) - g(x1) = " << f(x1) - polinom(x1, x, y) << '\n';
  std::cout << "x2 = " << x2 << " f(x2) = " << f(x2) << " g(x2) = " << polinom(x2, x, y) << "|f(x2) - g(x2) = " << f(x2) - polinom(x2, x, y) << '\n';
  std::cout << "x3 = " << x3 << " f(x3) = " << f(x3) << " g(x3) = " << polinom(x3, x, y) << "|f(x3) - g(x3) = " << f(x3) - polinom(x3, x, y) << '\n';

  return 0;
}


