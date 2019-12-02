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
   out << "ID: " << stud._uniqe_code << endl;
   out << "name: " << stud._name << endl;
   out << "course: " << stud._course << endl;
   out << "group: " << stud._group << endl;
   out << "number of record: " << stud._number_of_record << endl;
  out << "marks after first session: ";
  for (auto k : stud._marks) {
    out << k << " ";
  }
  out << "\n";
  return out;
}
