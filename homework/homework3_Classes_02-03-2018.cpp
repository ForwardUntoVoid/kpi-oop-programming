#include "stdafx.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <iomanip>
const int N = 10;// Количество студентов в списке журнала
const int L = 5; // Длина случайно генерируемого имени
const int M = 5; // Количество оценок
std::string rndName(int Len) // Генератор случайного имени
{
	std::string rname = {};
	rname += 0x41 + rand() % 26; // Случайная заглавная буква А-Z
	for (int i = 1; i < Len; ++i) 
		rname += 0x61 + rand() % 26; // Случайная прописная буква а-z
	return rname;
}
class Student
{
private:
	// Поточные оценки
	int m_marks[M];
	// Имя студента
	std::string m_name;
public:
	// Задание имени
	void setName(std::string name)
	{
		m_name = name;
	}
	// Вывод имени
	std::string getName()
	{
		return m_name;
	}
	// Задание поточных оценок
	void setMarks(int marks[])
	{
		for (int i = 0; i < M; ++i)
			m_marks[i] = marks[i];
	}
	// Вывод поточных оценок
	void showMarks()
	{
		for (int i = 0; i < M; ++i)
			std::cout << std::uppercase << std::hex << m_marks[i] << " ";
		std::cout << std::endl;
	}

};
class Journal
{
private:
	Student stds[N];
public:
	void Generate()
	{
		int *rmarks = new int[M];
		for (int i = 0; i < N; ++i)
		{
			stds[i].setName(rndName(L));
			for (int j = 0; j < M; ++j)
				rmarks[j] = 0xE - rand() % 5; // Случайное число в диапазоне А-Е
			stds[i].setMarks(rmarks);
		}
		delete[]rmarks;
	}
	void showList()
	{
		for (int i = 0; i < N; ++i)
		{
			std::cout << " > " << std::dec << std::setw(3) << std::left << i + 1 << (stds[i].getName()) << " : ";
			stds[i].showMarks();
		}
	}
	// !!! Неясная ошибка доступа чтения/записи !!!
	void sortList() 
	{
		std::string nameBuffer;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (((stds[j].getName()) > (stds[j+1].getName())))
				{
					nameBuffer = ((stds[j].getName()));
					stds[j].setName(stds[j + 1].getName());
					stds[j+1].setName(nameBuffer);
				}
			}
		}
	}
};
int main()
{
	Journal JRNL;
	JRNL.Generate();
	JRNL.showList();
	std::cout << std::endl;
	//JRNL.sortList();
	JRNL.showList();
	system("pause");
}