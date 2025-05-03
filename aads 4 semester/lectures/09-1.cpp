#include <iostream>
#include <vector>
#include <functional>

class Graph {
private:
  std::vector<std::vector<long long>> g;
  size_t ln = 1LL;
  std::vector<long long> list;
  std::vector<long long> h;
  std::vector<long long> used;
  std::vector<long long>tree;
  std::vector<long long> first;
public:
  size_t size() {
    return g.size();
  }
  explicit Graph() = default;
  Graph(std::vector<std::vector<long long>>& vec, long long root_) {
    g = vec;
    build(root_);
  }
  void dfs(long long v, long long height = 1) {
    used[v] = 1;
    h[v] = height;
    list.push_back(v);
    for (long long i : g[v])
      if (!used[i])
      {
        dfs(i, height + 1);
        list.push_back(v);
      }
  }
  
  void build(long long i, long long l, long long r)
  {
    if (l == r)
      tree[i] = list[l];
    else
    {
      long long m = (l + r) >> 1;
      build(i + i, l, m);
      build(i + i + 1, m + 1, r);
      if (h[tree[i + i]] < h[tree[i + i + 1]])
        tree[i] = tree[i + i];
      else
        tree[i] = tree[i + i + 1];
    }
  }

  void build(long long root)
  {
    long long n = (long long)g.size();
    h.resize(n);
    list.reserve(n * 2);
    used.assign(n, 0);

    dfs(root);
    long long m = (long long)list.size();
    tree.assign(list.size() * 4 + 1, -1);
    build(1, 0, m - 1);

    first.assign(n, -1);
    for (long long i = 0; i < m; ++i)
    {
      long long v = list[i];
      if (first[v] == -1)
        first[v] = i;
    }
  }

  long long lca_tree_min(long long i, long long sl, long long sr, long long l, long long r)
  {
    if (sl == l && sr == r)
      return tree[i];
    long long sm = (sl + sr) >> 1;
    if (r <= sm)
      return lca_tree_min(i + i, sl, sm, l, r);
    if (l > sm)
      return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
    long long ans1 = lca_tree_min(i + i, sl, sm, l, sm);
    long long ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
    return h[ans1] < h[ans2] ? ans1 : ans2;
  }

  long long lca(long long a, long long b)
  {
    long long left = first[a];
    long long right = first[b];
    if (left == -1 || right == -1) return -1;
    if (left > right)  std::swap(left, right);
    return lca_tree_min(1, 0, (long long)list.size() - 1, left, right);
  }
};

int main() {
  long long n = 0;
  long long m = 0;
  std::cin >> n >> m;
  if (n == 1) {
    std::cout << 0;
    return 0;
  }
  std::vector<std::vector<long long>> g(n);
  long long q = 0;
  //std::cout << "checkpoint 1\n";
  for (long long i = 1LL; i < n; i++) {
    std::cin >> q;
    g[q].push_back(i);
    g[i].push_back(q);
  }
  //std::cout << "checkpoint 2\n";
  Graph graph(g, 0);
  //std::cout << "checkpoint 3\n";
  long long a1 = 0;
  long long a2 = 0;
  long long x = 0;
  long long y = 0;
  long long z = 0;
  std::vector<long long> a(2 * m + 1);
  std::cin >> a[1] >> a[2] >> x >> y >> z;
  //std::cout << "checkpoint 4\n";
  for (long long i = 3; i <= 2 * m; i++) {
    a[i] = (x * a[i - 2] * 1LL + y * a[i - 1] * 1LL + z) % n;
  }
  //std::cout << "checkpoint 5\n";
  long long v = graph.lca(a[1], a[2]);
  //std::cout << "checkpoint 6\n";
  long long ans = v;
  for (long long i = 2; i <= m; i++) {
    v = graph.lca((a[2 * i - 1] + v) % n, a[2 * i]);
    ans += v;
  }
  //std::cout << "checkpoint 7\n";
  std::cout << ans;
  return 0;
}
