#include <iostream>
#include <vector>
#include <set>

void prim(std::vector<std::pair<int, int>>& min_e, std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& used) {
  min_e[0].second = 0;
  int weight = 0;
  int n = g.size();
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < n; j++) {
      if (!used[j] && (v == -1 || min_e[j].second < min_e[v].second)) {
        v = j;
      }
    }
    used[v] = 1;
    if (min_e[v].first != -1) {
      weight += min_e[v].second;
    }
    for (int to = 0; to < n; to++) {

    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector < std::vector<std::pair<int, int>>> g(n);
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    g[a - 1].push_back({ b - 1, c });
    g[b - 1].push_back({ a - 1, c });
  }
  std::vector<std::pair<int, int>> min_e(n, { -1, 1e9 });
  std::vector<int> used(n, 0);
  //prim()
}