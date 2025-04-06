#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define Min(a, b) ((a) < (b) ? (a) : (b))

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (size_t i = 1; i < v.size(); i++) {
    os << v[i] + 1 << ' ';
  }
  return os;
}

std::vector <int> suffix_array(std::string s) {
  s += '\0';
  size_t n = s.size();
  //std::cout << n << '\n';
  //std::cout << s << '\n';
  std::vector<int> c(n);
  std::vector<int> p(n);
  std::vector<std::pair<int, int>> pairs(n);

  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return s[i] < s[j];
    });
  //std::cout << p << '\n';

  c[p[0]] = 0;
  for (int i = 1; i < n; ++i) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }
  //std::cout << c;

  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; ++i) {
      pairs[i] = { c[i], c[(i + len) % n] };
    }
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return pairs[i] < pairs[j];
      });
    c[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
      c[p[i]] = c[p[i - 1]] + (pairs[p[i]] != pairs[p[i - 1]]);
    }
  }

  return p;
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::cout << suffix_array(s);
}

