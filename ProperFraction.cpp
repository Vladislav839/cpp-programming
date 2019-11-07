#include "ProperFraction.h"
#include <iostream>

using namespace std;

int NOD(int x, int y) { 
   if (y == 0) return x;
  return NOD(y, x % y);
}

void ProperFraction::ReduceFraction() {
  int nod = NOD(numerator, denumerator);
  numerator = numerator / nod;
  denumerator = denumerator / nod;
}

ProperFraction::ProperFraction(int num, int denum) {
  if (denum == 0) {
    cout << "Unable to construct PF" << endl;
    abort();
  } else {
    numerator = num;
    denumerator = denum;
    ReduceFraction();
  }
}

ProperFraction::ProperFraction(const ProperFraction& obj) {
  numerator = obj.numerator;
  denumerator = obj.denumerator;
}

int ProperFraction::get_num() { return numerator; }

void ProperFraction::set_num(int a) {
  numerator = a;
  ReduceFraction();
}

int ProperFraction::get_denum() { return denumerator; }

void ProperFraction::set_denum(int d) {
  if (d == 0) {
    cout << "cannot change denumerator" << endl;
    abort();
  }
  denumerator = d;
  ReduceFraction();
}

ProperFraction ProperFraction::operator+(const ProperFraction& obj) {
  ProperFraction drob(1, 1);
  drob.denumerator = obj.denumerator * denumerator;
  int num1 = drob.denumerator / denumerator * numerator;
  int num2 = drob.denumerator / obj.denumerator * obj.numerator;
  drob.numerator = num1 + num2;
  drob.ReduceFraction();
  return drob;
}

ProperFraction ProperFraction::operator*(const ProperFraction& obj) {
  ProperFraction drob(1, 1);
  drob.denumerator = obj.denumerator * denumerator;
  drob.numerator = obj.numerator * numerator;
  drob.ReduceFraction();
  return drob;
}

ProperFraction ProperFraction::operator/(const ProperFraction& obj) {
  ProperFraction drob(1, 1);
  drob.denumerator = denumerator * obj.numerator;
  drob.numerator = numerator * obj.denumerator;
  drob.ReduceFraction();
  return drob;
}

void ProperFraction::PrintFraction() {
  cout << numerator << "/" << denumerator << endl;
}
