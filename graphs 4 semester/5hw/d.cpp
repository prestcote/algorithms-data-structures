#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>

struct edge {
  int x, y, g, h;
  bool operator>(const edge& other) const {
    return (g + h) > (other.g + other.h);
  }
};

int heuristic(int x, int y, int n) {
  return std::max(std::abs(n - 1 - x), std::abs(n - 1 - y));
}

int a_star(int n, std::unordered_set<long long>& blocked) {
  std::priority_queue<edge, std::vector<edge>, std::greater<edge>> q;
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e9));
  q.push({ 0, 0, 0, heuristic(0, 0, n) });
  dist[0][0] = 0;

  while (!q.empty()) {
    int x = q.top().x;
    int y = q.top().y;
    int g = q.top().g;
    int h = q.top().h;
    q.pop();

    if (x == n - 1 && y == n - 1) {
      return g;
    }
    std::vector<std::pair<int, int>> moves = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    for (int i = 0; i < 8; ++i) {

      int xi = x + moves[i].first;
      int yi = y + moves[i].second;
      long long h = xi * n + yi;
      if (xi >= 0 && xi < n && yi >= 0 && yi < n && !blocked.count(h)) {
        int new_g = g + 1;
        if (new_g < dist[xi][yi]) {
          dist[xi][yi] = new_g;
          q.push({ xi, yi, new_g, heuristic(xi, yi, n) });
        }
      }
    }
  }
  return -1;
}

int main() {
  int n, k, r;
  std::unordered_set<long long> banned;
  std::cin >> n >> k >> r;
  int xi, yi;
  for (int i = 0; i < k; ++i) {
    std::cin >> xi >> yi;
    for (int x = -r; x <= r; ++x) {
      for (int y = -r; y <= r; ++y) {
        int x_ = xi + x;
        int y_ = yi + y;
        if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n && 
          ((x_ - xi)* (x_ - xi) + (y_ - yi) * (y_ - yi) <= r * r)) {
          long long h = x_ * n + y_;
          banned.insert(h);
        }
      }
    }
  }
  std::cout << a_star(n, banned) << std::endl;
  return 0;
}
