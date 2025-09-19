#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> goal(n);
  for (int i = 0; i < n; i++) {
    std::cin >> goal[i];
  }
  int k = 0;
  std::cin >> k;
  std::vector<int> process(n);
  int ind = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> ind;
    process[ind - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (process[i] > goal[i]) {
      std::cout << "yes\n";
    }
    else {
      std::cout << "no\n";
    }
  }
  return 0;

}
