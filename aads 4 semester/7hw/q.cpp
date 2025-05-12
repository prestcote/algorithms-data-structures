#include <iostream>
#include <vector>
#include <iomanip>
#include <tuple>
#include <cmath>

struct Point {
  double x = 0;
  double y = 0;
  explicit Point() = default;
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
  }
  Point operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
  }
  friend double operator*(const Point& lhs, const  Point& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }
  friend Point operator*(const Point& lhs, const double rhs) {
    return Point(lhs.x * rhs, lhs.y * rhs);
  }
  friend Point operator*(const double lhs, const Point& rhs) {
    return Point(lhs * rhs.x, lhs * rhs.y);
  }
  friend double operator^(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
  }
  friend std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend std::istream& operator>>(std::istream& is, std::vector<Point>& points) {
    for (auto& p : points) {
      is >> p.x >> p.y;
    }
    return is;
  }
  bool operator==(const Point& other) const {
    return std::tie(x, y) == std::tie(other.x, other.y);
  }
  double dist() {
    return std::sqrt((x * x) + (y * y));
  }
};

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<Point> points(n);
  std::cin >> points;
  Point p0 = points[0];
  for (const auto& p : points) {
    if (p.y < p0.y) {
      p0 = p;
    }
    else if (p.y == p0.y && p.x < p0.x) {
      p0 = p;
    }
  }
  std::vector<Point> ans;
  ans.push_back(p0);
  while (true) {
    Point t = points[0];
    if (t == p0) {
      t = points[1];
    }
    for (const auto& p : points) {
      if (((p0 - p) ^ (p0 - t)) > 0) {
        t = p;
      }
    }
    p0 = t;
    ans.push_back(p0);
    if (ans[0] == ans.back()) {
      break;
    }
  }
  double s1 = 0, s2 = 0;
  for (size_t i = 0; i < ans.size() - 1; ++i) {
    s1 += (ans[i + 1] - ans[i]).dist();
    s2 += (ans[i] ^ ans[i + 1]);
  }
  std::cout << std::fixed << std::setprecision(8) << s1 << "\n";
  std::cout << std::fixed << std::setprecision(8) << std::abs(s2 / 2);
  return 0;
}
