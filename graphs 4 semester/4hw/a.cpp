#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void dij(std::vector<std::vector<std::pair<long long, long long>>>& g, std::vector<long long>& p, std::vector<long long>& d, long long s) {
  std::priority_queue<std::pair<long long, long long>> q;
  d[s] = 0; 
  q.push(std::make_pair(0, s));
  while (!q.empty()) {
    //std::cout << q.size()  << '\n';
    long long v = q.top().second;
    long long cur_d = -q.top().first;
    //std::cout << "check1 ";
    q.pop();
    if (cur_d > d[v]) {
      continue;
    }
    //std::cout << "check2 ";
    for (size_t j = 0; j < g[v].size(); j++) {
      long long to = g[v][j].first;
      long long len = g[v][j].second;
      //std::cout << "check3 ";
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
        q.push(std::make_pair(-d[to], to));
        //std::cout << "check4 ";
      }
    }

  }
}

int main() {
  long long n = 0;
  long long s = 0;
  long long f = 0;
  std::cin >> n >> s >> f;
  s--;
  f--;
  long long c = 0;
  std::vector<std::vector<std::pair<long long, long long>>> g(n);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      std::cin >> c;
      if (c > 0) {
        g[i].push_back(std::make_pair(j, c));
        //g[j].push_back(std::make_pair(i, c));
      }
    }
  }
  //std::cout << "hiii";
  std::vector<long long> p(n, -1);
  std::vector<long long> d(n, 1e9);
  dij(g, p, d, s);
  //std::cout << "hello";
  if (d[f] == 1e9) {
    std::cout << -1 << '\n';
  }
  else {
    std::vector<long long> path;
    for (long long i = f; i != -1; i = p[i]) {
      path.push_back(i + 1);
    }
    std::reverse(path.begin(), path.end());
    for (long long i = 0; i < path.size(); i++) {
      std::cout << path[i] << ' ';
    }
  }
}