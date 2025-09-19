#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> dp(n, 0);
  int num = 0;
  std::cin >> num;
  if (num == 0) {
    dp[0] = 1;
  }
  for (int i = 1; i < n; i++) {
    std::cin >> num;
    dp[i] = dp[i - 1];
    if (num == 0) {
      dp[i] += 1;
    }
  }
  int k = 0;
  std::cin >> k;
  int l = 0;
  int r = 0;
  /*
  for (int i = 0; i < n; i++) {
      std::cout << dp[i] << ' ';
  }
  */
  std::vector<int> ans;
  for (int i = 0; i < k; i++) {
    std::cin >> l >> r;
    if (l == 0) {
      ans.push_back(dp[r - 1]);
    }
    else {
      ans.push_back(dp[r - 1] - dp[l - 2]);
    }
  }
  for (int i = 0; i < k; i++) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}
