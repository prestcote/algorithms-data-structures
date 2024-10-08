#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <set>
#include <unordered_set>
const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);
std::vector <int64_t> pref;

int64_t get_hash(size_t left, size_t right)
{
  int64_t h = pref[right] - pref[left - 1] * base[right - left + 1];
  h = (h % MOD + MOD) % MOD;
  return h;
}

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();

  base[0] = 1;
  for (size_t i = 1; i < n; i++)
    base[i] = (base[i - 1] * 263) % MOD;

  pref.resize(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; i++)
    pref[i + 1] = (pref[i] + (s[i] - 'a' + 1) * base[i]) % MOD;

  int ans = 0;
  for (int l = 1; l <= n; l++) {
    std::set<long long> hash;
    for (int i = 0; i <= n - l; i++) {
      //long long h = get_hash(i+1, i + l+1);
      long long h = (pref[i + l] + MOD - pref[i]) % MOD;
      h = (h * base[n - i - 1]) % MOD;
      hash.insert(h);
    }
    ans += hash.size();
  }
  
  std::cout << ans;
}