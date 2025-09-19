#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

long long a = 131;
long long m = 1e9 + 7;

int main() {
  std::string s; // строка
  std::cin >> s;
  int n = s.size();
  std::vector<long long> H(n + 1, 0);
  std::vector<long long> P(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    H[i] = (H[i - 1] * a + s[i - 1]) % m;
    P[i] = (P[i - 1] * a) % m;
  }
  std::cout << "checkpoint 1\n";
  std::unordered_map < long long, std::pair<std::string, std::vector<long long>>> map;
  std::unordered_map<std::string, long long> words;
  for (int l = 1; l < s.size(); l++) {
    for (int i = 0; i < s.size() - l + 1; i++) {
      long long h = (H[i + l - 1] - (H[i - 1] * P[l])) % m;
      if (map[h].second.empty()) {
        map[h].first = s.substr(i, l);
      }
      map[h].second.push_back(i);
    }
  }
  for (int i = 0; i < map.size(); i++) {
    if (map[i].second.size() > 1) {
      std::cout << map[i].first << ' ';
      for (int j = 0; j < map[i].second.size(); j++) {
        std::cout << map[i].second[j] << ' ';
      }
      std::cout << '\n';
    }
    
  }

}
