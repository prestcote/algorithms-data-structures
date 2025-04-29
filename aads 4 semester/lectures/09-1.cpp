#include <iostream>
#include <vector>
#include <functional>

class Graph {
private:
  std::vector<std::vector<int>> g;
  size_t ln = 1;
  std::vector<std::vector<int>> dp;
  std::vector<int> h;
public:
  size_t size() {
    return g.size();
  }
  explicit Graph() = default;
  Graph(size_t size, std::vector<std::vector<int>>& vec) {
    g = vec;
    //g.resize(size);
  }
  std::vector<int>& operator[](size_t index) {
    return g[index];
  }
  void build(int root) {
    while ((1 << ln) < size()) {
      ++ln;
    }
    ln += 2;
    h.resize(size());
    dp.assign(size(), std::vector<int>(ln, root));
    std::vector<int> used(size());
    std::function<void(int, int)> dfs = [&](int v, int p) {
      used[v] = 1;
      dp[v][0] = p;
      h[v] = h[p] + 1;
      for (auto to : g[v]) {
        if (!used[to]) {
          dfs(to, v);
        }
      }
      };
    dfs(root, root);
    for (int v = 0; v < size(); ++v) {
      for (int k = 1; k < ln; ++k) {
        dp[v][k] = dp[dp[v][k - 1]][k - 1];
      }
    }
  }

  int lca(int u, int v) {
    if (h[u] > h[v]) {
      std::swap(u, v);
    }
    for (int k = ln - 1; k >= 0; --k) {
      int p = dp[v][k];
      if (h[p] >= h[u]) {
        v = p;
      }
    }
    if (u == v) {
      return v;
    }
    for (int k = ln - 1; k >= 0; --k) {
      if (dp[v][k] != dp[u][k]) {
        v = dp[v][k];
        u = dp[u][k];
      }
    }
    return dp[v][0];
  }
};

int main() {
  std::vector<std::vector<int>> g;

  return 0;
}
