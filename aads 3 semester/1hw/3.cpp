#include <iostream>
#include <vector>

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
  std::vector<int> vec = alg(500000);
  for (int i = 2; i <= n; i++) {
    int j = 1;
    int count = 0;
    while (vec[j] * 2 <= i) {
      if (i % vec[j] == 0) {
        count += 1;
      }
      if (count >= 3) {
        std::cout << i << ' ';
        break;
      }
      j += 1;
    }
  }

}