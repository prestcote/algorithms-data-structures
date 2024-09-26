#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);
std::vector <int64_t> pref;

int main() {
  std::string str;
  std::cin >> str;
  std::vector<int> prefix(1 + str.size());
  int sum = 0;
  int it = 0;
  for (int i = 0; i < str.size(); i++) {
    prefix[1] = 0;
    int len = 0;
    int max = 0;
    for (int i = 1; i < str.size(); i++) {
      while (str[len] != str[i]) {
        if (len == 0) {
          break;
        }
        len = prefix[len];
      }
      len += 1;
      prefix[i + 1] = len;
      max = std::max(max, len);
    }
    sum += str.size() - max;
    str.erase(str.begin());
  }
  std::cout << sum;
}