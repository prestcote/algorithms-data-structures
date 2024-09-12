#include <iostream>
#include <vector>

void fact(int n, std::vector<int> vec) {
  for (int i = 1; i * i <= n/2 + 1; i++) {
    int c = vec[i];
    while (n % c == 0) {
      std::cout << c << ' ';
      n /= c;
    }
  }
  if (n != 1) {
    std::cout << n << ' ';
  }
}

std::vector<int> alg(int x) {
  std::vector<int> vec(x + 1, true);
  std::vector<int> good;
  good.push_back(0);
  for (int i = 2; i <= x; i++) {
    if (vec[i]) {
      good.push_back(i);
      for (int j = 2 * i; j <= x; j += i) {
        vec[j] = false;
      }
    }
  }
  return good;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vec = alg(1200000);
  fact(n, vec);
}