#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<long long> base(16);
long long p = 1000000007;
long long x = 263;


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
  base[0]  = 1;
  long long x = 263;
  for (int i = 1; i < 16; i++) {
    base[i] = (base[i - 1] * 263) % p;
  }

  long long m = 0;
  std::cin >> m;
  long long n = 0;
  std::cin >> n;
  //std::cout << get_hash("HellO", m);
  std::vector<std::vector<std::string>> table(m+1);
  std::string comm;
  std::string word;
  long long check = 0;
  long long hash = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> comm;
    if (comm == "add") {
      std::cin >> word;
      hash = get_hash(word, m);
      if (std::find(table[hash].begin(), table[hash].end(), word) == table[hash].end()) {
        table[hash].push_back(word);
      }
    }
    else if (comm == "del") {
      std::cin >> word;
      long long c = get_hash(word, m);
      if (!table[c].empty()) {
        for (int i = 0; i < table[c].size(); i++) {
          if (table[c][i] == word) {
            table[c].erase(table[c].begin() + i);
          }
        }
      }
    }
    else if (comm == "find") {
      std::cin >> word;
      long long h = get_hash(word, m);
      bool f = false;
      if (!table[h].empty()) {
        for (int i = 0; i < table[h].size(); i++) {
          if (table[h][i] == word) {
            f = true;
          }
        }
      }
      if (f == true) {
        std::cout << "yes" << std::endl;
      }
      else {
        std::cout << "no" << std::endl;
      }
    }
    else if (comm == "check") {
      std::cin >> check;
      if (!table[check].empty()) {
        for (int i = table[check].size() - 1; i >= 0; i--) {
          std::cout << table[check][i] << ' ';
        }
      }
      std::cout << std::endl;
    }
    
  }

}