#include <iostream>
#include <vector>
#include <string>

void dfs(int v, std::vector<std::vector<int>>& g, std::vector<int>& used, std::vector<int>& p, bool& cycle) {
  used[v] = 1;
  for (int to : g[v]) {
    if (used[to] == 0) {
      p[to] = v;
      dfs(to, g, used, p, cycle);
    }
    else if (used[to] == 1 && to != p[v]) {
      cycle = false;
      return;
    }
  }
  used[v] = 2;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::string s;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    std::cin >> s;
    //std::cout << s.size();
    for (int j = 0; j < s.size(); j++) {
      //std::cout << "PROBLEM HERE";
      if (s[i] == 'R') {
        //std::cout << "AND HERE";
        g[i].push_back(j);
      }
      else {
        g[j].push_back(i);
      }
    }
  }
  std::vector<int> p(n, -1);
  std::vector<int> used(n, 0);
  bool cycle = true;
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      dfs(i, g, used, p, cycle);
    }
  }
  if (cycle == true) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }
}