#include "StudentAfterSecondSession.h"
#include <vector>

using namespace std;

vector<int> StudentAfterSecondSession::getMarks() { return _marks; }

void StudentAfterSecondSession::setMarks(int mark, int index_of_subject) {
  _marks[index_of_subject] = mark;
}

double StudentAfterSecondSession::CalculateAverage() { 
  int sum = 0;
  for (int i = 0; i < _marks.size(); i++){
    sum += _marks[i];
  }
  for (int j = 0; j < _marks2.size(); j++) {
    sum += _marks2[j];
  }
  return sum / (_marks.size() + _marks2.size());
}

std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSession& stud) {
  setlocale(LC_ALL, "Russian");
  out << "Идентификатор: " << stud._uniqe_code << endl;
  out << "Имя студента: " << stud._name << endl;
  out << "Курс: " << stud._course << endl;
  out << "Группа: " << stud._group << endl;
  out << "Номер зачетки: " << stud._number_of_record << endl;
  out << "Оценки за первую сессию: ";
  for (auto k : stud._marks) {
    out << k << " ";
  }
  out << "\n";
  out << "Оценки за вторую сессию: ";
  for (auto k : stud._marks2) {
    out << k << " ";
  }
  out << "\n";
  return out;
}
