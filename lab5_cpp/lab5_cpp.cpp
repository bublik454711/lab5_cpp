#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <windows.h>  
#include "Lesson.h"

using namespace std;

int Client::clientCounter = 0;
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	// Пример работы с исключениями
	try
	{
		ID id = ID(2352, -235654); // Пытаемся создать паспорт с отрицательным номером
	}
	catch (const std::invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
	// Пример работы с одномерными и двумерными массивами
	Client cl[3];
	int val;
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите кол-во занятий для добавления: ";
		cin >> val;
		cl[i] = cl[i] + val;
		cl[i].Print();
	}
	Auto car[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			car[i][j].Input();
	cout << "Гос номер второго автомобиля: ";
	cout << car[0][1].GetgosNumber() << endl;
}