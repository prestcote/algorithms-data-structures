#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

void rec(int n, int b, std::set<std::vector<int>, std::greater<std::vector<int>>>& sett, std::vector<int> vec) {
  if (n == 0) {
    std::sort(vec.begin(), vec.end());
    sett.insert(vec);
    vec.clear();
  }
  if (n < 0) {
    return;
  }
  for (int i = b; i > 0; --i) {
    vec.push_back(i);
    rec(n - i, i, sett, vec);
    vec.pop_back();
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vec;
  std::set<std::vector<int>, std::greater<std::vector<int>>> sett;
  rec(n, n, sett, vec);

  for (auto a : sett) {
    for (int i = 0; i < a.size(); i++) {
      std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
  }
}