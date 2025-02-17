#include <iostream>
#include <vector>

std::vector<int> alg(int x) {
  std::vector<int> vec(x + 1, true);
  std::vector<int> good;
  good.push_back(0);
  int count = 0;
  //vec[0] = false;
  //vec[1] = false;
  for (int i = 2; i <= x; i++) {
    if (vec[i]) {
      count += 1;
      good.push_back(i);
      for (int j = 2 * i; j <= x; j += i) {
        vec[j] = false;
      }
    }
  }
  return good;
}

int main() {
  std::vector<int> vec = alg(1299709);
  int n = 0;
  std::cin >> n;
  int a = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    std::cout << vec[a] << ' ';
  }
}