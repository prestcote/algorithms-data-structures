
#include <iostream>
#include <vector>

void rec(int n, int b, std::vector<int> vec) {
  if (n == 0) {
    for (int i = vec.size()-1; i >=0; i--) {
      std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
  }
  if (n < 0) {
    return;
  }
  for (int i = b; i > 0; i--) {
    vec.push_back(i);
    rec(n - i, i, vec);
    vec.pop_back();
  }
}
/*
int rec2(int64_t a, int64_t n, int number) {
  if 
} */

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vec;
  rec(n, n, vec);
}
