#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> prefix = { 0 };

  int el = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> el;
    prefix.push_back(prefix[i - 1] + el);
  }
  int l = 1;
  int r = 1;
  int count = 0;
  while (r < n) {
    if (l == r && prefix[l] == k) {
      count += 1;
    }
    
    if (prefix[r] - prefix[l] == k) {
      count += 1;
    }
    r += 1;
    
    while (prefix[r] - prefix[l] > r) {
      l += 1;
    }
  }
  std::cout << count;
}