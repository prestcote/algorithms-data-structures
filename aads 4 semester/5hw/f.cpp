#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define Min(a, b) ((a) < (b) ? (a) : (b));

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (auto item : v) {
    os << item << ' ';
  }
  return os;
}

std::vector<int> z_func(std::vector<int>& pi) {
  int n = pi.size();
  std::vector<int> z(n, 0);
  for (int i = 1; i < n; i++) {
    if (pi[i]) {
      z[i - pi[i] + 1] = pi[i];
    }
  }
  z[0] = 0;
  /*
  if (z[1] > 0) {
    for (int i = 1; i < z[1]; i++) {
      z[i + 1] = z[1] - i;
    }
  }*/
  for (int i = 1; i < z[1]; i++) {
    z[i + 1] = z[1] - i;
  }
  int t = 0;
  for (int i = z[1] + 1; i < n - 1; i++) {
    t = i;
    if (z[i] > 0 && z[i + 1] == 0)
      for (int j = 1; j < z[i] && z[i + j] <= z[j]; j++) {
        z[i + j] = Min(z[j], z[i] - j);
        t = i + j;
      }
    i = t;
  }
  return z;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> pi(n);
  for (int i = 0; i < n; i++) {
    std::cin >> pi[i];
  }
  std::cout << z_func(pi);
}
