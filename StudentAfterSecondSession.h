#pragma once
#include <vector>
#include "Student.h"
#include "StudentAfterFirstSession.h"

using namespace std;

class StudentAfterSecondSession : public StudentAfterFirstSession {
 protected:
  vector<int> _marks2;

 public:
  StudentAfterSecondSession(const char* name, int course, int group, int number_of_record,
	  vector<int> marks, vector<int> marks2) : StudentAfterFirstSession(name, course, group, 
		  number_of_record, marks){
    _marks2 = marks2;
  } 
  vector<int> getMarks();
  void setMarks(int mark, int index_of_subject);
  double CalculateAverage() override;
  double CalculateAverage(int number_of_session) override;	
  friend std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSession& point);
};
