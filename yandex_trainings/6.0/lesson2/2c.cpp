#include <iostream>
#include <vector>

int main() {
  int r = 0;
  int n = 0;
  std::cin >> n >> r;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  int left = 0;
  int right = 0;
  int count = 0;
  while (right < n) {
    while (vec[right] - vec[left] <= r) {
      right += 1;
    }
    while (vec[right] - vec[left] > r) {
      left += 1;
    }
    left -= 1;
    count += left + 1;
    right += 1;
  }
  std::cout << count;
}