#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<long long> base(16);
long long p = 1000000007;
long long x = 263;
long long m = 100000;

long long get_hash(std::string str, long long m) {
  long long h = 0;
  long long t = 0;
  for (int64_t i = 0; i < str.size(); i++) {
    t = ((str[i] % p) * (base[i] % p)) % p;
    h = (h + t) % p;
  }
  return h % m;
}

int main() {
  std::set <std::string> words;
  std::string word;
  int n = 0;
  //std::cin >> str >> n;
  base[0] = 1;
  for (int i = 0; i < base.size(); i++) {
    base[i] = base[i - 1] * 257 % 263;
  }
  int count = 0;

  for (int i = 0; i < word.size(); i++) {

  }
}