
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{

    Date d1(21,06,2024);
    cout << "Pierwsza data: " << d1 << endl;


    Date d2(31,12,1900);
    cout << "Druga data: " << d2 << endl;

    
    cout << "Roznica dat: " << (d1 - d2) << " dni" << endl << endl;

    d1 += 1000;
    cout << "Pierwsza data za 1000 dni: " << d1 << endl;

    cout << "Czy rok " << d2.get_year() << " jest przestepny?";
    if (Date::is_leap(d2.get_year())) {
        cout << " Tak" << endl;
    }
    else {
        cout << " Nie" << endl;
    }
    int i;
    cin >> i;


 }

