#include<iostream>
#include<string>
#include<vector>
#include <set>

const int64_t MOD = 1e12 + 1;
const int64_t N = 1e5 + 1;
std::vector <long long> base(N);

int64_t get_hash(size_t left, size_t right, std::vector <long long> pref)
{
  long long h = pref[right] - pref[left - 1] * base[right - left + 1];
  h = (h % MOD + MOD) % MOD;
  return h;
}

int main() {
  base[0] = 1;
  for (size_t i = 1; i < N; ++i)
  {
    base[i] = base[i - 1] * 257 % MOD;
  }
  std::string t;
  std::vector <long long> pref;
  int n = 0;
  int m = 0;
  int k = 0;
  std::cin >> n >> m >> k;
  std::string s;
  std::vector<std::vector<long long>> hash_table(n, std::vector<long long>(m));
  for (size_t j = 0; j < n; j++) {
    std::cin >> t;
    t = '\0' + t;
    pref.resize(t.size());
    for (size_t i = 1; i < t.size(); ++i)
    {
      pref[i] = (pref[i - 1] * base[1] + t[i]) % MOD;
    }

    hash_table[j] = pref;
    pref.clear();
  }

  std::set<std::vector<long long>> ans;
  for (size_t i = 0; i < n - k + 1; i++) {
    for (size_t j = 0; j < m - k + 1; j++) {
      std::vector<long long> hash;
      for (long long k_ = 0; k_ < k; k_++) {
        hash.push_back(get_hash(j + 1, j + k_ + 1, hash_table[i + k_]));
      }
      ans.insert(hash);
    }
  }

  std::cout << ans.size();
}