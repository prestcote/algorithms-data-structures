#include <iostream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>> m, int s, std::vector<int>& d) {
  std::queue<int> q;
  q.push(s);
  std::vector<int> used(m.size(), 0);
  //std::vector<int> d(m.size());
  std::vector<int> p(m.size());
  used[s] = 1;
  p[s] = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto to : m[v]) {
      if (!used[to]) {
        used[to] = 1;
        q.push(to);
        d[to] = d[v] + 1;
        p[to] = v;
      }
    }
  }

}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> m(n);
  int s = 0;
  int f = 0;
  for (int i = 0; i < n-1; i++) {
    std::cin >> s >> f;
    m[s - 1].push_back(f - 1);
    m[f - 1].push_back(s - 1);
  }
  //for (int i = 0; i < n; i++) {

  //}
  std::vector<int> d(n, 0);
  bfs(m, 0, d);
  int start = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < d[i]) {
      max = d[i];
      start = i;
    }
    ///std::cout << d[i] << ' ';
  }
  //std::cout << '\n' << start << '\n';
  std::vector<int> new_d(n, 0);
  bfs(m, start, new_d);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, new_d[i]);
    //std::cout << new_d[i] << ' ';
  }
  std::cout << ans + 1;
}