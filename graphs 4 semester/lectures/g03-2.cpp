#include <iostream>
#include <vector>

// a in 3hw

void dfs(std::vector<std::vector<int>>& g,
  std::vector<int>& used, std::vector<int>& cycle,
  std::vector<int>& ans,
  int v, bool& flag, int p = -1) {
  used[v] = 1;
  cycle.emplace_back(v);
  for (auto to : g[v]) {
    if (flag == true) {
      return;
    }
    if (used[to] == 1 && to != p) {
      int i = cycle.size() - 1;
      while (cycle[i] != to) {
        ans.emplace_back(cycle[i] + 1);
        --i;
      }
      ans.emplace_back(cycle[i] + 1);
      flag = true;
      return;
    }
    else if (used[to] == 1 && to == p) {
      continue;
    }
    else {
      dfs(g, used, cycle, ans, to, flag, v);
    }
  }
  used[v] = 2;
  cycle.erase(cycle.begin() + cycle.size() - 1, cycle.end());
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  std::vector<int> used(n, 0);
  std::vector<int> cycle;
  std::vector<int> ans;
  int v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> v;
      if (v)
        g[j].emplace_back(i);
    }
  }
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    if (used[i] == 0) {
      dfs(g, used, cycle, ans, i, flag);
      if (flag) {
        break;
      }
    }
  }
  if (flag) {
    std::cout << "YES\n" << ans.size() << '\n';
    for (int v : ans) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
  else {
    std::cout << "NO\n";
  }
}
