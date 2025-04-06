#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i] << ' ';
  }
  return os;
}

std::vector<int> pi(std::vector<int>& z) {
  int n = z.size();
  std::vector<int> p(n, 0);
  for (int i = 1; i < n; i++) {
    if (z[i] > 0) {
      for (int j = z[i] - 1; j >= 0; j--) {
        if (p[i + j] > 0) {
          break;
        }
        p[i + j] = j + 1;
      }
    }
  }
  return p;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> z(n);
  //std::cout << "checkpoint 1\n";
  for (int i = 0; i < n; i++) {
    std::cin >> z[i];
  }
  //std::cout << "checkpoint 2\n";
  std::cout << pi(z);
}