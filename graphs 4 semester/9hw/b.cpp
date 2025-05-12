#include <iostream>
#include <vector>
#include <climits>

bool check(const std::vector<std::vector<long long>>& tree, std::vector<long long>& val, long long v, long long l, long long r) {
  if (v == -1)
    return true;
  if (val[v] < l || val[v] > r)
    return false;
  return check(tree, val, tree[v][0], l, val[v] - 1) && check(tree, val, tree[v][1], val[v] + 1, r);
}

int main() {
  long long n = 0;
  std::cin >> n;
  std::vector<std::vector<long long>> tree(n);
  std::vector<long long> val(n);
  long long key = 0;
  long long l = 0;
  long long r = 0;
  for (long long i = 0; i < n; i++) {
    std::cin >> key >> l >> r;
    val[i] = key;
    tree[i].push_back(l);
    tree[i].push_back(r);
  }
  if (check(tree, val, 0, INT_MIN, INT_MAX)) {
    std::cout << "CORRECT";
  }
  else {
    std::cout << "INCORRECT";
  }
}

