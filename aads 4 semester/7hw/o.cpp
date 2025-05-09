#include <iostream>
#include <vector>
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

long long cross(Point& a, Point& b, Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool solve(std::vector<Point>& p) {
  if (p.size() < 3) return false;
  long long in = 0;
  bool fp = false;
  bool fn = false;
  for (int i = 0; i < p.size(); i++) {
    Point& a = p[i];
    Point& b = p[(i + 1) % p.size()];
    Point& c = p[(i + 2) % p.size()];
    long long cr = cross(a, b, c);
    if (cr > 0) {
      fp = true;
    }
    else if (cr < 0) {
      fn = true;
    }
    if (fp && fn) {
      return false;
    }
  }
  if (!fp && !fn) {
    return false;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  if (solve(p)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO\n";
  }
  return 0;
}