#include <iostream>
#include <vector>
#include <string>

std::ostream& operator<<(std::ostream& os, const std::vector<long long>& v) {
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i] << ' ';
  }
  return os;
}

std::vector<long long> pi(std::string s) {
  long long n = s.size();
  std::vector<long long> p(n, 0);
  for (long long i = 1; i < n; i++) {
    long long j = p[i - 1];
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
  std::vector<long long> p = pi(s);
  //std::cout << p <<'\n';
  std::cout << s.size() - p[s.size() - 1];
  return 0;
}