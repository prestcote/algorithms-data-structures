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

double cross(Point& a, Point& b, Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool belong(Point& n1, Point& n2, Point& m) {
  return m.x >= std::min(n1.x, n2.x) && m.x <= std::max(n1.x, n2.x) &&
    m.y >= std::min(n1.y, n2.y) && m.y <= std::max(n1.y, n2.y) && cross(n1, n2, m) == 0;
}

bool solve(Point point, std::vector<Point>& p) {
  int ans = 0;
  Point a;
  Point b;
  double c = 0;
  for (int i = 0; i < p.size(); ++i) {
    a = p[i];
    b = p[(i + 1) % p.size()];
    if (belong(a, b, point)) {
      return true;
    }
    if (a.y > b.y) {
      std::swap(a, b);
    }
    if (point.y > a.y && point.y <= b.y && b.y != a.y) {
      c = cross(a, b, point);
      if (c > 0) {
        ans += 1;
      }
    }
  }
  return ans % 2 == 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  Point point;
  std::cin >> n >> point;
  std::vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  if (solve(point, p)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
  return 0;
}