#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;


class finance
{
public:
    long int �������;
    short int ����;
    short int �������;
    short int �����;

    void ������(long int �, short int �, short int �, short int �)
    {
        ������� = �;
        ���� = �;
        ������� = �;
        ����� = �;
    }
    
    void ��������()
    {
        ������� = 0;
        ���� = 0;
        ������� = 0;
        ����� = 0;
    }
};
void ����������(int size, short int �����, finance* �����)
{
   
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string file = "file.cpp";
    ifstream fin;
    fin.open(file);
    ofstream fout;
    fout.open(file);
    if (!fin)
    {
        cout << "\nFILE WASN'T FOUND\n";
        return 0;
    }


    long int r = 0, size = 0;
    short int d = 0, t = 0, m = 0, command = 0;
    finance* finances = new finance [100];

    while (!fin.eof())
    {
        fin >> r;
        fin >> d;
        fin >> t; 
        fin >> m;
        if (r != 0 && d != 0 && t != 0 && m != 0)
        {
            finances[size].������(r, d, t, m);
            size++;
        }
        
    }
    while (true)
    {
        cout << "\n����:\n"
            << "0 - �������� �������\n"
            << "1 - ������ �������\n"
            << "2 - ������������� � ��������\n"
            << "3 - ������������\n"
            << "4 - �������� �������\n"
            << "5 - ������� �� �������\n";
        cin >> command;
        if (command == 0)
        {
            cout << "������ ����� �������(��������� � 0): ";
            finances[command].��������();
        }
        else if (command == 1)
        {
            r = 0, d = 0, t = 0, m = 0;
            while ((m <= 0 || m > 12) || ((m == 2 && d > 29) || (m % 2 == 0 && d > 30) || (m % 2 != 0 && d > 31)))
            {
                 cout << "�������:   ";
                 cin >> r;
                 cout << "����: ";
                 cin >> d;
                 t = d / 7;
                 cout << "̳����:";
                 cin >> m;
            }
            finances[size].������(r, d, t, m);
            size++;
        }
        else if (command == 2)
        {
            command = size + 1;
            while (command > size)
            {
                cout << "������ ����� �������, � ���� ������ �������������:    ";
                cin >> command;
            }

            if (finances[command].������� > 0)
            {
                cout << "������� ��� ���������\n";
            }
            else
            {
                finances[command].������� = 0 - finances[command].�������;
                cout << "������� ��������.\n";
            }
        }
        else if (command == 3)
        {
            command = 0;
            cout << "������ �����(1 - �� �����,2 - �� �������,3 - �� �������):  ";
            cin >> command;
            if (command <= 0 || command > 3)
            {
                cout << "\n����� � ��� ������� �� ��������\n";
            }
            else  ����������(size, command, finances);
        }
        else if (command == 4)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (finances[i].������� != 0 && finances[i].����� != 0 && finances[i].������� != 0 && finances[i].���� != 0)
                {
                    fout << finances[i].������� << " " << finances[i].���� << " " << finances[i].������� << " " << finances[i].����� << " ";
                }
            }
        }
        else if (command == 5)
        {
            for (size_t i = 0; i < size; i++)
            {
                cout << finances[i].������� << " " << finances[i].���� << "." << finances[i].������� << "." << finances[i].����� << endl;
            }
        }
        else
        {
            cout << "Unknown command";
        }
    }
}