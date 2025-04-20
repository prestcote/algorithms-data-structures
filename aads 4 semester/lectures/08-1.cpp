#include <iostream>

struct Point {
  double x = 0;
  double y = 0;
  explicit Point() = default;
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point& other) const {
    return { x + other.x, y + other.y };
  }
  Point operator-(const Point& other) const {
    return Point(x + other.x, y + other.y);
  }

};

int main() {
  Point one(0, 0);
  Point two(1, 1);
  one = one + Point(1, 1);
  Point three = one + two;
  std::cout << three.x << ' ' << three.y;
}