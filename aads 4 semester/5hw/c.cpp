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
  std::string a; // text
  std::string b; // string
  std::cin >> a >> b;
  int n = b.size(); // string
  int m = a.size(); // text
  std::string s = b + '#' + a;
  std::vector<int> p = pi(s);
  std::vector<int> ans;
  //std::cout << p << '\n' << n << '\n';
  for (int i = n + 1; i < s.size(); i++) {
    if (p[i] == n) {
      ans.push_back(i - 2 * n + 1);
    }
  }
  std::cout << ans.size() << '\n' << ans;
}