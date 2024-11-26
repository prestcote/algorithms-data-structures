#include <iostream>
#include<vector>
#include <random>
#include <algorithm>

std::mt19937_64 rd(time(0));

bool p(int t, int df) {
  return std::exp(df / t) > ((double)rd() / UINT64_MAX);
}

int func(std::vector<std::vector<int>> mx, int n, int m) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < m; k++) {
        for (int l = k + 1; l < m; l++) {
          if (mx[i][k] == mx[i][l] && mx[i][k] == mx[j][k] && mx[i][k] == mx[j][l]) {
            count += 1;
          }
        }
      }
    }
  }
  return count;
}
//2
int main() {
  int n = 0;
  int m = 0;
  int c = 0;
  std::cin >> n >> m >> c;
  std::vector<std::vector<int>> mx(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mx[i][j] = rd() % c;
    }
  }
  /*
    if (func(mx, n, m) == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          std::cout << mx[i][j] + 1 << ' ';
        }
        std::cout << std::endl;
      }
      //std::cout << "YASSSS";
      return 0;
    }
    */
  double t = 1000;
  while (t > 1) {

    t *= 0.999992;
    int y = rd() % n;
    int x = rd() % m;
    int new_c = rd() % c;
    int old_c = mx[y][x];
    if (old_c != new_c) {
      int cur = func(mx, n, m);
      mx[y][x] = new_c;
      int fut = func(mx, n, m);
      if (!(fut <= cur || p(t, (cur - fut)))) {
        mx[y][x] = old_c;
      }
      if (fut == 0) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            std::cout << mx[i][j] + 1 << ' ';
          }
          std::cout << std::endl;
        }
        //std::cout << "YEE HAW";
        return 0;
      }
    }

  }
  return 0;
}