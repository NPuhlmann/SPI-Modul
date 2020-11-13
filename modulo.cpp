#include <iostream>
#include <stdio.h>
#include <cmath>
#include <tuple>

using namespace std;

void findFactors(long long n)
{
    long long x = 0;

    while (true)
    {
        x++;
        long long y = 0;
        while (y <= x)
        {
            y++;
            if (n == pow(x, 2) - pow(y, 2))
            {
                cout << "Factors are: " << x << " and " << y << endl;
                return;
            }
        }
    }
}

void prime(long long num)
{
    // since fermat's factorization applicable
    // for odd positive integers only
    while (num % 2 == 0)
    {
        cout << 2 << " " << endl;
        num = num / 2;
    }
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            cout << i << " " << endl;
            num = num / i;
        }
    }
    if (num > 2)
    {
        cout << num << " " << endl;
    }
}

int mod(int number, int modul)
{
    // bool modulIsNegativ = false;
    // if (number == modul || number == (modul * -1) || (number * -1) == modul)
    // {
    //     return 0;
    // }
    // if (modul < 0)
    // {
    //     modulIsNegativ = true;
    //     modul = modul * -1;
    // }
    // if (number > 0)
    // {
    //     while (number >= modul)
    //     {
    //         number -= modul;
    //     }

    //     return number;
    // }
    // else
    // {

    //     if (modulIsNegativ)
    //     {
    //         return mod(number * -1, modul * -1) * -1;
    //     }
    //     int solution = mod(number * -1, modul);
    //     return solution * -1;
    // }

    int result = 0;
    int devisor = number / modul;
    result = number - modul * devisor;
    return result;
}

int main()
{
    findFactors(56);
    prime(117723949419918377);
    int num, modul, a, b;
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

    cout << "Bye!" << endl;
    return 0;
}