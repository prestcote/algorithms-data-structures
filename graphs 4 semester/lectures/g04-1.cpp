#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
  int n = 0;
  int s = 0;
  int f = 0;
  std::cin >> n >> s >> f;
  std::vector<std::vector<std::pair<int, int>>> g(n);
  int a = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a;
      if (i != j && a != -1) {
        g[i].push_back({ j, a });
      }
    }
  }
  
  std::vector<int> d(n, 1e9);
  std::vector<int> p(n, 1e9);
  d[s] = 0;
  std::set<std::pair<int, int>> q;
  q.insert(std::make_pair(d[s], s));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (size_t j = 0; j < g[v].size(); j++) {
      int to = g[v][j].first;
      int len = g[v][j].second;
      if (d[v] + len < d[to]) {
        q.erase(std::make_pair(d[to], to));
        d[to] = d[v] + len;
        p[to] = v;
        q.insert(std::make_pair(d[to], to));
      }
    }
  }

  if (d[f - 1] == 1e9) {
    std::cout << -1;
  }
  else {
    /*
    std::vector<int> path;
    std::cout << '\n';
    for (int i = 0; i < n; i++) {
      std::cout << d[i] << ' ';
    }
    std::cout << '\n';
    for (int i = f-1; i != -1; i = p[i]) {
      std::cout << i << ' ';
      path.push_back(i);
      std::cout << i << ' ';
    }
    std::reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
      std::cout << path[i] << ' ';
    }
    std::cout << "done";
  }
  */
    std::cout << d[f - 1] + 1;
  }
}