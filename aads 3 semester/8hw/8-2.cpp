//метод отжига: задача 3088 на информатиксе

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

std::mt19937_64 rd(time(0));

bool p(double t, int df) {
  return std::exp(df / t) > ((double)rd() / UINT64_MAX);
}

int main() {
  size_t n = 0;
  int m = 0;
  std::cin >> m >> n;
  std::vector<int> v(n);
  std::vector<int> mask(n);
  for (auto& el : v) {
    std::cin >> el;
  }
  int mx = 0;
  double t = 100000;
  int cnt = 0;
  int cur_weight = 0;
  while (t > 0.0001) {
    t = t * 0.999995;
    cnt++;
    mx = std::max(mx, cur_weight);
    size_t index = rd() % n;
    if (mask[index] == 0 && cur_weight + v[index] == m) {
      std::cout << m;
      return 0;
    }
    if (mask[index] == 0 && cur_weight + v[index] < m) {
      mask[index] = 1;
      cur_weight += v[index];
      continue;
    }
    if (mask[index] == 1 && p(t, -v[index])) {
      mask[index] = 0;
      cur_weight -= v[index];
    }
  }
  //std::cout << cnt << '\n';
  std::cout << mx;
  return 0;
}

