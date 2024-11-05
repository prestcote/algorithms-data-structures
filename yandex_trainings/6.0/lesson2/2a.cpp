#include <iostream>

int main() {
  int n = 0; 
  std::cin >> n;
  int el = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> el;
    sum += el;
    std::cout << sum << ' ';
  }
}