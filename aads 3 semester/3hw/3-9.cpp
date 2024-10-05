#include<iostream>
#include<string>
#include<vector>

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
  base[0] = 1;
  for (size_t i = 1; i < N; ++i)
  {
    base[i] = base[i - 1] * 257 % MOD;
  }
  std::string t = "abacaba";
  t = '\0' + t;
  pref.resize(t.size());
  for (size_t i = 1; i < t.size(); ++i)
  {
    pref[i] = (pref[i - 1] * base[1] + t[i]) % MOD;
  }

  int n = 0;
  int m = 0;
  int k = 0;
  std::cin >> n >> m >> k;
  std::string s;
  std::vector<std::vector<int>> hash_table(n, std::vector<int>(m));
}