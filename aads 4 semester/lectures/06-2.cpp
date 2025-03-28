#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define Min(a, b) ((a) < (b) ? (a) : (b))

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (auto item : v) {
    os << item << ' ';
  }
  return os;
}

std::vector<int> suffix_array(std::string s) {
  s += '\0';
  size_t n = s.size();
  std::vector<int> c(n);
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return s[i] < s[j];
    });
  std::cout << p << '\n';
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
  }
  std::cout << c << '\n';
  std::vector<std::pair<int, int>> pair(n);
  for (int len = 1; len < n; len *= 2) {
    for (int i = 0; i < n; i++) {
      pair[i] = { c[i], c[(i + len) % n] };
    }
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return pair[i] < pair[j];
      });
    c[p[0]] = 0;
    for (int i = 0; i < n; i++) {
      c[p[i]] = c[p[i - 1]] + (pair[p[i]] != pair[p[i - 1]]);
    }
  }
  return p;
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
  std::string s = "abacaba";
  suffix_array(s);
  return 0;
}