//метод отжига: задача 1120 на информатиксе

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

std::mt19937_64 rd(time(0));

bool p(double t, int df) {
  return std::exp(df / t) > (double)rd() / UINT64_MAX;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> v(n);
  std::vector<int> mask(n);
  for (auto& el : v) {
    std::cin >> el;
  }
  double t = 100;
  //int cnt = 0;
  int cur_weight = 0;
  while (t > 0.0001) {
    t = t * 0.999995;
    size_t index = rd() % n;
    if (mask[index] == 0 && cur_weight + v[index] == m) {
      std::cout << "YES";
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
    //cnt++;
  }
  std::cout << "NO";
  return 0;
}

