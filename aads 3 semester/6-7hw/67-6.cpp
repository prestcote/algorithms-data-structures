#include <iostream>
#include <vector> 
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  int el;
  std::vector<int> money(n);
  std::cin >> money[0];
  std::cin >> money[1];
  int min = 0;
  for (int i = 2; i < n; i++) {
    std::cin >> el;
    money[i] = el + std::min(money[i - 1], money[i - 2]);
  }
  std::cout << money[n - 1];
}