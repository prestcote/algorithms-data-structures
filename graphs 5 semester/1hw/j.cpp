#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  int k = 0;
  std::cin >> k;
  int l = 0;
  int r = n - 1;
  int m = 0;
  while (l < r) {
    m = l + (r - l) / 2;
    if (nums[l] < nums[r])
      break;
    if (nums[m] < nums[l])
      r = m;
    else if (nums[m] > nums[l])
      l = m + 1;
    else {
      l += 1;
    }
  }
  int mid = l - 1;
  if (nums[0] <= k && nums[mid] >= k) {
    l = 0;
    r = mid;
  }
  else {
    l = mid + 1;
    r = n - 1;
  }
  while (l < r) {
    m = l + (r - l) / 2;
    if (k == nums[m]) {
      l = m;
      break;
    }
    else if (k < nums[m]) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
  std::cout << l;
  return 0;
}
