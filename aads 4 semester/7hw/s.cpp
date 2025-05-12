#include <iostream>
#include <vector>
#include <iomanip>
#include <tuple>
#include <cmath>
#include <algorithm>

double PI = 3.14159265358979323846;

struct Point {
  double x = 0;
  double y = 0;
  explicit Point() = default;
  Point(double x, double y) : x(x), y(y) {}
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
  bool operator<(const Point& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};

double dist(Point n, Point m) {
  return std::sqrt((n.x - m.x) * (n.x - m.x) + (n.y - m.y) * (n.y - m.y));
}
double cross(Point& a, Point& b, Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

std::vector<Point> convex(std::vector<Point> points) {
  if (points.size() <= 1) return points;
  std::sort(points.begin(), points.end());
  points.erase(std::unique(points.begin(), points.end()), points.end());
  std::vector<Point> vec;

  for (int i = 0; i < points.size(); i++) {
    while (vec.size() >= 2 && cross(vec[vec.size() - 2], vec[vec.size() - 1], points[i]) <= 0)
      vec.pop_back();
    vec.push_back(points[i]);
  }
  int down = vec.size();
  for (int i = points.size() - 2; i >= 0; i--) {
    while (vec.size() > down && cross(vec[vec.size() - 2], vec[vec.size() - 1], points[i]) <= 0)
      vec.pop_back();
    vec.push_back(points[i]);
  }
  if (vec.size() > 1) vec.pop_back();
  return vec;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  int l = 0;
  std::cin >> n >> l;
  std::vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    std::cin >> points[i];
  }
  std::vector<Point> hull = convex(points);
  double ans = 0;
  for (int i = 0; i < hull.size() - 1; i++) {
    ans += dist(hull[i], hull[i + 1]);
  }
  ans += dist(hull[hull.size() - 1], hull[0]);
  ans += l * PI * 2;
  std::cout << std::fixed << std::setprecision(15) << ans;
  return 0;
}
