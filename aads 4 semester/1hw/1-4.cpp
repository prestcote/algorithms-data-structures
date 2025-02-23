#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

unsigned int cur = 0;
unsigned int a, b;

unsigned int nextRand24() {
  cur = cur * a + b;
  return cur >> 8;
}

unsigned long long invertions(std::vector<unsigned int>& vec, unsigned int left, unsigned int right) {
  unsigned long long res = 0;
  if (left < right) {
    unsigned long long mid = left + (right - left) / 2;
    res += invertions(vec, left, mid);
    res += invertions(vec, mid + 1, right);
    std::vector<unsigned long long> left_part(mid - left + 1);
    std::vector<unsigned long long>right_part(right - mid);
    for (unsigned long long i = 0; i < (mid - left + 1); i++) {
      left_part[i] = vec[i + left];
    }
    for (unsigned long long j = 0; j < right - mid; j++) {
      right_part[j] = vec[mid + 1 + j];
    }
    unsigned long long i = 0;
    unsigned long long j = 0;
    unsigned long long k = left;
    while (i < mid - left + 1 && j < right - mid) {
      //std::cout << k << ' ' << i << ' ' << j;
      if (left_part[i] <= right_part[j]) {
        vec[k++] = left_part[i++];
        //1
        //std::cout << " 1 "<< '\n';
      }
      else {
        vec[k++] = right_part[j++];
        //2
        //std::cout << " 2 "<< '\n';
        res += (mid - left + 1 - i);
      }
    }
    while (i < mid - left + 1) {
      vec[k++] = left_part[i++];
    }
    while (j < right - mid) {
      vec[k++] = right_part[j++];
    }
  }
  return res;
}

int main() {
  unsigned int n = 0;
  unsigned int m = 0;
  std::cin >> n >> m >> a >> b;
  std::vector<unsigned int> vec(n);
  unsigned int x = 0;
  for (unsigned int i = 0; i < n; i++) {
    x = nextRand24() % m;
    vec[i] = x;
  }
  std::cout << invertions(vec, 0, n - 1);
  return 0;
}