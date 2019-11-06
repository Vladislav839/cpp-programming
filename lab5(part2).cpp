/*Строка состоит из слов, разделенных одним или несколькими пробелами. Найти слово,  символы
 в котором идут в строгом возрастании их кодов. Если таких слов несколько, найти первое из них.
предполагается, что длина входной строки не превосходит 300 символов, она вводится из файла. 
Вам необходимо вывести на консоль либо преобразованную строку, либо требуемые в условии данные.
Во входном файле просто строки разделенные '\n'.
 Использовать класс string нельзя!
Максимум 8 баллов – ввод склавиатуры
Максимум 10 баллов – ввод из файла. Задание выполнять для каждой строки*/

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
