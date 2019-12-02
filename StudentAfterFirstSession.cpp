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
  out << "�������������: " << stud._uniqe_code << endl;
  out << "��� ��������: " << stud._name << endl;
  out << "����: " << stud._course << endl;
  out << "������: " << stud._group << endl;
  out << "����� �������: " << stud._number_of_record << endl;
  out << "������: ";
  for (auto k : stud._marks) {
    out << k << " ";
  }
  out << "\n";
  return out;
}
