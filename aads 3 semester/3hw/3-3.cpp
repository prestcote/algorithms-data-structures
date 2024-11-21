#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <cmath>

double PI = 3.1415926535; 

double f(double x) { //выбранная функция
  return std::sin(x);
}

double g(double b) { //интеграл от функции на отрезке [0, b]
  return -(std::cos(b) - 1);
}

double boole_method(double h) { //формула буля
  double x0 = 0;
  double x1 = x0 + h;
  double x2 = x0 + 2*h;
  double x3 = x0 + 3*h;
  double x4 = x0 + 4*h;
  return (2 * h * (7 * f(x0) + 32 * f(x1) + 12 * f(x2) + 32 * f(x3) + 7 * f(x4))) / 45 - ((-f(PI / 3)) * 8 * std::pow(h, 7)) / 945;
}

int main() {
  setlocale(LC_ALL, "Russian");
  std::cout << std::setprecision(10);
  for (double x = 4; x < 12; x += 2) {
    double h = PI / x;
    double I = g(4 * h);
    double I_tilda = boole_method(h);
    std::cout << "[a, b] = [" << 0 << ", 4PI/" << x << "] h = PI / " << x << " I = " << I << " I~= " << I_tilda << " | I - I~| = " << I - I_tilda <<std::endl;
  }

  return 0;
}


