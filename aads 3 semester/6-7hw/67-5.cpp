#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<long long> prev;
  std::vector<long long> cur(1, 1);
  if (n != 0) {
    std::cout << 1 << std::endl;
  }
  for (int i = 1; i < n; i++) {
    prev = cur;
    cur.resize(i+1);
    cur[0] = 1; 
    cur[i] = 1;
    for (int j = 1; j < i; j++) {
      cur[j] = prev[j] + prev[j - 1];
    }
    for (int k = 0; k < i+1; k++) {
      std::cout << cur[k] << ' ';
    }
    std::cout << std::endl;
  }
}