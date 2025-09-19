#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct MyComparator {
  bool operator()(std::pair<long long, std::pair<long long, long long>> a, std::pair<long long, std::pair<long long, long long>> b) const
  {
    return (a.first < b.first || (a.first == b.first && a.second.first > b.second.first));
  }
};

int main() {
  long long n = 0;
  long long m = 0;
  std::cin >> n >> m;
  long long l = 0;
  long long r = 0;
  std::multiset<std::pair<long long, std::pair<long long, long long>>, MyComparator> q;
  std::vector<long long> ans(m);
  for (size_t i = 0; i < n; i++) {
    std::cin >> l >> r;
    q.insert({ l, {1, 0} });
    q.insert({ r, { -1, 0} });
  }
  for (size_t i = 0; i < m; i++) {
    std::cin >> l;
    q.insert({ l, {0, i} });
  }
  long long count = 0;
  
  /*
  for (std::pair<long long, long long> t : q) {
    std::cout << t.first << ':' << t.second << ' ';
  }
  */
  for (auto t : q) {
    count += t.second.first;
    if (t.second.first == 0) {
      ans[t.second.second] = count;
    }
  }

  for (int i = 0; i < m; i++) {
    std::cout << ans[i] << ' ';
  }
}