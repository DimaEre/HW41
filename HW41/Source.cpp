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
    long int рахунок;
    short int день;
    short int тиждень;
    short int м≥с€ць;

    void додати(long int р, short int д, short int т, short int м)
    {
        рахунок = р;
        день = д;
        тиждень = т;
        м≥с€ць = м;
    }
    
    void видалити()
    {
        рахунок = 0;
        день = 0;
        тиждень = 0;
        м≥с€ць = 0;
    }
};
void сортуванн€(int size, short int метод, finance* класс)
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
            finances[size].додати(r, d, t, m);
            size++;
        }
        
    }
    while (true)
    {
        cout << "\nћеню:\n"
            << "0 - видалити витрату\n"
            << "1 - додати витрату\n"
            << "2 - розрахуватись з витратою\n"
            << "3 - впор€дкувати\n"
            << "4 - зберегти рахунки\n"
            << "5 - вивести ус≥ рахунки\n";
        cin >> command;
        if (command == 0)
        {
            cout << "¬вед≥ть номер рахунку(починаючи з 0): ";
            finances[command].видалити();
        }
        else if (command == 1)
        {
            r = 0, d = 0, t = 0, m = 0;
            while ((m <= 0 || m > 12) || ((m == 2 && d > 29) || (m % 2 == 0 && d > 30) || (m % 2 != 0 && d > 31)))
            {
                 cout << "–ахунок:   ";
                 cin >> r;
                 cout << "ƒень: ";
                 cin >> d;
                 t = d / 7;
                 cout << "ћ≥с€ць:";
                 cin >> m;
            }
            finances[size].додати(r, d, t, m);
            size++;
        }
        else if (command == 2)
        {
            command = size + 1;
            while (command > size)
            {
                cout << "¬вед≥ть номер рахунку, з €ким хочете розрахуватись:    ";
                cin >> command;
            }

            if (finances[command].рахунок > 0)
            {
                cout << "–ахунок вже оплачений\n";
            }
            else
            {
                finances[command].рахунок = 0 - finances[command].рахунок;
                cout << "–ахунок оплачено.\n";
            }
        }
        else if (command == 3)
        {
            command = 0;
            cout << "¬вед≥ть метод(1 - за дн€ми,2 - за тижн€ми,3 - за м≥с€ц€ми):  ";
            cin >> command;
            if (command <= 0 || command > 3)
            {
                cout << "\nћетод з цим номером не знайдено\n";
            }
            else  сортуванн€(size, command, finances);
        }
        else if (command == 4)
        {
            for (size_t i = 0; i < size; i++)
            {
                if (finances[i].рахунок != 0 && finances[i].м≥с€ць != 0 && finances[i].тиждень != 0 && finances[i].день != 0)
                {
                    fout << finances[i].рахунок << " " << finances[i].день << " " << finances[i].тиждень << " " << finances[i].м≥с€ць << " ";
                }
            }
        }
        else if (command == 5)
        {
            for (size_t i = 0; i < size; i++)
            {
                cout << finances[i].рахунок << " " << finances[i].день << "." << finances[i].тиждень << "." << finances[i].м≥с€ць << endl;
            }
        }
        else
        {
            cout << "Unknown command";
        }
    }
}