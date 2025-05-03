#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

struct e {
  int to = 0;
  int from = 0;
  int cap = 0;
  int flow = 0;
};

int s = 0;
int t;
std::vector<int> level, ptr;

bool bfs(const std::vector<std::vector<e>>& g) {
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
  for (int& i = ptr[v]; i < g[v].size(); ++i) {
    e& u = g[v][i];
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
    std::fill(ptr.begin(), ptr.end(), 0);
    while (int flow = dfs(s, INT_MAX, g)) {
      max_flow += flow;
    }
  }
  return max_flow;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  int k = n + 28;
  t = k - 1;

  std::vector<std::vector<e>> g(k);
  std::vector<std::string> cards(n);
  std::unordered_map<int, char> letters;
  std::string cc;
  char a;
  char b;
  for (int i = 0; i < n; i++) {
    std::cin >> cc;
    cards[i] = cc;
    a = cc[0];
    b = cc[1];
    g[s].push_back({ i + 1, (int)g[i + 1].size(), 1, 0 });
    g[i + 1].push_back({ s, (int)g[s].size() - 1, 0, 0 });

    int ltoi1 = n + 1 + (a - 'a');
    g[i + 1].push_back({ ltoi1, (int)g[ltoi1].size(), 1, 0 });
    g[ltoi1].push_back({ i + 1, (int)g[i + 1].size() - 1, 0, 0 });
    letters[(i + 1) * k + ltoi1] = a;

    if (a != b) {
      int ltoi2 = n + 1 + (b - 'a');
      g[i + 1].push_back({ ltoi2, (int)g[ltoi2].size(), 1, 0 });
      g[ltoi2].push_back({ i + 1, (int)g[i + 1].size() - 1, 0, 0 });
      letters[(i + 1) * k + ltoi2] = b;
    }
  }

  std::string str;
  std::cin >> str;
  std::vector<int> cntr(26, 0);
  for (char c : str) {
    cntr[c - 'a'] += 1;
  }

  for (int i = 0; i < 26; ++i) {
    if (cntr[i] > 0) {
      int ltoi = n + 1 + i;
      g[ltoi].push_back({ t, (int)g[t].size(), cntr[i], 0 });
      g[t].push_back({ ltoi, (int)g[ltoi].size() - 1, 0, 0 });
    }
  }

  level.resize(k);
  ptr.resize(k);
  int max_flow = dinic(g);

  if (max_flow != str.size()) {
    std::cout << "IMPOSSIBLE";
    return 0;
  }
  char c;
  std::vector<std::vector<int>> f(26);
  for (int i = 1; i <= n; ++i) {
    for (const auto& edge : g[i]) {
      if (edge.flow > 0 && edge.to > n) {
        c = letters[i * k + edge.to];
        f[c - 'a'].push_back(i);
      }
    }
  }

  std::vector<int> ans;
  std::vector<int> card_ptr(26, 0);
  for (char c : str) {
    int ci = c - 'a';
    if (card_ptr[ci] >= f[ci].size()) {
      std::cout << "IMPOSSIBLE";
      return 0;
    }
    int ind = f[ci][card_ptr[ci]++];
    auto& card = cards[ind - 1];
    if (card[0] == c) {
      ans.push_back(ind);
    }
    else {
      ans.push_back(-ind);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}