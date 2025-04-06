#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i] << ' ';
  }
  return os;
}

std::vector<int> pi(std::string s) {
  int n = s.size();
  std::vector<int> p(n, 0);
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];

    }
    if (s[i] == s[j]) {
      j += 1;
    }
    p[i] = j;
  }
  return p;
}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << pi(s);
}