#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

using namespace std;


double ArrayAverage(const vector<Student*>& arr) {
  double sum = 0;
  for (int i = 0; i < arr.size(); ++i) {
    sum += arr[i]->CalculateAverage();
  }
  return sum / arr.size();
}

double GroupAverageAfterFirstSession(const vector<Student*>& arr, int number) {
  vector<Student*> tmp;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i]->getGroup() == number) {
      tmp.push_back(arr[i]);
    }
  }
  double sum = 0;
  for (int i = 0; i < tmp.size(); ++i) {
    sum += tmp[i]->CalculateAverage(1);
  }
  return sum / tmp.size();
}

double GroupAverageAfterSecondSession(const vector<Student*>& arr, int number) {
  vector<Student*> tmp;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i]->getGroup() == number &&
        (strcmp(typeid(*arr[i]).name(), "class StudentAfterSecondSession") == 0)) {
      tmp.push_back(arr[i]);
    }
  }
  double sum = 0.0;
  for (int i = 0; i < tmp.size(); ++i) {
    sum += tmp[i]->CalculateAverage(2);
  }
  return sum / tmp.size();
}

int main() {
  Student a("Vasia", 1, 2, 19248);
  cout << a;
  StudentAfterFirstSession b("Misha", 1, 3, 73757, {8, 9, 5, 6});
  cout << b;
  cout << "Average mark after first session " << b.CalculateAverage() << endl;
  StudentAfterSecondSession c("Sasha", 1, 3, 19248, {9, 5, 6, 7}, {8, 8, 5, 6});
  cout << c;
  cout << "Average mark after a year " << c.CalculateAverage() << endl;
  StudentAfterSecondSession d("Petya", 1, 3, 123548, {5, 6, 9, 7},
                              {5, 9, 7, 8});
  cout << d;
  cout << "Average mark after first session " << d.CalculateAverage() << endl;
  vector<Student*> arr;
  arr.push_back(&a);
  arr.push_back(&b);
  arr.push_back(&c);
  arr.push_back(&d);
  cout << "Average mark in the array is " << ArrayAverage(arr) << endl;
  cout << "Enter the number of group" << endl;
  int number_of_group = 3;
  cout << "Average mark in " << number_of_group
       << " group after first session is "
       << GroupAverageAfterFirstSession(arr, number_of_group) << endl;
  cout << "Average mark in " << number_of_group
       << " group after second session is "
       << GroupAverageAfterSecondSession(arr, number_of_group) << endl;
  system("pause");
  return 0;
}
