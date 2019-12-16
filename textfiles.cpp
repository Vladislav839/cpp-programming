/*Разбить исходный файл на два выходных: в первом файле должны идти строки, 
символы которых не убывают, во втором – строки, символы которых не возрастают.
 Порядок строк выходных файлов должен соответствовать их порядку во входном файле. */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool Increase (string str){
  string buffer = str;
  sort(str.begin(), str.end());
  return str == buffer;
}

bool Decrease (string str){
  string buffer = str;
  sort(str.begin(), str.end());
  reverse(str.begin(), str.end());
  return str == buffer;
}

int main(){
  ifstream fin("input.txt");
  ofstream fout("output1.txt");
  ofstream lout("output2.txt");
  while(!fin.eof()){
    string str;
    getline(fin, str, '\n');
    if(Increase(str)){
        fout<<str<<endl;
      }
    if(Decrease(str)){
        lout<<str<<endl;
      }
  }
  return 0;
}
