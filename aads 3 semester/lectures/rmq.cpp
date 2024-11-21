#include <iostream>
#include <vector>

//поиск суммы

struct FOO {
  int size = 320;
  std::vector<int>v;
  std::vector<int>b;
  FOO(const std::vector<int>& arr) {
    v = arr;
    b = std::vector<int>(arr.size() / size + 2);
    for (size_t i = 0; i < arr.size(); ++i) {
      b[i / size] += arr[i];
    }
  }
  int get_sum(int left, int right) {
    int sum = 0;
    while (left <= right) {
      if (left % size == 0 && left/size != right/size) {
        sum += b[left / size];
        left += size;
      }
      else {
        sum += v[left];
        ++left;
      }
    }
    return sum;
  }


};

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int>v(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> v[i];
    v[i] = (v[i] != 0);
  }
  FOO f(v);
  int k = 0;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    int left = 0;
    int right = 0;
    std::cin >> left >> right;
    std::cout << f.get_sum(left - 1, right - 1) << ' ';
  }
  return 0;
}
