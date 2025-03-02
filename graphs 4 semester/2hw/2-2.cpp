#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <algorithm>

void bfs(std::string v, std::map<std::string, std::vector<std::string>>& g, std::map<std::string, int>& d) {
  std::queue<std::string>q;
  q.push(v);
  d[v] = 0;
  while (!q.empty()) {
    std::string s = q.front();
    q.pop();
    for (const std::string to : g[s]) {
      q.push(to);
      d[to] = d[s] + 1;
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::map<std::string, std::vector<std::string>> m;
  std::vector<std::string> parents;
  std::set<std::string> children;
  std::string par, ch;
  for (int i = 0; i < n-1; i++) {
    std::cin >> ch >> par;
    m[par].push_back(ch);
    children.insert(ch);
    parents.push_back(par);
    //std::cout << "stage 0";
  }
  //std::cout << "stage one";
  
  std::string head;
  
  for (auto c : parents) {
    if (children.count(c) == 0) {
      head = c;
      //std::cout << '\n' << head << '\n';
    }
  }
  //head = parents[0];
  //std::cout << "stage two";
  std::map<std::string, int> d;
  bfs(head, m, d);
  for (const auto j : d) {
    std::cout << j.first << ' ' << j.second << '\n';
  }
}