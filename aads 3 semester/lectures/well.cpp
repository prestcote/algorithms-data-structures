#include <iostream>

using namespace std;

int n, i, j, k;

double d, s;

int main()

{

  cout << "Poryadok: " << endl;

  cin >> n;

  double** a = new double* [n];

  for (i = 0; i <= n; i++)

    a[i] = new double[n];

  double** a1 = new double* [n];

  for (i = 0; i <= n; i++)

    a1[i] = new double[n];

  double* b = new double[n];

  double* x = new double[n];

  cout << "Vvedite koefficienty i svobodnye chleny " << endl;

  for (i = 1; i <= n; i++)

  {

    for (j = 1; j <= n; j++)

    {

      cout << "a[ " << i << "," << j << "]= ";

      cin >> a[i][j];

      a1[i][j] = a[i][j];

    }

    cout << "b,[ " << i << "]= ";

    cin >> b[i];

  }

  for (k = 1; k <= n; k++) // ������ ���

  {

    for (j = k + 1; j <= n; j++)

    {

      d = a[j][k] / a[k][k]; // ������� (1)

      for (i = k; i <= n; i++)

      {

        a[j][i] = a[j][i] - d * a[k][i]; // ������� (2)

      }

      b[j] = b[j] - d * b[k]; // ������� (3)

    }

  }

  for (k = n; k >= 1; k--) // �������� ���

  {

    d = 0;

    for (j = k + 1; j <= n; j++)

    {

      s = a[k][j] * x[j]; // ������� (4)

      d = d + s; // ������� (4)

    }

    x[k] = (b[k] - d) / a[k][k]; // ������� (4)

  }

  cout << "Korni sistemy: " << endl;

  for (i = 1; i <= n; i++)

    cout << "x[" << i << "]=" << x[i] << " " << endl;

  return 0;

}