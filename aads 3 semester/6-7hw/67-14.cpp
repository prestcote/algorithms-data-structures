#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<long long>b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  std::vector<long long> dp(m, 0);

  for (size_t i = 0; i < n; i++) {
    int l = 0;
    //std::cout << "HELLLOOOO";
    for (size_t j = 0; j < m; j++) {
      //std::cout << "YIPYYYY";
      if (a[i] == b[j]) {
        if (l + 1 > dp[j]) {
          dp[j] = l + 1;
        }
      }
      if (a[i] > b[j]) {
        if (dp[j] > l) {
          l = dp[j];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (dp[i] > ans) {
      ans = dp[i];
    }
  }
  std::cout << ans;
}