#include <iostream>
#include <vector>
#include <locale.h>


int main() {
  setlocale(LC_ALL, "Russian");

  std::vector<std::vector<double>> matrix(8, std::vector<double>(9));
  
  matrix[0] = { 28, -1,	0, 0, 0, 0,	0,	0, 26 };
  matrix[1] = { -24,	66,	24,	0,	0,	0,	0,	0, 180 };
  matrix[2] = { 0,	20, -15,	38, 0,	0,	0,	0, 147 };
  matrix[3] = { 0,	0, -71,	73, -17,	0,	0,	0, -6 };
  matrix[4] = { 0,	0,	0,	3,	65, -44,	0,	0, 73 };
  matrix[5] = { 0,	0,	0,	0,	2, -16, -3,	0, -107 };
  matrix[6] = { 0,	0,	0,	0,	0,	93,	100, -43, 914 };
  matrix[7] = { 0,	0, 0,	0,	0,	0,	60, -100, -380 };

  int count_f_add = 0; // счетчики
  int count_f_mul = 0;
  int count_f_div = 0;
  int count_b_add = 0;
  int count_b_mul = 0;
  int count_b_div = 0;

  std::vector<double> p(8);
  std::vector<double> q(8);
  
  // пр€мой ход
  p[0] = (-matrix[0][1]) / matrix[0][0];  
  q[0] = matrix[0][8] / matrix[0][0];
  //а=0 => на 4 операции (2 сложени€ и 2 умножени€) меньше
  count_f_div += 2;
  for (int i = 1; i < 7; i++) {
    double division = (matrix[i][i] + matrix[i][i - 1] * p[i - 1]);
    p[i] = (-matrix[i][i + 1]) / division;
    q[i] = (-(matrix[i][i - 1] * q[i-1]) + matrix[i][8]) / division;
    count_f_mul += 2;
    count_f_add += 2;
    count_f_div += 2;
  }
  p[7] = 0; //c = 0 => на 1 операцию делени€ меньше
  q[7] = (-(matrix[7][6] * q[6]) + matrix[7][8]) / (matrix[7][7] + matrix[7][6] * p[6]);
  count_f_add += 2;
  count_f_mul += 2;
  count_f_div += 1;

  // обратный ход
  std::vector<double> x(8);
  // Xn+1 = 0 => Xn = q => на две операции (сложение и умножение меньше)
  x[7] = q[7]; // минус две операции
  for (int i = 6; i >= 0; i--) {
    x[i] = p[i] * x[i + 1] + q[i];
    count_b_mul += 1;
    count_b_add += 1;
  }
  std::cout << "–ешение: { ";
  for (int i = 0; i < 8; i++) {
    std::cout << x[i] << ' ';
  }
  std::cout << "}" << std::endl;
  std::cout << "ѕр€мой ход: " << count_f_add << " сложений " << count_f_mul << " умножений " << count_f_div << " делений ¬сего: " << count_f_mul + count_f_div + count_f_add << std::endl;
  std::cout << "ќбратный ход: " << count_b_add << " сложений " << count_b_mul << " умножений " << count_b_div << " делений ¬сего: " << count_b_mul + count_b_div + count_b_add;
  return 0;
}