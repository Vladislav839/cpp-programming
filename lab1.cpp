#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  int k, i;
  double x;
  double s2 = 0;
  cout << "Введите степень k, как натуральное, большее единицы число\n";
  cin >> k;
  if (k <= 1) {
    cout << "Вы ввели неверное k\n";
    system("pause");
    return 0;
  }
  cout << "Введите значение x из промежутка [-1;1)\n";
  cin >> x;
  double s1 = log(1 - x);
  cout << "Результат, веполненный стандартными функциями равен "
       << setprecision(k + 1) << s1 << endl;
  i = 1;
  do {
    s2 += -pow(x, i) / i;
    i++;
  } while (fabs(-pow(x, i) / i) > pow(10, -k));
  cout << "Результат вычесления через ряд равен " << setprecision(k + 1) << s2
       << endl;
  system("pause");
  return 0;
}
