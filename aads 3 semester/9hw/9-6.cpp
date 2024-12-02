#include <iostream>
#include <vector>

//поиск суммы

struct FOO {
  long long size = 320;
  std::vector<long long>v;
  std::vector<long long>b;
  FOO(std::vector <long long> arr) {
    v = arr;
    b = std::vector<long long>(v.size() / size + 2, 0);
  }
  long long sum(long long left, long long right) {
    long long sum = 0;
    while (left <= right) {
      if (left % size == 0 && left / size != right / size) {
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

  void set(long long num) {
    v[num] = num;
    b[num / size] += num;
  }


};

int main() {
  long long n = 0;
  std::cin >> n;
  std::vector<long long> v(5, 0);
  FOO f(v);
  std::string command;
  long long mem = 0;
  bool flag = false;
  long long l = 0;
  long long r = 0;
  for (long long i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "?") {
      std::cin >> l >> r;
      mem = f.sum(l + 1, r + 1);
      flag = true;
      std::cout << mem << '\n';
    }
    else {
      std::cin >> l;
      long long a = 0;
      if (flag == false) {
        a = l;
      }
      else {
        a = l + mem;
      }
      if (a > v.size()) {
        v.resize(a + 1);
      }
      f.set(a);
      flag = false;
    }
  }
  return 0;
}
