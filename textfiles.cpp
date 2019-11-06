/*Разбить исходный файл на два выходных: в первом файле должны идти строки, 
символы которых не убывают, во втором – строки, символы которых не возрастают.
 Порядок строк выходных файлов должен соответствовать их порядку во входном файле. */

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

bool Increase(char* str) {
  bool flag = true;
  for (int i = 0; i < strlen(str) - 1; i++) {
    if (str[i] >= str[i + 1]) {
      flag = false;
    }
  }
  return flag;
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int number_of_string = 0;
  while (!fin.eof()) {
    number_of_string++;
    char* str = new char[300];
    fin.getline(str, 300, '\n');
    char* pch = strtok(str, " ");
    bool flag = true;
    while (pch != NULL) {
      if (Increase(pch)) {
        fout << number_of_string << " " << pch << endl;
        break;
      }
      pch = strtok(NULL, " ,.-");
    }
    delete[] str;
  }
  return 0;
}