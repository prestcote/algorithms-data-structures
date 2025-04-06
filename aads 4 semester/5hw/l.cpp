#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool dfs(int v, std::vector<std::vector<int>>& g, std::vector<int>& p, std::vector<int>& used) {
  if (used[v] == 1) {
    return false;
  }
  used[v] = 1;
  for (int to : g[v]) {
    if (p[to] == -1 || dfs(p[to], g, p, used)) {
      p[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (s.size() > n) {
    std::cout << "NO";
    return 0;
  }
  //std::cout << "checkpoint 1\n";
  std::vector<std::string> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }
  //std::cout << "checkpoint 2\n";
  std::vector<std::vector<int>> g(s.size());
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    for (int j = 0; j < n; j++) {
      if (vec[j].find(c) != std::string::npos) {
        g[i].push_back(j);
      }
    }
  }
  //std::cout << "checkpoint 3\n";
  std::vector<int> p(n, -1);
  for (int v = 0; v < s.size(); ++v) {
    std::vector<int> used(s.size(), 0);
    dfs(v, g, p, used);
  }
  //std::cout << "checkpoint 4\n";
  std::vector<int> ans(s.size(), -1);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > -1) {
      ans[p[i]] = i;
      //std::cout << ans[p[i]] << ' ';
      count += 1;
    }
  }
  //std::cout << "checkpoint 5\n";
  if (count == s.size()) {
    std::cout << "YES\n";
    for (int i = 0; i < count; i++) {
      std::cout << ans[i] + 1 << ' ';
    }
  }
  else {
    std::cout << "NO";
  }
  return 0;
}