#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> nums(n);
  int mins = 1e6;
  int ind = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  std::deque<int> deq;

  for (int i = 0; i < n; i++) {
    //std::cout << "i: " << i << ' ' << deq.front() << '\n';
    if (!deq.empty() && deq.front() == i - k) {
      deq.pop_front();
    }
    while (!deq.empty() && nums[i] <= nums[deq.back()]) {
      deq.pop_back();
    }
    deq.push_back(i);
    if (i >= k - 1) {
      std::cout << nums[deq.front()] << '\n';
    }

  }
  return 0;

}
