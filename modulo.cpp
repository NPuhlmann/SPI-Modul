#include <iostream>

using namespace std;

int mod(int number, int modul)
{

    if (modul < 0)
    {
        modul = modul * -1;
    }
    if (number > 0)
    {
        while (number >= modul)
        {
            number -= modul;
        }
        return number;
    }
    else
    {
        while (number < 0)
        {
            number += modul;
        }
        return number;
    }
}

int main()
{
    int num, modul;
    cout << "Geben Sie eine Ganzzahl ein: ";
    cin >> num;
    cout << "Geben Sie den Modul ein: ";
    cin >> modul;
    cout << "Ergebnis: " << mod(num, modul) << endl;
    return 0;
}