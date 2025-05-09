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

struct Line {
  double a = 0;
  double b = 0;
  double c = 0;
  Line() = default;
  Line(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
  Line(Point p, Point q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.x * q.y - q.x * p.y;
  }
};

int main() {
  Point d;
  Point e;
  Point f;
  std::cin >> d.x >> d.y >> e.x >> e.y >> f.x >> f.y;
  Line v(e, f);
  double ans = std::abs(v.a * d.x + v.b * d.y + v.c) / std::sqrt(v.a * v.a + v.b * v.b);
  std::cout << std::fixed << std::setprecision(6) << ans;
  return 0;

}

