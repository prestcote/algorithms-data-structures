#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void dij(std::vector<std::vector<std::vector<int>>>& g, std::vector<int>& d, std::vector<int>& p, int s) {
  d[s] = 0;
  std::priority_queue<std::pair<int, int>> q;
  q.push({ 0, s });
  while (!q.empty()) {
    int v = q.top().second;
    int cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v]) {
      continue;
    }
    for (size_t j = 0; j < g[v].size(); j++) {
      if (g[v][j][0] < d[v]) {
        continue;
      }
      int to = g[v][j][2];
      if (d[to] > g[v][j][1]) {
        d[to] = g[v][j][1];
        p[to] = v;
        q.push({ -d[to], to });
      }
    }
  }

}

int main() {
  int n = 0;
  int e = 0;
  int m = 0;
  std::cin >> n >> e >> m;
  e--;
  std::vector<int> f(0, 0);
  std::vector<std::vector<std::vector<int>>> g(n);
  int k = 0;
  int cur_s = 0;
  int cur_f = 0;
  int prev_s = 0;
  int prev_f = 0;
  for (int i = 0; i < m; i++) {
    //std::cout << "hii";
    std::cin >> k;
    std::cin >> prev_s >> prev_f;
    for (int j = 1; j < k; j++) {
      std::cin >> cur_s >> cur_f;
      g[prev_s-1].push_back({ prev_f, cur_f, cur_s -1 });
      prev_s = cur_s;
      prev_f = cur_f;
    }
  }
  //std::cout << "CHECK1 ";
  std::vector<int> p(n, -1);
  std::vector<int> d(n, 1e9);
  dij(g, d, p, 0);
  //std::cout << "CHECK2 ";
  if (d[e] == 1e9) {
    std::cout << -1;
    return 0;
  }
  std::cout << d[e];
  return 0;
}