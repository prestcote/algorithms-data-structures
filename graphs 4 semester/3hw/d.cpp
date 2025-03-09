#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int v, std::vector<int>& used, std::vector<std::vector<int>>& g, std::vector<int>& ans) {
  used[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    if (used[g[v][i]] == 0) {
      used[g[v][i]] = 1;
      dfs(g[v][i], used, g, ans);
    }
    else if (used[g[v][i]] == 1) {
      return;
    }
  }
  used[v] = 2;
  ans.push_back(v);
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  std::vector<int>used(n, 0);
  int a = 0;
  int b = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      dfs(i, used, g, ans);
    }
  }
  if (ans.size() == n) {
    std::cout << "Yes\n";
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << ' ';
    }
  }
  else {
    std::cout << "No\n";
  }
}