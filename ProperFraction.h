#pragma once

using namespace std;

int NOD(int x, int y);

class ProperFraction {
 private:
  int numerator;
  int denumerator;
  ProperFraction() {} 

 public:
  void ReduceFraction();
  ProperFraction(int num, int denum);
  ProperFraction(const ProperFraction &obj);
  int get_num();
  void set_num(int a);
  int get_denum();
  void set_denum(int d);
  ProperFraction operator+(const ProperFraction &obj);
  ProperFraction operator*(const ProperFraction &obj);
  ProperFraction operator/(const ProperFraction &obj);
  void PrintFraction();
};
