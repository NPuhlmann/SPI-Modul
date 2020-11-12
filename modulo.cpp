#include <iostream>

using namespace std;

int mod(int number, int modul)
{
    bool modulIsNegativ = false;
    if (number == modul || number == (modul * -1) || (number * -1) == modul)
    {
        return 0;
    }
    if (modul < 0)
    {
        modulIsNegativ = true;
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

        if (modulIsNegativ)
        {
            return mod(number * -1, modul * -1) * -1;
        }
        int solution = mod(number * -1, modul);
        return solution * -1;
    }
}

int main()
{
    int num, modul;
    string answer;
    cout << "Geben Sie eine Ganzzahl ein: ";
    cin >> num;
    cout << "Geben Sie den Modul ein: ";
    cin >> modul;
    cout << "Ergebnis: " << mod(num, modul) << endl;
    cout << "wanna see Solutions? y/n : ";
    cin >> answer;
    int compare = answer.compare("y");
    if (compare == 0)
    {
        cout << "87654 mod 13 =" << 87654 % 13 << endl;
        cout << "-87654 mod 13 =" << -87654 % 13 << endl;
        cout << "87654 mod -13 =" << 87654 % -13 << endl;
        cout << "-87654 mod -13 =" << -87654 % -13 << endl;
        cout << "10 mod 10 =" << 10 % 10 << endl;
    }
    else
    {
        cout << "Bye!" << endl;
    }
    return 0;
}