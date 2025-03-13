#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

std::ostream& operator << (std::ostream& os, const std::vector<int>& v) {
  for (auto el : v) {
    os << el << ' ';
  }
  return os;
}

std::istream& operator >> (std::istream& is, std::vector<int>& v) {
  for (auto& el : v) {
    is >> el;
  }
  return is;
}

struct Query {
  int id = 0;
  int left = 0;
  int right = 0;
  int res = 0;
};

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<int> v(n);
  std::cin >> v;

  std::vector<int> pos = v;
  std::sort(pos.begin(), pos.end());

  for (auto& el : v) {
    el = std::lower_bound(pos.begin(), pos.end(), el) - pos.begin();
  }

  int m = 0;
  std::cin >> m;
  std::vector<Query> queries(m);
  for (int i = 0; i < m; ++i) {
    queries[i].id = i;
    std::cin >> queries[i].left >> queries[i].right;
  }


  std::sort(queries.begin(), queries.end(),
    [](const Query& lhs, const Query& rhs) {
      return std::tuple<int, int>(lhs.left / 500, lhs.right) <
        std::tuple<int, int>(rhs.left / 500, rhs.right);
    });

  int a = 0, b = -1;
  int diff = 0; // кол-во различных от a до b
  std::vector<int> count(n); // кол-во i элементов от a до b

  for (auto& q : queries) {
    --q.left;
    --q.right;
    while (a < q.left) {
      --count[v[a]];
      if (count[v[a]] == 0) --diff;
      ++a;
    }
    while (a > q.left) {
      --a;
      if (count[v[a]] == 0) ++diff;
      ++count[v[a]];
    }
    while (b < q.right) {
      ++b;
      if (count[v[b]] == 0) ++diff;
      ++count[v[b]];
    }
    while (b > q.right) {
      --count[v[b]];
      if (count[v[b]] == 0) --diff;
      --b;
    }
    q.res = diff;
  }

  std::sort(queries.begin(), queries.end(),
    [](const Query& lhs, const Query& rhs) {
      return lhs.id < rhs.id;
    });

  for (auto q : queries) {
    std::cout << q.res << '\n';
  }
  return 0;
}
