#include <iostream>
#include "Header.h"

using namespace std;

void Lab1()
{
    cout << "Task 1" << '\n';
    cout << "Size of int: " << sizeof(int) << '\n';
    cout << "Size of short int: " << sizeof(short int) << '\n';
    cout << "Size of long int: " << sizeof(long long int) << '\n';
    cout << "Size of double: " << sizeof(double) << '\n';
    cout << "Size of float: " << sizeof(float) << '\n';
    cout << "Size of long double: " << sizeof(long double) << '\n';
    cout << "Size of char: " << sizeof(char) << '\n';
    cout << "Size of bool: " << sizeof(bool) << '\n';
    cout << '\n';


    cout << "Task 2" << '\n';
    int value;
    cin >> value;
    unsigned int order = sizeof(int) * 8;
    unsigned int mask = 1 << order - 1;
    for (int i = 1; i <= order; i++)
    {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0)
        {
            putchar(' ');
        }
        if (i % order - 1 == 0)
        {
            putchar(' ');
        }
    }
    cout << '\n';

    cout << "Task 3" << '\n';

    union {
        float pb;
        int a;
    };
    cin >> pb;
    mask = 1 << order - 1;
    for (int i = 1; i <= order; i++)
    {
        putchar(a & mask ? '1' : '0');
        a <<= 1;
        if (i % 8 == 0)
        {
            putchar(' ');
        }
        if (i % order - 1 == 0)
        {
            putchar(' ');
        }
    }
    cout << '\n';

    cout << "Task 4" << '\n';
    union {
        double pr;
        int b[2];

    };
    cin >> pr;

    for (int j = 1; j >= 0; j--) {
        mask = 1 << order - 1;
        for (int i = 1; i <= order; i++)
        {
            putchar(b[j] & mask ? '1' : '0');
            mask >>= 1;

            if (j == 1 && i == 1)
            {
                putchar(' ');
            }
            if (j == 1 && i == 12)
            {
                putchar(' ');
            }
        }
    }
    cout << '\n';

}