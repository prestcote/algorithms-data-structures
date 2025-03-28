#include <iostream>
#include <vector>

struct edge {
  int s, f, cost;
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<edge> e;
  int count = 0;
  int INF = 1000000;

  for (int i = 2; i <= n; ++i) {
    e.push_back({ i - 1, i, i-2 });
    count += 1;
  }
  int weight = INF - 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 2; j <= n; ++j) {
      e.push_back({ i, j, weight });
      weight -= 1;
      count += 1;
      if (count == m) {
        break;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    std::cout << e[i].s << ' ' << e[i].f << ' ' << e[i].cost << '\n';
  }

  return 0;
}

