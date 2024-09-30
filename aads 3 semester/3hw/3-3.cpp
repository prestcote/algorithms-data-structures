#include <iostream>
#include <vector>
#include <locale.h>

void printMatrix(std::vector<std::vector<double>> vec) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 9; j++) {
      std::cout << vec[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void sol(int n, std::vector<std::vector<double>> matrix, std::vector<double> ans) {
  int64_t count_f_div = 0; //счетчики
  int64_t count_f_mul = 0;
  int64_t count_f_add = 0;
  for (int64_t i = 0; i < n - 1; i++) { //начинаем прямой ход: цикл для перебора каждой "ведущую" строку 
    for (int64_t k = i + 1; k < n; k++) { //цикл для перебора каждой строки после ведущей
      double t = matrix[k][i] / matrix[i][i]; //находим соотношение, чтобы потом обнулить элемент
      count_f_div += 1;
      for (int64_t j = 0; j <= n; j++) { //цикл для перебора каждого элемента строки
        matrix[k][j] = matrix[k][j] - t * matrix[i][j]; //вычитаем из каждого элемента соотв. элемент "ведущей строки", умноженный на соотношение
        count_f_add += 1;
        count_f_mul += 1;
      }
    }
  }

  int64_t count_b_div = 0;
  int64_t count_b_mul = 0;
  int64_t count_b_add = 0;
  for (int64_t i = n - 1; i >= 0; i--) { //начинаем обратный ход, идем с последних строк матрицы
    ans[i] = matrix[i][n]; //каждый текущий ответ зависит от предыдущего
    for (int64_t j = i + 1; j < n; j++) {
      ans[i] = ans[i] - matrix[i][j] * ans[j]; //вычитаем из ответа коэффициенты, если нашли соответствущий икс
      count_b_add += 1;
      count_b_mul += 1;
    }
    ans[i] = ans[i] / matrix[i][i]; //находим икс
    count_b_div += 1;
  }

  int summ_b = count_b_add + count_b_div + count_b_mul;
  int summ_f = count_f_add + count_f_div + count_f_mul;

  std::cout << "Решение системы методом Гауccа\nрезультат { ";
  for (int64_t i = 0; i < n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << "}\n";
  std::cout << "Этап " << "Сложения " << "Умножения " << "Деления " << "Всего операций\n";
  std::cout << "Прямой ход: " << count_f_add << ' ' << count_f_mul << ' ' << count_f_div << ' ' << summ_f << '\n';
  std::cout << "Обратный ход: " << count_b_add << ' ' << count_b_mul << ' ' << count_b_div << ' ' << summ_b << '\n';
  std::cout << "Всего " << count_f_add + count_b_add << ' ' << count_f_mul + count_b_mul << ' ' << count_f_div + count_b_div << ' ' << summ_f + summ_b;
  std::cout << std::endl;
}

void sol_but_better(int n, std::vector<std::vector<double>> matrix, std::vector<double> ans) {
  int64_t count_f_div = 0; //счетчики
  int64_t count_f_mul = 0;
  int64_t count_f_add = 0;

  for (int64_t i = 0; i < n - 1; i++) { //начинаем прямой ход: цикл для перебора каждой "ведущую" строку 
    for (int64_t row = i + 1; row < n; row++) { //выбор ведущего элемента
      if (std::abs(matrix[i][i]) < std::abs(matrix[row][i])) { //в каждом столбце находим наименьший элемент
        for (int j = 0; j <= n; j++) 
        {
          double temp = matrix[i][j];
          matrix[i][j] = matrix[row][j];
          matrix[row][j] = temp;
        }
      }
    }
    for (int64_t k = i + 1; k < n; k++) { //цикл для перебора каждой строки после ведущей
      double t = matrix[k][i] / matrix[i][i]; //находим соотношение, чтобы потом обнулить элемент
      count_f_div += 1;
      for (int64_t j = 0; j <= n; j++) { //цикл для перебора каждого элемента строки
        matrix[k][j] = matrix[k][j] - t * matrix[i][j]; //вычитаем из каждого элемента соотв. элемент "ведущей строки", умноженный на соотношение
        count_f_add += 1;
        count_f_mul += 1;
      }
    }
  }

  int64_t count_b_div = 0;
  int64_t count_b_mul = 0;
  int64_t count_b_add = 0;

  for (int64_t i = n - 1; i >= 0; i--) { //начинаем обратный ход, идем с последних строк матрицы
    ans[i] = matrix[i][n]; //каждый текущий ответ зависит от предыдущего
    for (int64_t j = i + 1; j < n; j++) {
      if (j != i) { //вычитаем из ответа коэффициенты, если нашли соответствущий икс
        ans[i] = ans[i] - matrix[i][j] * ans[j];
        count_b_add += 1;
        count_b_mul += 1;
      }
    }
    ans[i] = ans[i] / matrix[i][i]; //находим икс
    count_b_div += 1;
  }

  int summ_b = count_b_add + count_b_div + count_b_mul;
  int summ_f = count_f_add + count_f_div + count_f_mul;

  std::cout << "Решение системы методом Гауccа c выбором ведущего элемента\nрезультат { ";
  for (int64_t i = 0; i < n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << "}\n";
  std::cout << "Этап " << "Сложения " << "Умножения " << "Деления " << "Всего операций\n";
  std::cout << "Прямой ход: " << count_f_add << ' ' << count_f_mul << ' ' << count_f_div << ' ' << summ_f << '\n';
  std::cout << "Обратный ход: " << count_b_add << ' ' << count_b_mul << ' ' << count_b_div << ' ' << summ_b << '\n';
  std::cout << "Всего " << count_f_add + count_b_add << ' ' << count_f_mul + count_b_mul << ' ' << count_f_div + count_b_div << ' ' << summ_f + summ_b;
  std::cout << std::endl;
}

int main() {
  setlocale(LC_ALL, "Russian");

  int n = 8;

  std::vector<std::vector<double>> matrix(8, std::vector<double>(9));
  std::vector<double> x(8);

  matrix[0] = { 124, -82, -92,3, 106, -191, - 93, - 188, -3075 };
  matrix[1] = { -39, - 17, 78, - 53, - 178, 136, 140, 133, 1919 };
  matrix[2] = { 37, 37, - 175, 29, - 113, - 38, - 155, 65, -1656};
  matrix[3] = { -24, - 27, - 117, 50, - 52, - 148, - 154, 2, -2439};
  matrix[4] = { 191, 62, 137, 20, 89, - 34, - 37, - 98, 4 };
  matrix[5] = { 188, - 159, 64, - 187, - 73, 108, - 15, 113, 396 };
  matrix[6] = { -169, 97, - 71, 93, 91, - 64, - 107, 10, -414 };
  matrix[7] = { 62, 198, - 71, 172, 116, 199, 173, 194, 5470 };

  std::cout << "Система линейных уравнений в матричном виде: \n";
  std::cout.width(10);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 9; j++) {
      if (j == 8) {
        std::cout << "| ";
      }
      std::cout.width(4);
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  sol(8, matrix, x);
  std::cout << std::endl;
  sol_but_better(8, matrix, x);
}