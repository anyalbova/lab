#include <iostream>
#include <string>
#include <windows.h>
#include "Header.h"

using namespace std;


void printSubstringIndexes(const char* str, const char* substr)
{
	int strLength = strlen(str);
	int substrLength = strlen(substr);

	int iter = 0;
	int res;
	for (int i = 0; i < strLength - substrLength + 1; ++i)
	{
		int j = 0;
		while (j != substrLength && str[i + j] == substr[j]) ++j;
		if (j == substrLength) cout << i << ' ';
	}
}


void printCapitalized(const char* str)
{
	cout << char(toupper(str[0]));
	for (int i = 1; i < strlen(str); ++i)
	{
		if (!isalpha(str[i - 1]) && isalpha(str[i])) cout << char(toupper(str[i]));
		else cout << str[i];
	}
}


void Lab4()
{
	cin.ignore();
	char text[1000];
	char punct[12] = { 33, 34, 39, 40, 41, 44, 45, 47, 58, 59, 63, 92 };
	cout << "Enter a text ";
	cin.getline(text, 1000);

	cout << "Your text: " << text << endl;



	// 2.1 Убрать пробелы

	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ') {
			while (text[i] == text[i + 1]) {
				for (int j = i + 1; j < strlen(text); j++)
				{
					text[j] = text[j + 1];
				}
			}
		}

	}
	cout << "Text without ' ' : " << text << endl;

	// 2.2. Убрать лишние знаки препинания
	for (int i = 0; i < strlen(text); i++) {

		if (ispunct(text[i])) {
			while (text[i] == text[i + 1]) {
				for (int k = i + 1; k < strlen(text); k++)
				{
					text[k] = text[k + 1];
				}
			}
		}

	}

	cout << "Text without punctuation: " << text << endl;


	// 3.3 Вывести последовательность, не содержащую цифры.
	cout << "Text without numbers: ";
	int indexIn = 0;
	int indexOut = 0;
	char text1[1000];
	while (text[indexIn] != '\0') // 
	{
		if (text[indexIn] >= '0' && text[indexIn] <= '9')
			indexIn++;
		else
		{
			text1[indexOut] = text[indexIn];
			indexIn++;
			indexOut++;
		}
	}

	text1[indexOut] = '\0';
	puts(text1);

	// 4.1 Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.

	cout << "Edited text: ";
	printCapitalized(text);

	// 5. Линейный поиск подстроки

	cout << endl << "Substring: ";
	char substring[100];
	cin.getline(substring, 100, '\n');
	cout << endl << "indexes: ";
	printSubstringIndexes(text, substring);


}