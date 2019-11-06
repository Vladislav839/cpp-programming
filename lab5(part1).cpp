/* Написать собственную реализацию стандартной функции strcpy.*/

#include <iostream>
#include <cstring>

using namespace std;

char* MyCopy(char* destination, const char* source)
{
	if (destination == NULL)// проверяем не пуста ли строка
		return NULL;
	char *ptr = destination; // присваиваем новому указателю указатель на начало исходной строки
	while (*source != '\0') // собственно копируем содержимое
	{
		*destination = *source;
		destination++;
		source++;
	}
	return ptr; // возвращаем копию строки
}

int main(){
    setlocale(LC_ALL, "Russian");
    char* source = "Techie Delight";
	char* destination = new char [strlen(source)];
	cout<<"Результат работы функции MyCopy"<<endl;
	cout<<MyCopy(destination, source)<<endl;
	delete[] source;
	delete[] destination;
	system("pause");
	return 0;
}
