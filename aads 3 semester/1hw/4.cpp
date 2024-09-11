#include <iostream>
#include <vector>

std::vector<int> alg(int x) {
  std::vector<bool> vec(x + 1, true);
  std::vector<int> good;
  good.push_back(0);
  int count = 0;
  //vec[0] = false;
  //vec[1] = false;
  for (int i = 2; i <= x; i++) {
    if (vec[i]) {
      count += 1;
      good.emplace_back(i);
      for (int j = 2 * i; j <= x; j += i) {
        vec[j] = false;
      }
    }
  }
  return good;
}

int bruh(int n, std::vector<bool> vec) {
  int count = 0;
  int j = 0;
  int ans = 0;
  while (count != n) {
    if (vec[j]) {
      count += 1;
      ans = j;
    }
    j += 1;
  }
  return ans;
}

int main() {
  std::vector<int> vec = alg(10000000);
  /*
  int n = 0;
  std::cin >> n;
  int a = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    std::cout << bruh(a, vec) << ' ';
  }
  */
  for (int i = 0; i < 10; i++) {
    std::cout << vec[i] << ' ';
  }
}