#include <iostream>
#include <vector>

void rec(int n, int b, std::vector<int> vec) {
  if (n == 0) {
    for (int i = vec.size() - 1; i >= 0; i--) {
      std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
  }
  //if (n < 0) {
  //  return;
  //}
  for (int i = 1; i <= b; i++) {
    vec.push_back(i);
    rec(n - i, i, vec);
    vec.pop_back();
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vec;
  rec(n, n, vec);
}