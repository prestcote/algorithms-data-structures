#include <iostream>
#include <vector>

int dsu_get(int v, std::vector<int>& p) {
  return (v == p[v] ? v : p[v] = dsu_get(p[v], p));
}

void dsu_unite(int a, int b, std::vector<int>& p, std::vector<std::vector<int>>& res) {
  a = dsu_get(a, p);
  b = dsu_get(b, p);
  if (rand() & 1) {
    std::swap(a, b);
  }
  if (a != b) {
    p[a] = b;
    std::vector<int> a_ = res[a];
    std::vector<int> b_ = res[b];
    res[a].insert(res[a].end(), b_.begin(), b_.end());
    res[b].insert(res[b].end(), a_.begin(), a_.end());
    std::cout << '\n';
    for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) {
        std::cout << res[i][j] << ' ';
      }
      std::cout << '\n';
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> p(n);
  std::vector<std::vector<int>> res(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    res[i] = { i + 1 };
  }
  int a = 0;
  int b = 0;

  for (int i = 0; i < n - 1; i++) {
    std::cin >> a >> b;
    a--;
    b--;
    if (dsu_get(a, p) != dsu_get(b, p)) {
      dsu_unite(a, b, p, res);
    }
  }
  //std::cout << "checkpoint 1\n";
  int r = dsu_get(0, p);
  for (int i = 0; i < res[r].size(); i++) {
    std::cout << res[r][i] << ' ';
  }
}