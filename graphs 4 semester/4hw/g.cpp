#include <iostream>
#include <queue>
#include <algorithm>

int dij(std::vector<std::vector<std::vector<int>>>& g, int s, int f, int ans) {
  std::vector<int> d(g.size(), 1e9);
  d[s] = ans;
  std::priority_queue<std::pair<int, int>> q;
  q.push({ -ans, s });
  while (!q.empty()) {
    int v = q.top().second;
    int cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v]) {
      continue;
    }
    for (size_t j = 0; j < g[v].size(); j++) {
      int to = g[v][j][0];
      int len = g[v][j][2]; // ןנמגונטעü דנאפ 
      //int wait = g[v][j][1];
      //int wait = d[v] % g[v][j][3];
      int wait = (g[v][j][1] - (cur_d % g[v][j][1])) % g[v][j][1];
      if (d[v] + len + wait < d[to]) {
        d[to] = d[v] + len + wait;
        q.push({ -d[to], to });
      }
    }
  }
  if (d[f] == 1e9) {
    return -1;
  }
  else {
    return d[f];
  }
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int a, b, c, d;
  std::vector<std::vector<std::vector<int>>> g(n);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> a >> b >> c >> d;
    g[a - 1].push_back({ b - 1, c, d });

  }
  int m = 0;
  std::cin >> m;
  int one = 0;
  std::cin >> one;
  int two;
  for (int i = 1; i < m; i++) {
    std::cin >> two;
    //std::cout << "CHECK " << i << '\n';
    ans = dij(g, one-1, two-1, ans);
    //std::cout << "CHECK " << i+1 << '\n';
    if (ans == -1) {
      std::cout << "-1\n";
      return 0;
    }
    one = two;
  }
  std::cout << ans << '\n';
  return 0;
}