#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> nums;
  int n = 0;

  while (std::cin) {
    std::cin >> n;
    nums.push_back(n);
  }
  /*
  std::cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; i++) {
      std::cin >> nums[i];
  }
  */
  int s = nums[0];
  int f = nums[nums[0]];
  while (s != f) {
    s = nums[s];
    f = nums[nums[f]];
  }
  std::cout << nums[s];
  return 0;
}
