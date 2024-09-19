#include<iostream>
#include<string>
#include<vector>
const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);
std::vector <int64_t> pref;
int64_t get_hash(const std::string& s)
{
  int64_t h = 0;
  for (const auto& to : s)
  {
    h = (h * base[1] + to) % MOD;
  }
  return h;
}
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

  std::string t;
  std::string s;
  std::cin >> t >> s;

  //std::string t = "abacaba";
  t = '\0' + t;
  pref.resize(t.size());
  //pref[0] = 0;
  for (size_t i = 1; i < t.size(); ++i)
  {
    pref[i] = (pref[i - 1] * base[1] + t[i]) % MOD;
  }
  //std::cout << get_hash(1, 3) << " " << get_hash(5, 7);

  int64_t find = get_hash(s);
  //std::cout << find << '\n';

  int64_t length = s.size();
  for (int64_t i = 1; i < t.size() - length + 1; i++) {
    int64_t h = get_hash(i, i + length - 1);
    //std::cout << h << ' ';
    if (h == find) {
      std::cout << i-1 << ' ';
    }
  }

}