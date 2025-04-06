#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// z-function

#define Min(a, b) ((a) < (b) ? (a) : (b));

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (auto item : v) {
    os << item << ' ';
  }
  return os;
}

std::vector<int> z_func(const std::string& s) {
  size_t n = s.size();
  int left = 0;
  std::vector<int> z(n);
  for (size_t i = 1; i < n; i++) {
    if (i < z[left] + left) {
      z[i] = Min(z[i - left], z[left] + left - i);
    }
    while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
      z[i] += 1;
    }
    if (z[i] + i > z[left] + left) {
      left = i;
    }
  }
  z[0] = n;
  return z;
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << z_func(s);
}
