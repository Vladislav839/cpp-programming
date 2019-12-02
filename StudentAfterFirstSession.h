#pragma once
#include "Student.h"
#include <vector>

using namespace std;

class StudentAfterFirstSession : public Student {
 protected:
  vector<int> _marks;
  StudentAfterFirstSession(){};
 public:
  StudentAfterFirstSession(const char* name, int course, int group, 
	  int number_of_record, vector<int> marks)
      : Student(name, course, group, number_of_record) {
    _marks = marks;
  }
  vector<int> getMarks();
  void setMarks(int mark, int index_of_subject);
  double CalculateAverage() override;
  friend std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSession& point);

};