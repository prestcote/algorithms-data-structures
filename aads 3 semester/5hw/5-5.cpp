#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for (auto& x : v) {
    std::cin >> x;
  }

  int left = -1;
  int right = v.back();
  int ans = 0;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    int cnt = 1;
    int len = 0;
    for (int i = 1; i < n; i++) {
      len += v[i] - v[i - 1];
      if (len >= mid) {
        len = 0;
        cnt += 1;
      }
    }
    if (k <= cnt) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  //std::cout << left << ' ' << right;
  std::cout << left;

}
