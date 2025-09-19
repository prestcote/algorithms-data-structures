#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int>nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  int l = 0;
  int r = n - 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (nums[m] != nums[m ^ 1])
      r = m;
    else
      l = m + 1;

  }
  std::cout << nums[l];
  return 0;
}
