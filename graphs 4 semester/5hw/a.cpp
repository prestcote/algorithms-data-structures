#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void dij(std::vector<std::vector<std::pair<long long, long long>>>& g, std::vector<long long>& d, std::vector<long long>& p, long long s) {
  d[s] = 0;
  std::priority_queue<std::pair<long long, long long>> q;
  q.push({ 0, s });
  while (!q.empty()) {
    long long v = q.top().second;
    long long cur = -q.top().first;
    q.pop();
    if (cur > d[v]) {
      continue;
    }
    for (size_t j = 0; j < g[v].size(); j++) {
      long long to = g[v][j].first;

      long long len = g[v][j].second;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
        q.push({ -d[to], to });
      }
    }

  }
}

int main() {
  long long n = 0;
  long long m = 0;
  long long s = 0;
  long long f = 0;
  std::cin >> n >> m >> s >> f;
  std::vector < std::vector < std::pair<long long, long long>>> g(n);
  long long a, b, c;
  for (long long i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    g[a - 1].push_back({ b - 1, c });
    g[b - 1].push_back({ a - 1, c });
  }
  s--;
  f--;
  //std::cout << "CHECKPOINT 1 ";
  std::vector<long long> p(n, -1);
  std::vector<long long> d(n, 1e9);
  dij(g, d, p, s);
  //std::cout << "CHECKPOINT 2";
  if (d[f] == 1e9) {
    std::cout << "-1";
    return 0;
  }
  else {
    std::cout << d[f]  << '\n';
    std::vector<long long> path;
    for (long long i = f; i != -1; i = p[i]) {
      path.push_back(i+1);
    }
    std::reverse(path.begin(), path.end());
    for (long long i = 0; i < path.size(); i++) {
      std::cout << path[i] << ' ';
    }
  }
}