#include <iostream>
#include <vector>
#include <iomanip>

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
};

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<Point> points(n);
  std::cin >> points;
  double s = points.back() ^ points[0];
  for (size_t i = 0; i < n - 1; ++i) {
    s += points[i] ^ points[i + 1];
  }
  std::cout << std::fixed << std::setprecision(7) << std::abs(s / 2);
  return 0;
}
