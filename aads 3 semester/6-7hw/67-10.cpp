#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>


int main() {
  int n = 0;
  int s = 0;
  std::cin >> n;
  std::vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    std::cin >> weight[i];
  }
  std::cin >> s;
  std::vector<int> dp(s + 1, 5000000);
  std::vector <int> ans(s+1, -1);
  dp[0] = 0;
  
  for (int i = 1; i <= s; i++) {
    for (int j = 0; j < n; j++) {
      if (i - weight[j] >= 0 && dp[i] > dp[i - weight[j]]) {
        dp[i] = dp[i - weight[j]] + 1;
        ans[i] = weight[j];
      }
    }
  }
  if (dp[s] != 5000000) {
    std::cout << dp[s] << '\n';
    while (s > 0) {
      std::cout << ans[s] << ' ';
      s -= ans[s];
    }
  }
  else {
    std::cout << "- 1";
  }
}