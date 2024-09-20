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
  int n = 0;
  std::cin >> t;
  std::cin >> n;

  t = '\0' + t;
  pref.resize(t.size());
  //pref[0] = 0;
  for (size_t i = 1; i < t.size(); ++i)
  {
    pref[i] = (pref[i - 1] * base[1] + t[i]) % MOD;
  }

  int count = 0;
  std::vector<int> pos;

  for (int64_t i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (get_hash(x1, y1) == get_hash(x2, y2)) {
      std::cout << "Yes" << std::endl;
    }
    else {
      std::cout << "No" << std::endl;
    }
  }

}