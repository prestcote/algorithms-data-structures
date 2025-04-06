#include <iostream>
#include <vector>
#include <string>


int main() {
  std::string s;
  std::cin >> s;
  long long n = s.size();

  std::vector<long long> d1(n);
  std::vector<long long> d2(n);
  long long left1 = 0;
  long long right1 = -1;
  long long left2 = 0;
  long long right2 = -1;
  long long k1 = 0;
  long long k2 = 0;
  for (long long i = 0; i < n; ++i) {
    if (i > right1) {
      k1 = 1;
    }
    else {
      k1 = std::min(d1[left1 + right1 - i], right1 - i + 1);
    }
    if (i > right2) {
      k2 = 0;
    }
    else {
      k2 = std::min(d2[left2 + right2 - i + 1], right2 - i + 1);
    }
    while (i + k1 < n && i - k1 >= 0 && s[i + k1] == s[i - k1]) {
      k1 += 1;
    } 
    while (i + k2 < n && i - k2 - 1 >= 0 && s[i + k2] == s[i - k2 - 1]) {
      k2 += 1;
    }
    d1[i] = k1;
    d2[i] = k2;
    if (i + k1 - 1 > right1) {
      left1 = i - k1 + 1;
      right1 = i + k1 - 1;
    }
    if (i + k2 - 1 > right2)
      left2 = i - k2;
      right2 = i + k2 - 1;
  }
  
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    count += d1[i];
    count += d2[i];
  }
  std::cout << count;
}

