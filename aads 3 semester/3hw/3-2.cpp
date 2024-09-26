#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<int64_t> base(16);
int64_t p = 1000000007;
int64_t x = 263;


int64_t get_hash(std::string str, int m) {
  int h = 0;
  for (int64_t i = 0; i < str.size(); i++) {
    h += ((str[i] % p) * base[i]) % m;
  }
  return h;
}

int main() {
  base[0]  = 1;
  int x = 263;
  for (int i = 1; i < 16; i++) {
    base[i] = (base[i - 1] * 263) % p;
  }

  int m = 0;
  std::cin >> m;
  int n = 0;
  std::cin >> n;
  std::cout << get_hash("HellO", m);
  std::vector<std::vector<std::string>> table(m+1);
  std::string comm;
  std::string word;
  int check = 0;
  int hash = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> comm;
    if (comm == "add") {
      std::cin >> word;
      hash = get_hash(word, m);
      table[hash].push_back(word);
    }
    else if (comm == "del") {
      std::cin >> word;
      int c = get_hash(word, m);
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
      int h = get_hash(word, m);
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