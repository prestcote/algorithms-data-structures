#include <iostream>  
#include <vector>
#include <random>   
#include <ctime> 

int n = 0;
int m = 0;
int c = 0;

std::mt19937_64 rd(time(0));

bool p(double df, double t) {
  return std::exp(df / t) > double(rd() / UINT64_MAX);
}

int rectangleCounter(int x, int y, std::vector<std::vector<int>> v) {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int height = 1; height < n - i; ++height) {
        for (int width = 1; width < m - j; ++width) {
          if (v[i][j] == v[i + height][j] && v[i][j] == v[i][j + width] && v[i][j] == v[i + height][j + width]) {
            if ((i == x && j == y) || (i + height == x && j == y) || (i == x && j + width == y) || (i + height == x && j + width == y)) {
              ++count;
            }
          }
        }
      }
    }
  }
  return count;
}


int main() {
  std::cin >> n >> m >> c;

  std::vector<std::vector<int>> table(n, std::vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      table[i][j] = rd() % c + 1;
    }
  }


  double temp = 1e2;

  while (temp > 1e-20) {

    temp *= 0.9994;
    int index_row = rd() % n;
    int index_column = rd() % m;
    int cur = rectangleCounter(index_row, index_column, table);
    int cell_color = table[index_row][index_column];
    int new_color = rd() % c + 1;
    table[index_row][index_column] = new_color;
    int next = rectangleCounter(index_row, index_column, table);

    if (next < cur || p(-std::abs(cur - next), temp)) {
      table[index_row][index_column] = new_color;
      cur = next;
    }
    else {
      table[index_row][index_column] = cell_color;
    }
  }


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << table[i][j] << ' ';
    }
    std::cout << '\n';
  }

}