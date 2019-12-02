#define _CRT_SECURE_NO_WARNINGS 0
#include "Student.h"
#include <cstring>

using namespace std;

int code = 0;

Student::Student(const char* name, int course, int group, int number_of_record) {
  _name = new char[strlen(name)];
  strcpy(_name, name);
  _course = course;
  _group = group;
  _number_of_record = number_of_record;
  _uniqe_code = ++code;
}

Student::Student(const Student& obj) {
  _name = obj._name;
  _course = obj._course;
  _group = obj._group;
  _number_of_record = obj._number_of_record;
  _uniqe_code = obj._uniqe_code;
}

int Student::getCode() { return _uniqe_code; }

char* Student::getName() { return _name; }

void Student::setName(char* name) { _name = name; }

int Student::getGroup() { return _group; }

void Student::setGroup(int group) { _group = group; }

int Student::getCourse() { return _course; }

void Student::setCourse(int course) { _course = course; }

int Student::getNumber_of_record() { return _number_of_record; }

void Student::setNumber_of_record(int number_of_record) {
  _number_of_record = number_of_record;
}

double Student::CalculateAverage() { return 0.0; }

std::ostream& operator<<(std::ostream& out, const Student& stud) {
  out << "ID: " << stud._uniqe_code << endl;
  out << "name: " << stud._name << endl;
  out << "course: " << stud._course << endl;
  out << "group: " << stud._group << endl;
  out << "number of record: " << stud._number_of_record << endl;
  return out;
}
