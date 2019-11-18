#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> Strtovec(string str)  // перевод считанных с файла строк в массив
{
  vector<int> v;
  int n;
  istringstream ss(str);

  while (ss >> n) {
    v.push_back(n);
  }

  return v;
}

struct coord  // структура координат вектора
{
  int x1;
  int y1;
  int x2;
  int y2;
  void Print(ofstream &fout) {
    fout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  }
};

bool Colen(coord a, coord b)  // проверка на коллинеарность
{
  int v1_x = a.x2 - a.x1;
  int v1_y = a.y2 - a.y1;
  int v2_x = b.x2 - b.x1;
  int v2_y = b.y2 - b.y1;
  int col = v1_x * v2_y - v1_y * v2_x;
  if (col == 0) {
    return true;
  } else {
    return false;
  }
}

double lengh_of_vector(coord a) {
  return sqrt((a.x2 - a.x1) * (a.x2 - a.x1) + (a.y2 - a.y1) * (a.y2 - a.y1));
}

double angle(coord a)  // угол между вектором и Ox
{
  return acos((a.x2 - a.x1) / lengh_of_vector(a));
}

void Sort_by_angle(vector<vector<coord>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size() - i - 1; j++) {
      if (angle(v[j][0]) > angle(v[j + 1][0])) {
        auto tmp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = tmp;
      }
    }
  }
}

void Sort_by_length(vector<coord> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size() - i - 1; j++) {
      if (lengh_of_vector(v[j]) > lengh_of_vector(v[j + 1])) {
        auto tmp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = tmp;
      }
    }
  }
}

int main() {
  ifstream fin("vectors.txt");
  vector<coord> v;
  while (!fin.eof()) {
    string str;
    getline(fin, str);
    vector<int> arr = Strtovec(str);
    coord c;
    c.x1 = arr[0];
    c.y1 = arr[1];
    c.x2 = arr[2];
    c.y2 = arr[3];
    v.push_back(c);
  }
  vector<vector<coord>> groups;  // формирование групп по коллинеарности
  for (int i = 0; i < v.size(); i++) {
    vector<coord> tmp;
    tmp.push_back(v[i]);
    for (int j = i + 1; j < v.size(); j++) {
      if (Colen(v[i], v[j])) {
        tmp.push_back(v[j]);
        v.erase(v.begin() + j);
        j--;
      }
    }
    groups.push_back(tmp);
  }
  string name_of_file = to_string(groups.size()) + "_groups_for_" +
                        to_string(v.size()) + "_vectors.txt";
  ofstream fout(name_of_file);
  Sort_by_angle(groups);
  for (int i = 0; i < groups.size(); i++) {
    Sort_by_length(groups[i]);
  }
  for (int i = 0; i < groups.size(); i++) {
    for (int j = 0; j < groups[i].size(); j++) {
      groups[i][j].Print(fout);
    }
    fout << endl;
  }
  system("pause");
  return 0;
}
