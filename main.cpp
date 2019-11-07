#include <iostream>
#include "ProperFraction.h"


using namespace std;


int main() {
  setlocale(LC_ALL, "Russian");
  ProperFraction drob1(5, 10);
  drob1.PrintFraction();
  ProperFraction drob2(3, 5);
  drob2.PrintFraction();
  cout << "Сумма дробей равна" << endl;
  ProperFraction a = drob1 + drob2;
  a.PrintFraction();
  cout << "Произведение дробей равно" << endl;
  ProperFraction b = drob1 * drob2;
  b.PrintFraction();
  cout << "Частное от деления дробей равно" << endl;
  ProperFraction c = drob1 / drob2;
  c.PrintFraction();
  system("pause");
  return 0;
}
