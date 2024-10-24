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
  int INF = 10000000001;
  //std::vector<int> vec(n);
  std::vector<int> dp(n, INF);
  dp[0] = -INF;
  //vec[0] = a1;
  dp[1] = a1;
  int key = a1;
  int answer = 1;
  for (int i = 1; i < n; i++) {
    key = (key * k + b) % m;
    int left = 0;
    int right = n;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (dp[mid] <= key) {
        left = mid;
      }
      else {
        right = mid;
      }
    }
    if (dp[right] > key) {
      dp[right] = key; //минимальный элемент последовательности длины right
      answer = std::max(answer, right);
    }
  }
  std::cout << answer;
  return 0;
}