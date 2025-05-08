#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

const long long nbase = 1e7 + 1;
const long long mod = 1e9 + 7;
const long long nbase2 = 1e7 + 3;
const long long mod2 = 1e9 + 9;

std::vector<long long> pref;
std::vector<long long> base;
std::vector<long long> pref2;
std::vector<long long> base2;

long long get_hash(size_t left, size_t right) {
  long long h = pref[right] - pref[left] * base[right - left];
  h = (h % mod + mod) % mod;
  return h;
}

long long get_hash2(size_t left, size_t right) {
  long long h = pref2[right] - pref2[left] * base2[right - left];
  h = (h % mod2 + mod2) % mod2;
  return h;
}

int main() {
  std::string s;
  std::cin >> s;
  long long n = s.size();
  pref.resize(n + 1);
  base.resize(n + 1);
  base[0] = 1;
  pref[0] = 0;
  pref2.resize(n + 1);
  base2.resize(n + 1);
  base2[0] = 1;
  pref2[0] = 0;
  for (size_t i = 0; i < n; i++) {
    base[i + 1] = (base[i] * nbase) % mod;
    pref[i + 1] = (pref[i] * nbase + s[i]) % mod;
    base2[i + 1] = (base2[i] * nbase2) % mod2;
    pref2[i + 1] = (pref2[i] * nbase2 + s[i]) % mod2;
  }
  std::unordered_set<long long>ans;
  for (size_t i = 1; i <= n; i++) {
    std::unordered_map<long long, std::vector<long long>> hash;
    for (size_t j = 0; j + i <= n; j++) {
      long long h = get_hash(j, j + i);
      long long h2 = get_hash2(j, j + i);
      hash[h * mod2 + h2].push_back(j);
    }
    for (const auto& [k, pos] : hash) {
      if (pos.size() < 2) continue;
      long long last_pos = pos[0];
      for (size_t a = 1; a < pos.size(); a++) {
        if (pos[a] >= last_pos + i) {
          ans.insert(k);
          //flag = true;
          break;

        }
        last_pos = std::min(last_pos, pos[a]);
      }
    }
  }

  std::cout << ans.size();
  return 0;
}