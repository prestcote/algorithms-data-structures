#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

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
  os << std::fixed << std::setprecision(6) << l.a << ' ' << l.b << ' ' << l.c;
  return os;
}


double scalar(Point& a, Point& b) {
  return a.x * b.x + a.y * b.y;
}

double cross(Point& a, Point& b) {
  return (b.x * a.y - b.y * a.x);
}

double dist(Point& a, Point& b) {
  return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(Point& p, Point& n1, Point& n2) {
  if (n1.x == n2.x && n1.y == n2.y) {
    return dist(p, n1);
  }
  Point ray(n2.x - n1.x, n2.y - n1.y);
  Point point(p.x - n1.x, p.y - n1.y);
  double d = scalar(point, ray) / scalar(ray, ray);
  if (d <= 0) {
    return dist(p, n1);
  }
  if (d >= 1) {
    return dist(p, n2);
  }
  Point d1(n1.x + d * ray.x, n1.y + d * ray.y);
  return dist(p, d1);
}

bool solve(Point& n1, Point& n2, Point& m1, Point& m2) {
  Point n1n2(n2.x - n1.x, n2.y - n1.y);
  Point n1m1(m1.x - n1.x, m1.y - n1.y);
  Point n1m2(m2.x - n1.x, m2.y - n1.y);
  Point m1m2(m2.x - m1.x, m2.y - m1.y);
  Point m1n1(n1.x - m1.x, n1.y - m1.y);
  Point m1n2(n2.x - m1.x, n2.y - m1.y);
  double a1 = cross(n1n2, n1m1);
  double a2 = cross(n1n2, n1m2);
  double a3 = cross(m1m2, m1n1);
  double a4 = cross(m1m2, m1n2);
  if (((a1 > 0 && a2 < 0) || (a1 < 0 && a2 > 0)) && ((a3 > 0 && a4 < 0) || (a3 < 0 && a4 > 0))) {
    return true;
  }
  if ((std::abs(a1) <= 1e-9 && dist(n1, m1, m2) < 1e-9) ||
    (std::abs(a2) <= 1e-9 && dist(n2, m1, m2) < 1e-9) ||
    (std::abs(a3) <= 1e-9 && dist(m1, n1, n2) < 1e-9) ||
    (std::abs(a4) <= 1e-9 && dist(m2, n1, n2) < 1e-9)) {
    return true;
  }
  return false;
}

double dist(Point& n1, Point& n2, Point& m1, Point& m2) {
  if (solve(n1, n2, m1, m2)) {
    return 0;
  }
  double a1 = dist(n1, m1, m2);
  double a2 = dist(n2, m1, m2);
  double a3 = dist(m1, n1, n2);
  double a4 = dist(m2, n1, n2);
  return std::min({ a1, a2, a3, a4 });
}

int main() {
  Point n1;
  Point n2;
  Point m1;
  Point m2;
  std::cin >> n1 >> n2 >> m1 >> m2;
  double ans = dist(n1, n2, m1, m2);
  std::cout << std::fixed << std::setprecision(20) << ans;
  return 0;
}