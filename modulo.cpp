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

tuple<int, int> prime(int num)
{
    // since fermat's factorization applicable
    // for odd positive integers only
    if (num <= 0)
    {
        return tuple<int, int>{num, num};
    }

    // check if n is a even number
    if ((num & 1) == 0)
    {
        return tuple<int, int>{num / 2, 2};
    }

    int x = ceil(sqrt(num));

    if (pow(x, x) == num)
    {
        return tuple<int, int>{x, x};
    }

    int r = pow(x, 2) - num;
    while (r % r != 0)
    {
        r = r + 2 * x + 1;
        x += 1;
    }
    int y = sqrt(r);
    int a = x + y;
    int b = x - y;

    return tuple<int, int>{a, b};
}

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
    findFactors(56);
    int num, modul, a, b;
    string answer;
    cout << "Primfaktor? y/n : ";
    cin >> answer;
    int compare = answer.compare("y");
    if (compare == 0)
    {
        cout << "Geben Sie eine Ganzzahl ein: ";
        cin >> num;
        std::tie(a, b) = prime(num);
        cout << "Ergebnis: " << a << ", " << b << endl;
    }
    else
    {
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
    }
    cout << "Bye!" << endl;
    return 0;
}