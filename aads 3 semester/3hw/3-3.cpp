#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>

int main() {
  setlocale(LC_ALL, "Russian");

  int n = 8;

  std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
  std::vector<double> b = { -3075, 1919, -1656, -2439, 4, 396, -414, 5470 };

  std::vector<double> y(n);
  std::vector<double> x(n);
  
  matrix[0] = { 124, -82, -92, 3, 106, -191, -93, -188 };
  matrix[1] = { -39, -17, 78, -53, -178, 136, 140, 133 };
  matrix[2] = { 37, 37, -175, 29, -113, -38, -155, 65 };
  matrix[3] = { -24, -27, -117, 50, -52, -148, -154, 2 };
  matrix[4] = { 191, 62, 137, 20, 89, -34, -37, -98, 4 };
  matrix[5] = { 188, -159, 64, -187, -73, 108, -15, 113 };
  matrix[6] = { -169, 97, -71, 93, 91, -64, -107, 10 };
  matrix[7] = { 62, 198, -71, 172, 116, 199, 173, 194 };

  int count_f_add = 0; // счетчики
  int count_f_mul = 0;
  int count_f_div = 0;
  int count_b_add = 0;
  int count_b_mul = 0;
  int count_b_div = 0;
  int count_lu_add = 0;
  int count_lu_mul = 0;
  int count_lu_div = 0;

  int count = 0;

  for (size_t k = 0; k < n; ++k) { // lu-разложение

    for (size_t i = k; i < n; ++i) {
      for (size_t p = 0; p < k; ++p) {
        matrix[i][k] -= matrix[i][p] * matrix[p][k];
        count_lu_mul += 1;
        count_lu_add += 1;
      }
    }

    for (size_t j = k + 1; j < n; ++j) {
      matrix[k][j] = matrix[k][j];
      for (size_t p = 0; p < k; ++p) {
        matrix[k][j] -= matrix[p][j] * matrix[k][p];
        count_lu_mul += 1;
        count_lu_add += 1;
      }
      matrix[k][j] /= matrix[k][k];
      count_lu_div += 1;
    }
  }

  for (size_t i = 0; i < n; ++i) { // прямой ход
    y[i] = b[i];
    for (size_t j = 0; j < i; ++j) {
      y[i] -= matrix[i][j] * y[j];
      count_f_add += 1;
      count_f_mul += 1;
    }
    y[i] /= matrix[i][i];
    count_f_div += 1;
  } 

  
  for (int i = n-1; i >= 0; --i) { // обратный ход
    x[i] = y[i];
    for (size_t j = n-1; j > i; j--) {
      if (i == j) {
        x[i] -= x[j];
        count_b_add += 1;
      }
      else {
        x[i] -= matrix[i][j] * x[j];
        count_b_add += 1;
        count_b_mul += 1;
      }
    }
  }
  count = count_lu_mul + count_lu_add + count_lu_div + count_f_mul + count_f_add + count_f_div + count_b_mul + count_b_add + count_b_div;
  
  std::cout << "Решение: { ";
  for (int i = 0; i < 8; i++) {
    std::cout << std::setprecision(5) << x[i] << ' ';
  }
  std::cout << "}" << std::endl;
  std::cout << "||x - x*|| = ";
  double c = 0;
  for (int i = 0; i < 8; i++) {
    c += (x[i] - i - 1) * (x[i] - i - 1);
  }
  std::cout << std::pow(c, 0.5) << std::endl;
  std::cout << "LU-разложение: " << count_lu_add << " сложений " << count_lu_mul << " умножений " << count_lu_div << " делений Всего: " << count_lu_mul + count_lu_div + count_lu_add << std::endl;
  std::cout << "Прямой ход: " << count_f_add << " сложений " << count_f_mul << " умножений " << count_f_div << " делений Всего: " << count_f_mul + count_f_div + count_f_add << std::endl;
  std::cout << "Обратный ход: " << count_b_add << " сложений " << count_b_mul << " умножений " << count_b_div << " делений Всего: " << count_b_mul + count_b_div + count_b_add << std::endl;
  std::cout << "Всего: " << count_lu_add + count_f_add + count_b_add << " сложений " << count_lu_mul + count_f_mul + count_b_mul << " умножений " << count_lu_div + count_f_div + count_b_div << " делений Всего: "<<count;
  return 0;
}