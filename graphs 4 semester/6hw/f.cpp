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
  std::vector<std::vector<std::pair<int, int>>> g1(n);
  for (int i = 0; i < m; i++) {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    g.push_back({ c, {a - 1, b - 1} });
    g1[a - 1].push_back({ b - 1, c });
    g1[b - 1].push_back({ a - 1, c });
  }
  int cost = 0;
  std::vector<std::pair<int, std::pair<int, int>>> res;
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
      res.push_back({ l, g[i].second });
      dsu_unite(a, b, p);
    }
  }
  std::cout << cost << ' ';

  int cost2 = 1e9;
  for (int i = 0; i < res.size(); i++) {
    std::vector<int> p1(n);
    for (int j = 0; j < n; j++) {
      p1[j] = j;
    }

    int cur = 0;
    int count = 0;
    for (auto e : g) {
      if (e.second != res[i].second || e.first != res[i].first) {
        if (dsu_get(e.second.first, p1) != dsu_get(e.second.second, p1)) {
          cur += e.first;
          dsu_unite(e.second.first, e.second.second, p1);
          count += 1;
        }
      }
    }
    if (count == n - 1) {
      cost2 = std::min(cost2, cur);
    }
  }
  std::cout << cost2;
}