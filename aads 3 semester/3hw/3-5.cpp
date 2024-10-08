#include <iostream>
#include<string>
#include<vector>
const int64_t MOD = 1e9 + 9;
const int64_t N = 1e5 + 1;
std::vector <int64_t> base(N);
//std::vector <int64_t> pref;

int64_t get_hash(size_t left, size_t right, std::vector<int64_t> pref)
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
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int64_t>> list (n);
  std::string t;
  std::vector <int64_t> pref;
  for (int i = 0; i < n; i++) {
    std::cin >> t;
    pref.resize(t.size());
    //pref[0] = 0;
    for (size_t i = 1; i < t.size(); ++i)
    {
      pref[i] = (pref[i - 1] * base[1] + t[i]) % MOD;
    }
    list[i] = pref;
    pref.clear();
  }
  int l = 0;
  std::cin >> l;
  int pos = 0;
  std::cin >> pos;
  int max = 1;
  //int h = get_hash(1, list[pos-1].size() - 1, list[pos-1]);
  int size_ = list[pos - 1].size();
  int h = list[pos - 1][size_ - 1];;
  int temp = 1;
  int start_ans = 0; 
  int end_ans = 0;
  int end = 0;
  for (int i = 1; i < l; i++) {
    std::cin >> pos;
    //std::cout << list[pos - 1].size() << ' ' << size_;
    if (list[pos-1].size() > size_) {

      //int temp_hash = get_hash(1, size_-1, list[pos-1]);
      int temp_hash = list[pos - 1][size_ - 1];
      if (h == temp_hash) {
        temp += 1;
        if (max < temp) {
          max = temp;
          end_ans = i;
          start_ans = i - temp + 1;
        }
      }
      else {
        temp = 1;
      }
      //h = list[pos - 1].back();
      int end = list[pos - 1].size() - 1;
      h = list[pos - 1][end];
      
    }
    else {
      temp = 1;
      //h = list[pos - 1].back();
      int end = list[pos - 1].size() - 1;
      h = list[pos - 1][end];
    }
    size_ = list[pos-1].size();
    
  }
  std::cout << max << ' ' << start_ans+1 << ' ' << end_ans+1;
}