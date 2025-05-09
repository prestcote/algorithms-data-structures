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
  double d1 = scalar(ray, point);
  if (d1 <= 0) {
    return dist(p, n1);
  }
  double d2 = scalar(ray, ray);
  if (d2 <= d1) {
    return dist(p, n2);
  }
  double c = cross(ray, point);
  double ans = std::abs(c) / dist(n1, n2);
  return ans;
}

int main() {
  Point p;
  Point n1;
  Point n2;
  std::cin >> p >> n1 >> n2;
  double ans = dist(p, n1, n2);
  std::cout << std::fixed << std::setprecision(6) << ans;
  return 0;
}