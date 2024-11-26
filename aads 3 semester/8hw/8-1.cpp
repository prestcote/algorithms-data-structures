//камни

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

std::mt19937_64 rd(time(0));

bool p(double t, int df) {
  return std::exp(df / t) > ((double)rd() / UINT64_MAX);
}

int heapsDelta(std::vector<int>mask, std::vector<double> rocks) {
  double one = 0;
  double two = 0;
  for (size_t i = 0; i < mask.size(); i++) {
    if (mask[i] = 0) {
      one += rocks[i];
    }
    else {
      two += rocks[i];
    }
  }
  if (one > two) {
    return one - two;
  }
  else {
    return two - one;
  }
}

int countRocks(std::vector<int> mask) {
  int count = 0;
  for (size_t i = 0; i < mask.size(); i++) {
    if (mask[i] = 0) {
      count += 1;
    }
  }
  return count;
}

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<double> rocks(n);
  std::vector<int> mask(n);
  int max_weight = 0;
  for (auto& el : rocks) {
    std::cin >> el;
    max_weight += el;
  }
  double min = 100000000000;
  double t = 1e20;
  int cnt = 0;
  double sum = 0;
  while (t > 0.000001) {
    t = t * 0.9999;
    //min = std::min(min, delta);
    size_t index = rd() % n;
    if (mask[index] == 0 && p(t, -rocks[index])) {
      mask[index] = 1;
      sum += rocks[index];
      cnt += 1;
      //if (sum != max_weight) {
        //min = std::min(min, std::abs(max_weight - 2 * sum));
      //}
      continue;
    }
    if (mask[index] == 1 && p(t, -rocks[index])) {
      cnt -= 1;
      mask[index] = 0;
      sum -= rocks[index];
      //if (cnt > 0) {
      //  min = std::min(min, std::abs(max_weight - sum * 2));
      //}
    }
    min = std::min(min, std::abs(max_weight - sum * 2));
  }
  std::cout << cnt << ' ' << min << ' ';
  return 0;
}

