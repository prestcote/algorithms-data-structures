#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
  double x = 0;
  double y = 0;
  double z = 0;
  Point() = default;
  Point(double x_, double y_) : x(x_), y(y_) {}
  Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
};

struct Plane {
  double a = 0;
  double b = 0;
  double c = 0;
  Plane() = default;
  Plane(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
};

int main() {
  Point d;
  Plane v;
  std::cin >> d.x >> d.y >> v.a >> v.b >> v.c;
  double ans = std::abs(v.a * d.x + v.b * d.y + v.c) / std::sqrt(v.a * v.a + v.b * v.b);
  std::cout << std::fixed << std::setprecision(6) << ans;
  return 0;

}

