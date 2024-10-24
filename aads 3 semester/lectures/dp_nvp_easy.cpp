#include <iostream>
#include <array>

#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  int n = 0;
  int a1 = 0;
  int k = 0;
  int b = 0;
  int m = 0;
  std::cin >> n >> a1 >> k >> b >> m;
  std::vector<int> vec(n);
  std::vector<int> dp(n);
  vec[0] = a1;
  int answer = 0;
  for (size_t i = 1; i < vec.size(); i++) {
    vec[i] = (vec[i - 1] * k + b) % m;
    for (size_t j = 0; j < i; j++) {
      if (vec[i] > vec[j] && dp[i] < dp[j]) {
        dp[i] = dp[j] + 1;
      }
    }
    answer = std::max(answer, dp[i]);
  }
  std::cout << answer;
}