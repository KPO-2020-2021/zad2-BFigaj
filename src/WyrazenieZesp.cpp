#include <iostream>
#include "WyrazenieZesp.hh"

using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
/* przeciazenie operatora >> 
 * funkcja zaimplementowana na podstawie
 * pomyslu Pana Janca, lekko zmodyfikowana
 * Dialanie:
 *  funkcja zczytuje poszczegolne elementy ze strumienia wejsciowego
 *  by nastepnie poprzez referencje zmienic wartosc liczby zespolonej
 *  na takie ktore zostaly wczytane. Jezeli w ktoryms momencie liczba
 *  wpisana przez uzytkownika nie bedzie sie zgadac funkcja sie konczy
 *  bac, gdy strumien przejdzie w stan fail 
 * Uwagi:
 *  gdy wpisze sie sam ( lub ) to program sie zacina 
 */
istream& operator >> (istream &wej,LZespolona &lzesp)
{
    char nawias,i;
    wej >> nawias;
    if(wej.fail())
        return wej;
    if(nawias != '(')
    {
        wej.setstate(ios::failbit);
        return wej;
    }
    wej >> lzesp.re;
    if(wej.fail())
        return wej;
    wej >> lzesp.im;
    if(wej.fail())
        return wej;
    wej >> i;
    if (i!='i')
    {
        wej.setstate(ios::failbit);
        return wej;
    }
    wej >> nawias;
    if(wej.fail())
        return wej;
    if(nawias != ')')
    {
        wej.setstate(ios::failbit);
        return wej;
    }
    return wej;
}
/*przeciazenie << , wysietla liczbe zespolona*/
ostream& operator << (ostream &wyj,LZespolona lzesp)
{
    if(wyj.fail())
        return wyj;
    if(lzesp.im >= 0)
    {
        wyj << "(" << lzesp.re << "+" << lzesp.im << "i)" ;
        return wyj;
    }
    else
    {
        wyj << "(" << lzesp.re << lzesp.im << "i)" ;
        return wyj;
    }
}
/*funkcja sprawdza wartosc WyrZ.Op by okreslic jaki to operator by go wyswietlic*/
void Wyswietl(WyrazenieZesp  WyrZ)
{
    if(WyrZ.Op==0)
    {
        cout << WyrZ.Arg1 ;
        cout << " + ";
        cout << WyrZ.Arg2 << endl;
    }
    if(WyrZ.Op==1)
    {
        cout << WyrZ.Arg1 ;
        cout << " - ";
        cout << WyrZ.Arg2 << endl;
    }
    if(WyrZ.Op==2)
    {
        cout << WyrZ.Arg1 ;
        cout << " * ";
        cout << WyrZ.Arg2 << endl;
    }
    if(WyrZ.Op==3)
    {
        cout << WyrZ.Arg1 ;
        cout << " / ";
        cout << WyrZ.Arg2 << endl ;
    }
}
/*Funkcja oblicza wartosci liczb zespolonych
poprzez przeciazenia operatorow arytmetycznych*/
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    if(WyrZ.Op==0)
    {
        return (WyrZ.Arg1 + WyrZ.Arg2);
    }
    if(WyrZ.Op==1)
    {
        return (WyrZ.Arg1 - WyrZ.Arg2);
    }
    if(WyrZ.Op==2)
    {
        return (WyrZ.Arg1 * WyrZ.Arg2);
    }
    return (WyrZ.Arg1 / WyrZ.Arg2);
}
