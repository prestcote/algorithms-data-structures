#include <iostream>
#include <vector>
#include <set>

int n, m;
std::vector<std::vector<int>> g;
std::vector<std::vector<int>> newG;
std::set<std::pair<int, int>> ans;
std::vector<int> tin;
std::vector<int> fup;
int timer = 0;
std::vector<int> used;
std::vector<int> cmp;
std::vector<int> cmpSz;
int curCmp = 0;

long long MOD = 1e9 + 7;

void find_bridges(int v, int p = -1) {
  used[v] = 1;
  tin[v] = (fup[v] = timer++);
  for (auto i : g[v]) {
    if (i == p) {
      continue;
    }
    if (!used[i]) {
      find_bridges(i, v);
      fup[v] = std::min(fup[v], fup[i]);
      if (fup[i] > tin[v]) {
        ans.insert({std::min(v, i), std::max(v, i)});
      }
    }
    else {
      fup[v] = std::min(fup[v], tin[i]);
    }
  }
}

bool isBridge(int v, int to) {
  if (ans.count({ std::min(v, to), std::max(v, to) })) {
    return true;
  }
  return false;
}

void dfs(int v) {
  used[v] = 1;
  cmp[v] = curCmp;
  ++cmpSz[curCmp];
  for (auto to : g[v]) {
    if (isBridge(v, to)) {
      continue;
    }
    if (!used[to]) {
      dfs(to);
    }
  }
}

int main() {
  std::cin >> n >> m;
  g.resize(n);
  newG.resize(n);
  tin.resize(n);
  fup.resize(n);
  used.assign(n, 0);
  cmp.resize(n);
  cmpSz.resize(n);
  //std::cout << "checkpoint 1\n";
  for (int i = 0; i < m; i++) {
    int from, to;
    std::cin >> from >> to;
    g[from - 1].push_back(to - 1);
    g[to - 1].push_back(from - 1);
  }
  //std::cout << "checkpoint 2\n";
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      find_bridges(i);
    }
  }
  //std::cout << "checkpoint 3\n";
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  //std::cout << "checkpoint 4\n";
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
      ++curCmp;
    }
  }
  //std::cout << "checkpoint 5\n";

  if (curCmp == 1) {
    std::cout << "1 " << n << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (auto to : g[i]) {
      if (isBridge(i, to)) {
        newG[cmp[i]].push_back(cmp[to]);
      }
    }
  }

  int ans1 = 0;
  long long ans2 = 1;
  for (int i = 0; i < curCmp; i++) {
    if (newG[i].size() == 1) {
      ans1++;
      ans2 *= cmpSz[i];
      ans2 %= MOD;
    }
  }

  std::cout << ans1 << ' ' << ans2;

  return 0;
}
