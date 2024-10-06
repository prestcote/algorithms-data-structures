#include<iostream>
#include<string>
#include<vector>
#include <set>

const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);

int64_t get_hash(size_t left, size_t right, std::vector <int> pref)
{
  int64_t h = pref[right] - pref[left - 1] * base[right - left + 1];
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
  std::vector <int> pref;
  int n = 0;
  int m = 0;
  int k = 0;
  std::cin >> n >> m >> k;
  std::string s;
  std::vector<std::vector<int>> hash_table(n, std::vector<int>(m));
  for (int j = 0; j < n; j++) {
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
  
  std::set<std::vector<int>> ans;
  for (int i = 0; i < n-k+1; i++) {
    for (int j = 0; j < m - k + 1; j++) {
      std::vector<int> hash;
      for (int k_ = 0; k_ < k; k_++) {
        hash.push_back(get_hash(j+1, j + k_ + 1, hash_table[i + k_]));
      }
      ans.insert(hash);
    }
  }
  
  std::cout << ans.size();
}