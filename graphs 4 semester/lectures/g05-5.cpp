#include <iostream>
#include <vector>
#include <random>
#include <tuple>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v], p));
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
  int k = 0;
  int m = 0;
  std::cin >> n >> m >> k;
  std::vector<int> p(n);
  std::vector<std::tuple<std::string, int, int>> op;
  std::vector<std::vector<int>> g;

  for (int i = 0; i < m; i++) {

  }
}