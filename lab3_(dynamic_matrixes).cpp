/**
4.	В целочисленной прямоугольной матрице, имеющей 2m строк, a[i, j] = a[i+m, j] 
для всех допустимых i и j. Требуется определить:
– количество столбцов, не содержащих нулей;
– номер первой из строк, в которой содержится самая длинная 
строго возрастающая последовательность элементов.
**/
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find_zero(int** arr, int m,
              int n)  /// функция для подсчета кол-ва столбцов содерж. 0
{
  int i, j;
  int count = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (arr[j][i] == 0) {
        count++;
        break;
      }
  return count;
}

int number_of_first_row(int** arr, int m, int n) {
  int i, j, max_l = 1, l;
  vector<pair<int, int>> v;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      l = 1;
      while (arr[i] > arr[i - 1]) {
        i++;
        l++;
      }
      if (l > max_l) max_l = l;
    }
    v.push_back(make_pair(max_l, i));
  }
  int nmax = 0;
  for (i = 0; i < v.size(); i++) {
    if (v[i].first > v[nmax].first) {
      nmax = i;
    }
  }
  return v[nmax].second;
}

int main() {
  setlocale(LC_ALL, "Russian");
  int i, j, m, n;
  srand(time(NULL));
  cout << "Введите m" << endl;
  cin >> m;
  n = m;
  int** arr = new int*[2 * m];
  for (i = 0; i < 2 * m; i++) arr[i] = new int[n];
  for (i = 0; i < m; i++)  /// Вводим половину нашей матрицы
  {
    for (j = 0; j < n; j++) {
      arr[i][j] = rand() % 5;
    }
  }
  cout << "Исходная матрица" << endl;
  for (i = 0; i < m; i++)  /// Вводим половину нашей матрицы
  {
    for (j = 0; j < n; j++) {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
  for (i = 0; i < m; i++)  /// остальную половину заполняем первой
  {
    for (j = 0; j < n; j++) {
      arr[i + m][j] = arr[i][j];
    }
  }
  cout << "Исходная матрица после склеивания двух половин" << endl;
  for (i = 0; i < 2 * m; i++) {
    for (j = 0; j < n; j++) {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "Количество столбцов не содержащих нули равно "
       << n - find_zero(arr, m, n) << endl;
  cout << "Номер первой строки в которой содержится самая длинная" << endl;
  cout << "строго возрастающая последовательность чисел (нумерация с 0) равен "
       << number_of_first_row(arr, 2 * m, n) << endl;
  system("pause");
  return 0;
}
