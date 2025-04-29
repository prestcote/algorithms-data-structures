#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>

struct e {
  int to = 0;
  int from = 0;
  int cap = 0;
  int flow = 0;
};

int s = 0;
int t;
std::vector<int> parent, level;

bool bfs(const std::vector<std::vector<e>>& g) {
  std::fill(parent.begin(), parent.end(), -1);
  std::fill(level.begin(), level.end(), -1);
  level[s] = 0;
  std::queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (const auto& u : g[v]) {
      if (level[u.to] == -1 && u.flow < u.cap) {
        level[u.to] = level[v] + 1;
        parent[u.to] = v;
        q.push(u.to);
      }
    }
  }
  return level[t] != -1;
}

int dfs(int v, int flow, std::vector<std::vector<e>>& g) {
  if (v == t || flow == 0) {
    return flow;
  }
  for (auto& u : g[v]) {
    if (level[u.to] == level[v] + 1 && u.flow < u.cap) {
      int df = dfs(u.to, std::min(flow, u.cap - u.flow), g);
      if (df > 0) {
        u.flow += df;
        g[u.to][u.from].flow -= df;
        return df;
      }
    }
  }
  return 0;
}

int dinic(std::vector<std::vector<e>>& g) {
  int max_flow = 0;
  while (bfs(g)) {
    while (int flow = dfs(s, INT_MAX, g))
      max_flow += flow;
  }
  return max_flow;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 0;
  std::cin >> n;
  int k = n + 28;
  t = k - 1;
  std::vector<std::vector<e>> g(k);
  std::vector<std::string> cards(n);
  std::vector<std::vector<std::pair<int, char>>> letters(n);

  for (int i = 0; i < n; i++) {
    std::string a;
    std::cin >> a;
    cards[i] = a;

    g[s].push_back({ i + 1, (int)g[i + 1].size(), 1, 0 });
    g[i + 1].push_back({ s, (int)g[s].size() - 1, 0, 0 });

    int a1 = n + 1 + (a[0] - 'a');
    g[i + 1].push_back({ a1, (int)g[a1].size(), 1, 0 });
    g[a1].push_back({ i + 1, (int)g[i + 1].size() - 1, 0, 0 });
    letters[i].emplace_back(a1, a[0]);

    if (a[0] != a[1]) {
      int a2 = n + 1 + (a[1] - 'a');
      g[i + 1].push_back({ a2, (int)g[a2].size(), 1, 0 });
      g[a2].push_back({ i + 1, (int)g[i + 1].size() - 1, 0, 0 });
      letters[i].emplace_back(a2, a[1]);
    }
  }
  //std::cout << "checkpoint\n";
  std::string str;
  std::cin >> str;
  std::vector<int> cntr(26, 0);
  for (char c : str) cntr[c - 'a']++;
  //std::cout << "checkpoint\n";
  for (int i = 0; i < 26; i++) {
    if (cntr[i] > 0) {
      int ltoi = n + 1 + i;
      g[ltoi].push_back({ t, (int)g[t].size(), cntr[i], 0 });
      g[t].push_back({ ltoi, (int)g[ltoi].size() - 1, 0, 0 });
    }
  }
  //std::cout << "checkpoint\n";
  parent.resize(k);
  level.resize(k);
  int max_flow = dinic(g);
  //std::cout << "checkpoint\n";
  if (max_flow < (int)str.size()) {
    std::cout << "IMPOSSIBLE";
    return 0;
  }
  //std::cout << "checkpoint\n";
  std::vector<int> ans;
  std::vector<std::vector<int>> f(26);
  //std::cout << "checkpoint\n";
  for (int i = 0; i < n; i++) {
    for (auto& p : letters[i]) {
      int ltoi = p.first;
      char c = p.second;
      for (auto& u : g[i + 1]) {
        if (u.to == ltoi && u.flow > 0) {
          f[c - 'a'].push_back(i);
          break;
        }
      }
    }
  }
  //std::cout << "checkpoint\n";
  std::vector<int> ptr(26, 0);
  for (char c : str) {
    if (ptr[c - 'a'] >= (int)f[c - 'a'].size()) {
      std::cout << "IMPOSSIBLE";
      return 0;
    }
    int ind = f[c - 'a'][ptr[c - 'a']++];
    if (cards[ind][0] == c) {
      ans.push_back(ind + 1);
    }
    else {
      ans.push_back(-(ind + 1));
    }
  }
  //std::cout << "checkpoint\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}