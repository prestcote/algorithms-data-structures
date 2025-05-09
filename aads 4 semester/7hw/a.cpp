#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
  double x = 0;
  double y = 0;
};

struct Vector {
  double x = 0;
  double y = 0;
  double len = 0;
  Vector(double x_, double y_) : x(x_), y(y_) {
    len = std::sqrt(x_ * x_ + y_ * y_);
  }
};

struct Line {
  double a = 0;
  double b = 0;
  double c = 0;
  Line(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
};

int main() {
  Point x;
  Point y;
  Point z;
  std::cin >> x.x >> x.y >> y.x >> y.y >> z.x >> z.y;

  Vector xy(y.x - x.x, y.y - x.y);
  Vector xz(z.x - x.x, z.y - x.y);

  Vector xyn(xy.x / xy.len, xy.y / xy.len);
  Vector xzn(xz.x / xz.len, xz.y / xz.len);

  Vector b(xyn.x + xzn.x, xyn.y + xzn.y);
  Line lb(-b.y, b.x, b.y * x.x - b.x * x.y);
  
  std::cout << std::fixed << std::setprecision(6);
  std::cout << lb.a << ' ' << lb.b << ' ' << lb.c;

  return 0;
}