#include <iostream>
#include <vector>
#include <queue>
#include <string>

const int INF = 1e9;

int get_sum(std::string s) {
  int res = 0;
  for (auto i : s) {
    res += i - '0';
  }
  return res;
}

std::vector<std::pair<int, int>> get_vert(int x) {
  std::vector<std::pair<int, int>> res;
  std::string temp = std::to_string(x);
  for (int i = 0; i < temp.size(); i++) {
    for (int j = 1; j <= temp.size() - i; j++) {
      auto help = temp.substr(i, j);
      res.push_back({ stoi(help), get_sum(help) });
    }

  }
  return res;
}

void diij(std::vector<int>& d, int a, int b, int n, std::vector<std::pair<int, int>>& p) {
  d[a] = 0;
  std::priority_queue<std::pair<int, int>> q;
  q.push({ 0, a });
  while (!q.empty()) {
    auto v = q.top().second;
    auto cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v]) continue;
    auto verts = get_vert(v);
    for (auto u : verts) {
      int to = v - u.first;
      int cost = u.second;
      if (to > 0 && to <= n && cur_d + cost < d[to]) {
        d[to] = cur_d + cost;
        q.push({ -d[to], to });
        p[to] = { v, -u.first };
      }
      to = v + u.first;
      if (to > 0 && to <= n && cur_d + cost < d[to]) {
        d[to] = cur_d + cost;
        q.push({ -d[to], to });
        p[to] = { v, u.first };
      }
    
    }
  }
}

int main()
{
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> d(n+1, INF);
  std::vector<std::pair<int, int>> p(n+1);
  diij(d, a, b, n, p);
  if (d[b] == INF) {
    std::cout << -1 << '\n';
  }
  else {
    std::cout << d[b] << '\n';
    std::vector<int> ans;
    while (b != a) {
      ans.push_back(p[b].second);
      b = p[b].first;
    }
    std::cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
      if (ans[i] > 0) {
        std::cout << '+';
      }
      std::cout << ans[i] << '\n';
    }
  }

  return 0;
}
