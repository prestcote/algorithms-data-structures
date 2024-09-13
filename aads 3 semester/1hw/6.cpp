#include <iostream>
#include <vector>
#include <set>

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
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  std::vector<int> vec = alg(2000100);
  std::set<int> kmp;
  for (int i = a; i <= b; i++) {
    int k = i;
    int j = 1;
    while (vec[j] <= k && j < vec.size()) {
      if (k % vec[j] == 0) {
        kmp.insert(vec[j]);
        while (k % vec[j] == 0) {
          k /= vec[j];
        }
      }
      if (k != 1 && vec[j]*vec[j]>k) {
        kmp.insert(k);
        k = 1;
        break;
      }
      j += 1;
    }
  }
  std::cout << kmp.size();
}