#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>


int main() {
  int n = 0;
  int s = 0;
  std::cin >> s >> n;
  std::vector<int> weight(s+1);
  for (int i = 0; i < n; i++) {
    std::cin >> weight[i];
  }
  std::vector<int> dp(s + 1);
  dp[0] = 1;
  for (int i = 1; i <= s; i++) {
    for (int j = 0; j < n; j++) {
      if (i - weight[j] > 0) {
        dp[i] = dp[i - weight[j]];
      }
    }
    dp[i] += 1;
  }
  std::cout << dp[s];

}