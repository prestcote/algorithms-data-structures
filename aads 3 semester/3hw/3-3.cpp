#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <array>

double n = 8;
using Matrix = std::array<std::array<double, 8>, 8>;
using AnswerMatrix = std::array<double, 8>;
using RateMatrix = std::array<std::array<double, 1>, 8>;

void printMatrix(const Matrix& A) {
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < A[0].size(); ++j) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

template<size_t size>
void printMatrix(const std::array<double, size>& array) {
  for (double x : array) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}


void printMatrix(std::vector<std::vector<double>> matrix) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void printVector(std::vector<double> matrix) {
  std::cout << std::endl;
  for (int j = 0; j < n; j++) {
    std::cout << matrix[j] << ' ';
  }
  std::cout << std::endl;
}

std::vector<double> sol_but_better(std::vector<std::vector<double>> matrix, std::vector<double> b) {

  for (int64_t j = 0; j < n; j++) {
    for (int64_t row = j + 1; row < n; row++) {
      if (std::abs(matrix[j][j]) < std::abs(matrix[row][j])) { 
        for (int i = 0; i < n; i++)
        {
          double temp = matrix[j][i];
          matrix[j][i] = matrix[row][i];
          matrix[row][i] = temp;
        }
        double temp_b = b[j];
        b[j] = b[row];
        b[row] = temp_b;
      }
    }
    double lambda = matrix[j][j];
    for (size_t k = j; k < matrix.size(); ++k) {
      matrix[j][k] /= lambda;
    }
    b[j] /= lambda;

    for (size_t i = j + 1; i < 8; ++i) {
      double factor = matrix[i][j];
      for (size_t k = j; k < 8; ++k) {
        matrix[i][k] -= factor * matrix[j][k];
      }
      b[i] -= factor * b[j];
    }
  }

  std::vector<double> root(8, 0);
  for (int64_t i = 7; i >= 0; --i) {
    root[i] = b[i];
    for (size_t j = i + 1; j < 8; ++j) {
      root[i] -= matrix[i][j] * root[j];
    }
  }
  return root;
}

std::vector<double> multiplyMatrices(const std::vector<std::vector<double>> A, const std::vector<double> b) {
  std::vector<double> res(8, 0);
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < b.size(); ++j) {
      res[i] += A[i][j] * b[j];
    }
  }
  return res;
} 

std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>> A, const std::vector<std::vector<double>> B) {
  std::vector<std::vector<double>> res(8, std::vector<double>(8, 0));
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < B[0].size(); ++j) {
      for (size_t k = 0; k < A[0].size(); ++k) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
  Matrix res = { 0.0 };
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < B[0].size(); ++j) {
      for (size_t k = 0; k < A[0].size(); ++k) {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}


std::vector<std::vector<double>> transposeMatrix(std::vector<std::vector<double>> A) {
  std::vector<std::vector<double>> T;
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j < A[0].size(); ++j) {
      T[j][i] = A[i][j];
    }
  }
  return T;
}

std::vector<std::vector<double>> addRegularization(std::vector<std::vector<double>> A, double alpha) {
  for (size_t i = 0; i < A.size(); ++i) {
    A[i][i] += alpha;
  }
  return A;
}

size_t maxValueRow(const std::vector<std::vector<double>>& A, const size_t& j, const size_t& startRow) {
    size_t maxRowIndex = startRow;
    double maxValue = std::abs(A[startRow][j]);
    for (size_t i = startRow + 1; i < A.size(); ++i) {
        if (std::abs(A[i][j]) > maxValue) {
            maxValue = std::abs(A[i][j]);
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}


std::vector<double> leadingElementSolution(std::vector<std::vector<double>> A, std::vector<double> b) {
  for (size_t j = 0; j < A[0].size(); ++j) {
    size_t maxRowIndex = maxValueRow(A, j, j);
    std::swap(A[maxRowIndex], A[j]);
    std::swap(b[maxRowIndex], b[j]);

    double lambda = A[j][j];
    for (size_t k = j; k < A.size(); ++k) {
      A[j][k] /= lambda;
    }
    b[j] /= lambda;

    for (size_t i = j + 1; i < 8; ++i) {
      double factor = A[i][j];
      for (size_t k = j; k < 8; ++k) {
        A[i][k] -= factor * A[j][k];
      }
      b[i] -= factor * b[j];
    }
  }

  std::vector<double> root(8, 0);
  for (int64_t i = 7; i >= 0; --i) {
    root[i] = b[i];
    for (size_t j = i + 1; j < 8; ++j) {
      root[i] -= A[i][j] * root[j];
    }
  }
  return root;
}

std::vector<double> operator-(std::vector<double> lhs, std::vector<double> rhs) {
  std::vector<double> res;
  for (size_t i = 0; i < lhs.size(); ++i) {
    res[i] = lhs[i] - rhs[i];
  }
  return res;
}



std::vector<double> regularizationSolution(std::vector<std::vector<double>> A, std::vector<double> b, double alpha) {
  std::vector<std::vector<double>> At = transposeMatrix(A);

  std::vector<std::vector<double>> AtA = multiplyMatrices(At, A);

  std::vector<std::vector<double>> regularizedMatrix = addRegularization(AtA, alpha);

  std::vector<double> Atb = multiplyMatrices(At, b);

  return leadingElementSolution(regularizedMatrix, Atb);
}

double getNorm(const std::vector<std::vector<double>>& matrix) {
  double res = 0;
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix.size(); ++j) {
      res += matrix[i][j] * matrix[i][j];
    }
  }
  return std::sqrt(res);
}

double getNorm(const std::vector<double>& vector) {
  double res = 0;
  for (size_t i = 0; i < vector.size(); ++i) {
    res += vector[i] * vector[i];
  }
  return std::sqrt(res);
}




std::vector<double> regularization(std::vector<std::vector<double>>A, double alpha, std::vector<double> b) {
  std::vector<std::vector<double>> At = transposeMatrix(A);
  std::vector<std::vector<double>> At_A = multiplyMatrices(At, A);
  for (int i = 0; i < n; i++) {
    At_A[i][i] += alpha;
  }
  std::vector<double> At_B = multiplyMatrices(At, b);
  return sol_but_better(At_A, At_B);

}



int main() {
  setlocale(LC_ALL, "Russian");

  std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
  std::vector<double>x = { 1,2,3,4,5,6,7,8 };

  std::vector<double> b = { 0.25, 14.857142, 59.000001, 140, 257.5, 403.99998, 567, 744 };

  //матрица
  double elem = 0;
  for (double i = 1; i <= n; i++) {
    for (double j = 1; j <= n; j++) {
      if (i == j) {
        matrix[i-1][j-1] = ((i + 1)/(n - i + 1));
      }
      else if (i < j) {
        matrix[i-1][j-1] = 0;
      }
      else {
        matrix[i-1][j-1] = i * (n - j);
      }
    }
  }
  printMatrix(matrix);
  std::cout << std::endl;
  /*
  //норм-вектор
  double max_m = 0;
  for (int i = 0; i < n; i++) {
    double elem = 0;
    for (int j = 0; j < n; j++) {
       elem += std::abs(matrix[i][j]);
    }
    max_m = std::max(elem, max_m);
  }
  std::cout << "норма вектора: " << max_m << std::endl  << std::endl;

  std::vector<std::vector<double>> t_matrix(n, std::vector<double>(n));
  t_matrix[0] = { 4,	0,	0,	0,	0,	0,	0,	0 };
  t_matrix[1] = { -130.66679733346400013,	2.333335666669,	0,	0,	0,	0,	0,	0 };
  t_matrix[2] = { 3402.0018270026145021, -63.000031500047249976,	1.4999992500003749998,	0,	0,	0,	0,	0 };
  t_matrix[3] = { -65016.033404049154038,	1204.0005740008889995, - 29.999985000007499996,	1,	0,	0,	0,	0 };
  t_matrix[4] = { 812700.4175506144254, - 15050.007175011112493,	374.99981250009374994, - 13.333333333333333333,	0.66666666666666666666,	0,	0,	0 };
  t_matrix[5] = { -5642470.9596670653919,	104490.19908679013357, - 2603.5738461775740032,	92.571560816515452164, - 5.1428644898064140091,	0.42857204081720116743,	0,	0 };
  t_matrix[6] = { 15908638.885908075711, - 294604.41290183796092,	7340.6343475585660425, - 261.00046285780408255,	14.500025714322449031, - 1.500002142860204086,	0.25,	0 };
  t_matrix[7] = { -6060433.8612983145552,	112230.2525340335089, - 2796.4321324032632542,	99.4287477553539362, - 5.5238193197418853438,	0.57142938775626822324, - 0.22222222222222222222,	0.11111111111111111111 };
  //printMatrix(t_matrix);

  double max_tm = 0;
  //норм-вектор
  for (int i = 0; i < n; i++) {
    double elem = 0;
    for (int j = 0; j < n; j++) {
      //elem += t_matrix[j][i] * t_matrix[j][i];
      elem += std::abs(t_matrix[i][j]);
    }
    //std::cout << std::pow(elem, 0.5) << ' ';
    max_tm = std::max(max_tm, elem);
  }
  std::cout << "\nнорма обратной матрицы: " << max_tm;
  std::cout << "\nкоэффициент обусловленности матрицы А: " << max_tm * max_m;

  std::vector<double> b = { 0.25, 14.857142, 59.000001, 140, 257.5, 403.99998, 567, 744 };
  std::vector<double> b_tilda = { 0.1111111, 8.50000001, 45.28571315, 122.66666803, 245.000000099, 409.00000099, 604.33331003, 816.00000001 };

  double abs_norm_delta_b = -100000;
  std::cout << "\nвектор возмущений: ";
  for (int i = 0; i < n; i++) {
    std::cout << std::abs(b[i] - b_tilda[i]) << ' ';
    abs_norm_delta_b = std::max(std::abs(b[i] - b_tilda[i]), abs_norm_delta_b);
  }
  std::cout << "\nнорма вектора возмущений : " << abs_norm_delta_b;

  double abs_norm_b = -10000000;
  for (int i = 0; i < n; i++) {
    abs_norm_b = std::max(std::abs(b[i]), abs_norm_b);
  }
  std::cout << "\nнорма вектора b : " << abs_norm_b;
  std::cout << "\nотносительная норма возмущений eps: " << abs_norm_delta_b / abs_norm_b << '\n';
  double eps_b = abs_norm_delta_b / abs_norm_b;

  std::vector<double> x_tilda(8);
  x_tilda = sol_but_better(matrix, b_tilda);
  //x_tilda = { 1, 2, 2.9999, 4.00273, 4.94779, 6.65267, 2.46859, 20.7761 };
  std::vector<double> Ax_tilda = { 0.111111, 8.5, 45.2856701429, 122.66668800091, 244.99999, 409.000055, 604.3333551047, 816.0002 };
  std::vector <double> r(8);
  for (int i = 0; i < n; i++) {
    r[i] = std::abs(Ax_tilda[i] - b_tilda[i]);
  }
  printVector(r);

  double norm_r = -100000;
  for (int i = 0; i < n; i++) {
    norm_r = std::max(std::abs(r[i]), norm_r);
  }
  std::cout << "\nнорма вектора возмущений r: " << norm_r;

  std::vector<double> delta_x(8);
  for (int i = 0; i < n; i++) {
    delta_x[i] = x[i] - x_tilda[i];
  }
  printVector(delta_x);

  double abs_norm_delta_x = -10000000;
  for (int i = 0; i < n; i++) {
    abs_norm_delta_x = std::max(std::abs(delta_x[i]), abs_norm_delta_x);
  }
  std::cout << "\nнорма вектора delta x : " << abs_norm_delta_x;
  double abs_norm_x = -10000000;
  for (int i = 0; i < n; i++) {
    abs_norm_x = std::max(std::abs(x[i]), abs_norm_x);
  }
  std::cout << "\nнорма вектора x : " << abs_norm_x;
  double eps_x = abs_norm_delta_x / abs_norm_x;
  std::cout << "\nотносительная норма возмущения решения: " << eps_x;

  std::cout << "\nКоэффициент обусловленности матрицы = " << 2.79061e+11;
  std::cout << "\nотношение норм возмущения = " << eps_x / eps_b;
  std::cout << "\nкоэффициент / отношение норм возмущения = " << 2.79061e+11 / (eps_x / eps_b);
  */
  double bestAlpha = 0.0001;
  std::vector<double> bestRX;
  double bestNorm = 1e9;
  for (double alpha = 0.0; alpha <= 1e-12; alpha += 1e-17) {
    std::vector<double> regularizedX = regularizationSolution(matrix, b, alpha);
    double norm = getNorm(regularizedX - x);

    if (norm < bestNorm) {
      bestAlpha = alpha;
      bestRX = regularizedX;
      bestNorm = norm;
    }
  }
  std::cout << "\nRegularized X with alpha = " << bestAlpha << ":\n";
  printVector(bestRX);

  
  
  return 0;
}