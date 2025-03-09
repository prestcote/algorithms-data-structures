#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int v, int color, std::vector<std::vector<int>>& g, std::vector<int>& used, bool& cor) {
  for (int to : g[v]) {
    if (used[to] == 0) {
      int m = 3 - color;
      used[to] = m;
      dfs(to, m, g, used, cor);
    }
    else if (used[to] == color) {
      cor = false;
      return;
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  int a = 0;
  int b = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  std::vector<int> used(n, 0);
  bool cor = true;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      used[i] = 1;
      dfs(i, 1, g, used, cor);
    }
    if (cor == false) {
      break;
    }
  }
  if (cor == true) {
    std::cout << "YES\n" << std::count(used.begin(), used.end(), 2) << '\n';
    for (int i = 0; i < n; i++) {
      //std::cout << used[i] << ' ';
      if (used[i] == 2) {
        std::cout << i + 1 << ' ';
      }
    }
  }
  else {
    std::cout << "NO\n";
  }
}