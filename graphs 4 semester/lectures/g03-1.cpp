#include <iostream>
#include <vector>
#include <queue>

//c in 3hw

void dfs(std::vector<std::vector<int>>& g, std::vector<int>& used, std::vector<std::vector<int>>& ans, int v) {
  used[v] = 1;
  ans[ans.size() - 1].push_back(v + 1);
  for (int u : g[v]) {
    if (used[u] == 0) {
      dfs(g, used, ans, u);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  std::vector<std::vector<int>> g(n);
  int s = 0;
  int f = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> s >> f;
    g[s - 1].push_back(f - 1);
    g[f - 1].push_back(s - 1);
  }
  int count = 0;
  std::vector<int> used(n, 0);
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      ans.emplace_back();
      dfs(g, used, ans, i);
    }
  }

  std::cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i].size() << '\n';
    //std::cout << '\n' << "HEYOO" << '\n';
    for (int j = 0; j < ans[i].size(); j++) {
      std::cout << ans[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}