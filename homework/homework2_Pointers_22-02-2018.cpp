/*
Программа должна считывать введенный текст с клавиатуры и поместить его в динамический массив, размер которого зависит от количества введенных символов
*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	cout << " > Enter text: ";
	int i, j, symbol = getchar();
	char *ptr_buffer = new char[1];
	for (i = 0; symbol != '\n'; ++i)
	{
		if (i != 0)
		{
			char *ptr_buffer = new char[i + 1];
			for (j = 0; j < (i - 1); ++j)
			{
				ptr_buffer[j] = ptr_string[j];
			}
			delete[]ptr_string;
		}
		ptr_buffer[i] = symbol;
		symbol = getchar();
		char *ptr_string = new char[i + 1];
		for (j = 0; j < i; ++j)
		{
			ptr_string[j] = ptr_buffer[j];
		}
		delete[]ptr_buffer;
	}
	ptr_string[i] = '\0';
	cout << "Text: " << ptr_string;
	delete[]ptr_string;
	_getch();
	return 0;
}