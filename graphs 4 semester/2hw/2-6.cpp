#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(int v, int w, std::vector<int>& used, std::vector<int>& p, std::vector<int>& d) {
  std::queue<int> q;
  //std::vector<int> used(g.size(), 0);
  q.push(v);
  used[v] = 1;
  p[v] = -1;
  while (!q.empty()) {
    //std::cout << "count" << '\n';
    int s = q.front();
    q.pop();
    std::vector<int> moves;
    if (s / 1000 != 9 && v + 1000 < 10000) {
      moves.push_back(s + 1000);
    }
    if (s % 10 != 1 && s-1 > 999) {
      moves.push_back(s - 1);
    }
    moves.push_back((s % 10) * 1000 + s / 10);
    moves.push_back((s % 1000) * 10 + s / 1000);
    //std::cout << v << ' ' << (v % 1000) * 10 + v / 1000 << '\n';
    for (int i = 0; i < moves.size(); i++) {
      //std::cout << moves[i] << ' ';
      if (used[moves[i]] == 0) {
        used[moves[i]] = 1;
        q.push(moves[i]);
        p[moves[i]] = s;
        d[moves[i]] = d[s] + 1;
        if (moves[i] == w) {
          return;
        }
      }
    }
  }
}

int main() {
  int f = 0;
  int t = 0;
  std::cin >> f >> t;
  std::vector<int> used(10000, 0);
  std::vector<int> p(10001);
  std::vector<int> d(10001, 0);
  bfs(f, t, used, p, d);
  std::vector<int> path;
  for (int i = t; i != -1; i = p[i]) {
    path.push_back(i);
  }
  std::reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    std::cout << path[i] << '\n';
  }
}