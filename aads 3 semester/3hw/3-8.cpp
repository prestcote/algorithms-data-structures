#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <set>
const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);
std::vector <int64_t> pref;

int pref_func(std::string s) {
  std::vector<int> p(s.size());
  int maxx = 0;
  for (int i = 1; i < s.size(); ++i) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    p[i] = j;
    //std::cout << j << ' ';
    maxx = std::max(maxx, j); 
  }
  //std::cout << maxx << std::endl;
  return s.size() - maxx;
}

int prefix_function(std::string s) {
  int max = 0;
  int n = (int)s.length();
  std::vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])  ++j;
    pi[i] = j;
    if (j > max) {
      max = j;
    }
  }
  return max;
}

int main() {
  //int pref = pref_func("abcabcd");
  //std::cout << pref;
  std::string s;
  std::set<std::string> sett;
  std::cin >> s;
  int ans = 0;
  for (int i = 1; i <= s.size(); i++) {
    std::string str = s.substr(0, i);
    sett.insert(str);
    std::cout << str << ' ';
    ans += (str.size() + 1 - prefix_function(str));
  }
  std::cout << ans << ' ' << sett.size();
}