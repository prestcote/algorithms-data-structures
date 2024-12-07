#include <iostream>
#include <vector>

long long size = 100000;

struct FOO {
  //long long size = 100000;
  std::vector <std::vector<long long>> v;
  std::vector<long long>b;
  FOO(long long n) {
    v = std::vector <std::vector<long long>>(100000, std::vector<long long> (100000, 0));
    b = std::vector<long long>(v.size() / size + 2, 0);
    long long el = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> el;
      bool f = true;
      if (v[el / size][el % size] != 0) {
        b[i / size] += el;
        v[el / size][el % size] = 1;
      }
    }
    std::cout << '\n';
    for (int i = 0; i < 1; i++) {
      std::cout << v[0][i] << ' ';
    }
  }
  long long sum(long long left, long long right) {

    long long sum = 0;
    int nom = left / size;
    for (long long i = left % size; i < v[nom].size(); i++) {
      if (v[nom][i] == 1) {
        sum += nom * size + i;
      }
    }
    if (right / size != nom) {
      nom = right / size;
      for (long long i = 0; i < right / size; i++) {
        if (v[nom][i] == 1) {
          sum += nom * size + i;
        }
      }
      for (int i = left / size + 1; i < nom; ++i)
        sum += b[i];
    }
    return sum;
  }

  void set(long long num) {
    long long index = num / size;
    if (v[num / size][num % size] != 1) {
      b[num / size] += num;
      v[num / size][num % size] = 1;
    }
  }


};

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  long long n = 0;
  std::cin >> n;
  long long el = 0;
  long long index = 0;
  
  FOO f(n);
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
      f.set(a);
      flag = false;
    }
  }
  return 0;
}
