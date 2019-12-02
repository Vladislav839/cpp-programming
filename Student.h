#pragma once
#include <iostream>
class Student {
 protected:
  int _uniqe_code;
  char* _name;
  int _course;
  int _group;
  int _number_of_record;
  Student() {}
 public:
  Student(const char* name, int course, int group, int number_of_record);
  Student(const Student& obj);
  int getCode();
  char* getName();
  void setName(char* name);
  int getGroup();
  void setGroup(int group);
  int getCourse();
  void setCourse(int course);
  int getNumber_of_record();
  void setNumber_of_record(int number_of_record);
  virtual double CalculateAverage();
  friend std::ostream& operator<<(std::ostream& out, const Student& point);
};

