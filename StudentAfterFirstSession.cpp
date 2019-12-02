#include "StudentAfterFirstSession.h"
#include <vector>

 using namespace std;

 vector<int> StudentAfterFirstSession::getMarks() { return _marks; }

 void StudentAfterFirstSession::setMarks(int mark, int index_of_subject) {
  _marks[index_of_subject] = mark;
 }

 double StudentAfterFirstSession::CalculateAverage() { 
   int sum = 0;
   for (int i = 0; i < _marks.size(); i++) {
     sum += _marks[i];
   }
   return sum / _marks.size();
 }

 std::ostream& operator<<(std::ostream& out,
                         const StudentAfterFirstSession& stud) {
  setlocale(LC_ALL, "Russian");
  out << "Идентификатор: " << stud._uniqe_code << endl;
  out << "Имя студента: " << stud._name << endl;
  out << "Курс: " << stud._course << endl;
  out << "Группа: " << stud._group << endl;
  out << "Номер зачетки: " << stud._number_of_record << endl;
  out << "Оценки: ";
  for (auto k : stud._marks) {
    out << k << " ";
  }
  out << "\n";
  return out;
}
