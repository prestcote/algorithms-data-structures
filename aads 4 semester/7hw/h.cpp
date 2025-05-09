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

std::istream& operator>>(std::istream& is, Point& p) {
  is >> p.x >> p.y;
  return is;
}

std::ostream& operator<< (std::ostream& os, Point& p) {
  os << std::fixed << std::setprecision(6) << p.x << ' ' << p.y;
  return os;
}

std::istream& operator>> (std::istream& is, Line& l) {
  is >> l.a >> l.b >> l.c;
  return is;
}

std::ostream& operator<< (std::ostream& os, Line& l) {
  os << std::fixed << std::setprecision(6) << l.a << ' ' << l.b << l.c;
  return os;
}

double cross(Point& a, Point& b, Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool belong(Point& n1, Point& n2, Point& m) {
  return m.x >= std::min(n1.x, n2.x) && m.x <= std::max(n1.x, n2.x) &&
    m.y >= std::min(n1.y, n2.y) && m.y <= std::max(n1.y, n2.y);
}

bool solve(Point& n1, Point& n2, Point& m1, Point& m2) {
  double a1 = cross(n1, n2, m1);
  double a2 = cross(n1, n2, m2);
  double a3 = cross(m1, m2, n1);
  double a4 = cross(m1, m2, n2);

  if (((a1 > 0 && a2 < 0) || (a1 < 0 && a2 > 0)) && ((a3 > 0 && a4 < 0) || (a3 < 0 && a4 > 0))) {
    return true;
  }

  if ((a1 == 0 && belong(n1, n2, m1)) || (a2 == 0 && belong(n1, n2, m2)) || (a3 == 0 && belong(m1, m2, n1)) || (a4 == 0 && belong(m1, m2, n2))) {
    return true;
  }
  return false;
}
int main() {
  Point n1;
  Point n2;
  Point m1;
  Point m2;
  std::cin >> n1 >> n2 >> m1 >> m2;
  if (solve(n1, n2, m1, m2)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
  return 0;
}