#include <iostream>
#include <iomanip>
#include <chrono>
#include "Header.h"
using namespace std;
using namespace chrono;

void Lab2()
{

    // 1. �������� ������� �� ���������� ������� �� ��������� �� -99 �� 99
    cout << "task 1" << endl;
    const int N = 100;
    int i, A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 199 - 99;
        cout << setw(5) << A[i];
    }
    cout << endl;

    // 2. ���������� ������� + �����
    int F;
    cout << "task 2" << endl;
    cout << "�������� ������ ����������: " << endl << "1) ����������� ���������� (bubble sort)" << endl << "2) ���������� ��������� (insert sort)" << endl;
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
    // ����� ����������
    for (int i = 0; i < 100; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    duration<double> sec = end - start;
    cout << endl << "�����, ����������� �� ����������:  " << sec.count() << endl;

    // 3. ����� ������������ � ����������� ������� ���������������� � ������������������ �������
    cout << endl << "task 3" << endl;
    // ����� � ����������������� �������
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
    // ����� � ��������������� �������
    system_clock::time_point start2 = system_clock::now();
    max = A[N - 1];
    min = A[0];
    system_clock::time_point end2 = system_clock::now();
    duration<double> sec1 = end1 - start1;
    duration<double> sec2 = end2 - start2;
    cout << "����� ������ ����� ����������: " << sec2.count() << endl;
    cout << "����� ������ �� ����������: " << sec1.count() << endl;
    cout << "max: " << max << endl << "min: " << min;
    cout << endl;

    // 4. ����� ������� �������� max � min + ������� ������� ���� ���������, ������� ����� ����� ��������, � �� ���-��
    cout << endl << "task 4" << endl;
    int mid, K = 0;
    // ������� ������� ��������
    mid = (A[99] + A[0]) / 2;
    cout << "��.��������: " << mid << endl;
    // ������� ������� � ���-�� ������ ���������
    cout << "�������: ";
    for (int i = 0; i < N; i++)
    {
        if (A[i] == mid)
        {
            K += 1;
            cout << i << " ";
        }

    }
    cout << "����������: " << K << endl;

    //  5. ���-�� ���������� ������ � ������ ���������� �����
    cout << endl << "task 5 & 6" << endl;
    int p = 1;
    while (p != 0)
    {
        cout << "������� �����: ";
        int a, klv; //klv - ���������� ���������, � - �������� �����
        klv = 0;
        cin >> a;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > a)
            {
                klv += 1;
            }

        }
        cout << "���������� ��������� ������ ���������� �����: " << klv << endl;
        cout << endl;
        cout << "������� 0, ���� ������ ���������, ��� ������� 1, ����� ����������" << endl;
        cin >> p;
        cout << endl;
    }
    p = 1;
    while (p != 0)
    {
        cout << "������� �����: ";
        int b, klv2; // klv2 - ����������, b - �������� �����
        klv2 = 0;
        cin >> b;
        for (int i = 0; i < N; i++)
        {
            if (A[i] < b)
            {
                klv2 += 1;
            }
        }
        cout << "���������� ��������� ������ ���������� �����: " << klv2 << endl;
        cout << endl;
        cout << "������� 0, ���� ������ ���������, ��� ������� 1, ����� ����������" << endl;
        cin >> p;
        cout << endl;
    }


    // 8. ������ ���������
    cout << endl << "task 8" << endl;
    int t, u, h;
    p = 1;
    while (p != 0)
    {
        cout << "������� ����� 1: ";
        cin >> u;
        cout << "������� ����� 2: ";
        cin >> h;
        system_clock::time_point start3 = system_clock::now();
        t = A[u];
        A[u] = A[h];
        A[h] = t;
        system_clock::time_point end3 = system_clock::now();
        duration<double> sec3 = end3 - start3;
        cout << endl << "����� ������:" << sec3.count() << endl;
        cout << endl << endl << "��������� ����� ������: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << A[i] << " ";
        }

        cout << endl << "������� 0, ���� ������ ���������, ��� ������� 1, ����� ����������" << endl;
        cin >> p;
        cout << endl;
    }

}