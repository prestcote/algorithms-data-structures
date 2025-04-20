#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void bridge(std::vector<std::vector<int>>& g, std::vector<int>& tin, std::vector<int>& fup, int& timer,
  std::vector<int>& used, std::set<int>& ans, int v, int p = -1) {
  used[v] = 1;
  tin[v] = (fup[v] = timer++);
  int children = 0;
  for (auto& i : g[v]) {
    if (i == p) {
      continue;
    }
    if (!used[i]) {
      bridge(g, tin, fup, timer, used, ans, i, v);
      fup[v] = std::min(fup[v], fup[i]);
      children++;
      if (fup[i] >= tin[v] && p != -1) {
        ans.insert(v);
      }
    }
    else {
      fup[v] = std::min(fup[v], tin[i]);
    }
  }
  if (p == -1 && children > 1) {
    ans.insert(v);
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
  std::vector<int> tin(n, 0);
  std::vector<int> fup(n, 0);
  int timer = 0;
  std::vector<int> used(n, 0);
  std::set<int> ans;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      bridge(g, tin, fup, timer, used, ans, i);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto i : ans) {
    std::cout << i + 1 << ' ';
  }
  return 0;
}