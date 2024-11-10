#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> mass(n+1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> mass[i];
  }
  std::vector<int> price(n+1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> price[i];
  }
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 0) {
        dp[i][j] = 0;
      }
      else if (j - mass[i] < 0) {
        dp[i][j] = dp[i - 1][j];
      }
      else if (j - mass[i] >= 0) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - mass[i]] + price[i]);
      }
    }
  }
  std::cout << dp[n][m];
}