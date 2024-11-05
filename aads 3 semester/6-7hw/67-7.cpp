#include <iostream>
#include <vector>
#include <algorithm>


int main() {
  int n = 0;
  std::cin >> n;
  int nail = 0;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nail;
    vec[i] = nail;
  }
  std::sort(vec.begin(), vec.end());
  std::vector<int> dp(n);
  dp[1] = vec[1] - vec[0];
  dp[2] = vec[2] - vec[0];
  for (int i = 3; i < n; i++) {
    dp[i] = std::min(dp[i - 2], dp[i - 1]) + vec[i] - vec[i-1];
    //std::cout << dp[i] << '\n';
  }
  std::cout << dp[n - 1];
}