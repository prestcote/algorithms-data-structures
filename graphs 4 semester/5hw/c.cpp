#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

void dij(std::vector<std::vector<std::pair<int, double>>>& g, std::vector<std::vector<double>>& d, int s) {
  std::vector<double> p(g.size(), 1e9);
  d[s][s] = 0;
  std::priority_queue<std::pair<double, size_t>> q;
  q.push({ 0, s });
  while (!q.empty()) {
    size_t v = q.top().second;
    double cur = -q.top().first;
    q.pop();
    if (cur > d[s][v]) {
      continue;
    }
    for (size_t j = 0; j < g[v].size(); j++) {
      size_t to = g[v][j].first;

      double len = g[v][j].second;
      if (d[s][v] + len < d[s][to]) {
        d[s][to] = d[s][v] + len;
        p[to] = v;
        q.push({ -d[s][to], to });
      }
    }

  }
}

int main() {
  size_t n = 0;
  size_t evc = 0;
  std::cin >> n >> evc;
  std::vector < std::pair<double, double>> vec(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> vec[i].first >> vec[i].second;
  }
  std::vector<std::vector<std::pair<int, double>>> g(n);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      double x = (std::sqrt((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second)));
      if (x <= evc) {
        g[i].push_back({ j, x });
        g[j].push_back({ i, x });
      }
    }
  }
  std::vector<std::vector<double>> d(n, std::vector<double> (n, 1e9));

  size_t k = 0;
  std::cin >> k;
  std::vector<std::pair<size_t, size_t>> v;
  std::set<size_t> sett;
  double a, b;
  for (size_t i = 0; i < k; i++) {
    std::cin >> a >> b;
    v.push_back({ a-1, b-1 });
    sett.insert(a-1);
  }
  for (size_t i : sett) {
    dij(g, d, i);
  }
  
  for (std::pair<double, double> f : v) {
    if (d[f.first][f.second] == 1e9) {
      std::cout << "-1\n";
    }
    else {
      std::cout << std::fixed << std::setprecision(9) << d[f.first][f.second] << '\n';
    }
  }
  
}