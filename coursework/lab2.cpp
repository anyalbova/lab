#include <iostream>
#include <iomanip>
#include <chrono>
#include "Header.h"
using namespace std;
using namespace chrono;

void Lab2()
{

    // 1. Создание массива со случайными числами из интервала от -99 до 99
    cout << "task 1" << endl;
    const int N = 100;
    int i, A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 199 - 99;
        cout << setw(5) << A[i];
    }
    cout << endl;

    // 2. Сортировки массива + выбор
    int F;
    cout << "task 2" << endl;
    cout << "Выберите способ сортировки: " << endl << "1) Пузырьковая сортировка (bubble sort)" << endl << "2) Сортировка вставками (insert sort)" << endl;
    cin >> F;

    system_clock::time_point start = system_clock::now();
    switch (F) {

    case 1:
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (A[j] > A[j + 1]) {
                    int g = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = g;
                }
            }
            break;
        }


    case 2:
        int k = 0;
        for (i = 1; i < N; i++) {
            for (int j = i; j > 0 && A[j - 1] > A[j]; j--) {

                k++;
                int w = A[j - 1];
                A[j - 1] = A[j];
                A[j] = w;
            }
        }
        break;
    }

    system_clock::time_point end = system_clock::now();
    // Вывод результата
    for (int i = 0; i < 100; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    duration<double> sec = end - start;
    cout << endl << "Время, затраченное на сортировку:  " << sec.count() << endl;

    // 3. Найти максимальный и минимальный элемент отсортированного и неотсортированного массива
    cout << endl << "task 3" << endl;
    // Поиск в неотсортированном массиве
    system_clock::time_point start1 = system_clock::now();
    int max = A[0], min = A[0];
    for (i = 0; i < N; i++)
    {
        if (max < A[i])
            max = A[i];
        if (min > A[i])
            min = A[i];
    }
    system_clock::time_point end1 = system_clock::now();
    // Поиск в отсортированном массиве
    system_clock::time_point start2 = system_clock::now();
    max = A[N - 1];
    min = A[0];
    system_clock::time_point end2 = system_clock::now();
    duration<double> sec1 = end1 - start1;
    duration<double> sec2 = end2 - start2;
    cout << "Время поиска после сортировки: " << sec2.count() << endl;
    cout << "Время поиска до сортировки: " << sec1.count() << endl;
    cout << "max: " << max << endl << "min: " << min;
    cout << endl;

    // 4. Найти среднее значение max и min + вывести индексы всех элементов, которые равны этому значению, и их кол-во
    cout << endl << "task 4" << endl;
    int mid, K = 0;
    // Находим среднее значение
    mid = (A[99] + A[0]) / 2;
    cout << "Ср.значение: " << mid << endl;
    // Находим индексы и кол-во схожих элементов
    cout << "Индексы: ";
    for (int i = 0; i < N; i++)
    {
        if (A[i] == mid)
        {
            K += 1;
            cout << i << " ";
        }

    }
    cout << "Количество: " << K << endl;

    //  5. Кол-во эллементов больше и меньше введенного числа
    cout << endl << "task 5 & 6" << endl;
    int p = 1;
    while (p != 0)
    {
        cout << "Введите число: ";
        int a, klv; //klv - количество элементов, а - вводимое число
        klv = 0;
        cin >> a;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > a)
            {
                klv += 1;
            }

        }
        cout << "Количество элементов меньше введенного числа: " << klv << endl;
        cout << endl;
        cout << "Введите 0, если хотите закончить, или введите 1, чтобы продолжить" << endl;
        cin >> p;
        cout << endl;
    }
    p = 1;
    while (p != 0)
    {
        cout << "Введите число: ";
        int b, klv2; // klv2 - количество, b - вводимое число
        klv2 = 0;
        cin >> b;
        for (int i = 0; i < N; i++)
        {
            if (A[i] < b)
            {
                klv2 += 1;
            }
        }
        cout << "Количество элементов больше введенного числа: " << klv2 << endl;
        cout << endl;
        cout << "Введите 0, если хотите закончить, или введите 1, чтобы продолжить" << endl;
        cin >> p;
        cout << endl;
    }


    // 8. Замена элементов
    cout << endl << "task 8" << endl;
    int t, u, h;
    p = 1;
    while (p != 0)
    {
        cout << "Введите число 1: ";
        cin >> u;
        cout << "Введите число 2: ";
        cin >> h;
        system_clock::time_point start3 = system_clock::now();
        t = A[u];
        A[u] = A[h];
        A[h] = t;
        system_clock::time_point end3 = system_clock::now();
        duration<double> sec3 = end3 - start3;
        cout << endl << "Время замены:" << sec3.count() << endl;
        cout << endl << endl << "Результат после замены: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
        }

        cout << endl << "Введите 0, если хотите закончить, или введите 1, чтобы продолжить" << endl;
        cin >> p;
        cout << endl;
    }

}