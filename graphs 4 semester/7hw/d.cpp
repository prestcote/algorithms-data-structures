#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void bridge(std::vector<std::vector<long long>>& g, std::vector<long long>& tin, std::vector<long long>& fup, long long& timer,
  std::vector<long long>& used, std::set<long long>& ans, long long v, long long p = -1) {
  used[v] = 1;
  tin[v] = (fup[v] = timer++);
  long long children = 0;
  for (auto& i : g[v]) {
    if (i == p) {
      continue;
    }
    if (!used[i]) {
      bridge(g, tin, fup, timer, used, ans, i, v);
      fup[v] = std::min(fup[v], fup[i]);
      children++;
      if (fup[i] >= tin[v] && p != -1) {
        ans.insert(v);
      }
    }
    else {
      fup[v] = std::min(fup[v], tin[i]);
    }
  }
  if (p == -1 && children > 1) {
    ans.insert(v);
  }
}

int main() {
  long long n = 0;
  long long m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<long long>> g(n + m + 1);
  long long a = 0;
  long long b = 0;
  long long c = 0;
  //std::cout << "checkpoint 1\n";
  for (long long i = 1; i <= m; i++) {
    std::cin >> a >> b >> c;
    g[n+i].push_back(a);
    g[a].push_back(n + i);
    g[n+i].push_back(b);
    g[b].push_back(n + i);
    g[n+i].push_back(c);
    g[c].push_back(n + i);
  }
  //std::cout << "checkpoint 2\n";
  std::vector<long long> tin(n +  m + 1, 0);
  std::vector<long long> fup(n + m + 1, 0);
  long long timer = 1;
  std::vector<long long> used(n + m + 1, 0);
  std::set<long long> ans;
  //std::cout << "checkpoint 3\n";
  for (long long i = 1; i <= n + m; i++) {
    if (!used[i]) {
      bridge(g, tin, fup, timer, used, ans, i);
    }
  }
  //std::cout << ans.size() << '\n';
  int cnt = 0;
  std::vector<int> vec;
  for (auto i : ans) {
    if (i > n) {
      cnt += 1;
      vec.push_back(i - n);
    }
    //std::cout << i - n << ' ';
  }
  std::cout << cnt << '\n';
  for (auto i : vec) {
    std::cout << i << ' ';
  }
  return 0;
}