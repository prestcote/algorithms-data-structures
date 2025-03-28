#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : (p[v] = dsu_get(p[v], p)));
}

void dsu_unite(int a, int b, std::vector<int>& p) {
  a = dsu_get(a, p);
  b = dsu_get(b, p);
  if (rand() & 1) {
    std::swap(a, b);
  }
  if (a != b) {
    p[a] = b;
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector < std::pair<int, std::pair<int, int>>> g;
  for (int i = 0; i < m; i++) {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    g.push_back({ c, {a - 1, b - 1} });

  }
  int cost = 0;
  std::vector<std::pair<int, int>> res;
  std::sort(g.begin(), g.end());
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a = g[i].second.first;
    int b = g[i].second.second;
    int l = g[i].first;
    if (dsu_get(a, p) != dsu_get(b, p)) {
      cost += l;
      res.push_back(g[i].second);
      dsu_unite(a, b, p);
    }
  }
  std::cout << cost;
}