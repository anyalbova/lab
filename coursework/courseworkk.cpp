
#include <iostream>
#include <windows.h>
#include "Header.h"


using namespace std;



void menu() {
	cout << "Выберите тему: " << endl << "1.ТИПЫ ДАННЫХ И ИХ ВНУТРЕННЕЕ ПРЕДСТАВЛЕНИЕ В ПАМЯТИ" << endl << "2.ОДНОМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ" << endl << "3.ТЕКСТОВЫЕ СТРОКИ КАК МАССИВЫ СИМВОЛОВ";
	cout << endl << "Выберите цифру: ";
	int number;
	cin >> number;
	switch (number) {
	case 1:
		Lab1();
		break;
	case 2:
		Lab2();
		break;
	case 3:
		Lab4();
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}
