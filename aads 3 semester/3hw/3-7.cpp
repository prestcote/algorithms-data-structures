#include <iostream>
#include <vector>
#include <string>
#include <set>

const int64_t N = 1e5 + 1;
std::vector<int64_t>base(N);
std::vector<int64_t> pref;
const int64_t MOD = 1e9 + 1;
const int64_t base_ = 257;
int64_t min_hash = 1e9 + 2;
int64_t find_hash = 1e9 + 3;

int64_t get_hash(const std::string& s)
{
  int64_t h = 0;
  for (const auto& to : s)
  {
    h = (h * 257 + to) % MOD;
  }
  return h;
}

std::set<std::string> func(std::string str, int n) {
  std::set<std::string> s;
  int a = 0;
  for (int i = 0; i < str.size(); i++) {
    std::string head = str.substr(i) + str.substr(0, i);
    a = get_hash(head);
    if (a < min_hash) {
      min_hash = a;
    }
    if (a < min_hash + n) {
      s.insert(head);
    }
  }
  return s;
}


int main() {
  std::set <std::string> words;
  std::string str;
  int n = 0;
  std::cin >> str >> n;
  /*
  base[0] = 1;
  for (int i = 0; i < base.size(); i++) {
    base[i] = base[i - 1] * 257 % MOD;
  }
  */
  std::set<std::string> sett = func(str, n);
  int count = 0;
  if (n > sett.size()) {
    std::cout << "IMPOSSIBLE";
  }
  else {
    for (std::string i : sett) {
      //std::cout << i << ' ';
      count += 1;
      if (count == n) {
        std::cout << i << std::endl;
        break;
      }
    }

  }

}