#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <windows.h>
using namespace std;

int hashSqr(int s)
{
    int B = 100;
    int P;
    P = ((s * s) / B) % B;
    return P;
};

int hashMod(int s, int N)
{
    int P = s % N;
    return P;
}

int hashFr(int s)
{
    int P = (s % 100) + (s / 100);
    return P;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    int c = 0;

    cout << "K��������� ������: ";
    cin >> N;
    cout << endl;
    int* arrayA = new int[N];

    int array[1000] = { 0 }; // ���
    int collisions = 0;
    int array1[1000] = { 0 }; // ������
    int collisions1 = 0;
    int array2[1000] = { 0 }; // �������� ������
    int collisions2 = 0;

    FILE* file = NULL;
    // ����� ����� ��� ����������
    switch (N)
    {
    case(10):
        file = fopen("C:\\Users\\user\\lr5_hash\\h10.txt", "r");
        break;
    case(20):
        file = fopen("C:\\Users\\user\\lr5_hash\\h20.txt", "r");
        break;
    case(30):
        file = fopen("C:\\Users\\user\\lr5_hash\\h30.txt", "r");
        break;
    case(40):
        file = fopen("C:\\Users\\user\\lr5_hash\\h40.txt", "r");
        break;
    case(50):
        file = fopen("C:\\Users\\user\\lr5_hash\\h50.txt", "r");
        break;
    case(100):
        file = fopen("C:\\Users\\user\\lr5_hash\\h100.txt", "r");
        break;
    }
    cout << "�������� �����: ";
    for (int i = 0; i < N; i++)
    {
        fscanf(file, "%d", &arrayA[i]);
        cout << arrayA[i] << " ";
    }
    fclose(file);
    cout << endl << endl;

    for (int i = 0; i < N; i++)
    {
        c = hashSqr(arrayA[i]);
        cout << c << " ";
        array[c] = array[c] + 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (array[i] != 0)
            collisions = collisions + array[i] - 1;
    }
    cout << endl << "����� \"������� ����� ��������\".";
    cout << endl << "���������� ��������: " << collisions << endl << endl;

    for (int i = 0; i < N; i++)
    {
        c = hashMod(arrayA[i], N);
        cout << c << " ";
        array1[c] = array1[c] + 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (array1[i] != 0)
            collisions1 = collisions1 + array1[i] - 1;
    }
    cout << endl << "����� \"������� �� ������ N\".";
    cout << endl << "���������� ��������: " << collisions1 << endl << endl;

    for (int i = 0; i < N; i++)
    {
        c = hashFr(arrayA[i]);
        cout << c << " ";
        array2[c] = array2[c] + 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (array2[i] != 0)
            collisions2 = collisions2 + array2[i] - 1;
    }
    cout << endl << "����� \"��������� �� ����� � ��������\".";
    cout << endl << "���������� ��������: " << collisions2 << endl << endl;
}