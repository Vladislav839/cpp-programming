#include <iostream>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

using namespace std;



int main() {
  setlocale(LC_ALL, "Russian");
  Student a("Vasia", 1, 4, 19248);
  cout << a;
  StudentAfterFirstSession b("Misha", 1, 3, 73757, {8, 9, 5, 6});
  cout << b;
  cout << "Средний балл за первую сессию " << b.CalculateAverage() << endl;
  StudentAfterSecondSession c("Sasha", 1, 4, 19248, {9, 5, 6, 7}, {8, 8, 5, 7});
  cout << c;
  cout << "Средний балл за год " << c.CalculateAverage() << endl;
  system("pause");
  return 0;
}