#include <cmath>
#include <iostream>
#include <string>
#include "Stack.h"
#include "calculator.h"

using namespace std;

int main() {
  Calculator calc;
  cout << "Enter a string\n";
  calc.ReadExpression();
  cout << calc.calculate() << endl;
  system("pause");
  return 0;
}