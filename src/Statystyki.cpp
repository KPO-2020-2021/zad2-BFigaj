#include "Statystyki.hh"
#include <iostream>

using namespace std;
/*!
 * Funkcja statystyki
 * Przyjmuje:
 *  int dobry-ilosc dobrych odpowiedzi
 *  int zly-ilosc zlych odpowiedzi
 * Dzialanie:
 *  Funkcja wypisuje statysyki na podstawie danych wyslanych do funkcji
 */
void stat(int dobre ,int zle)
{
    
    cout <<"Ilosc poprawnych odpowiedzi to: " << dobre << endl;
    cout <<"Ilosc niepoprawnych odpowiedzi: " << zle << endl;
    if (dobre!=0)
    {
        
        cout << "Wynik procentowy to: "<< (int)(((dobre*100)/(dobre+zle))) <<"%"<< endl;
    }
    else
        cout << "Chyba trzeba powtorzyc arytmetyke liczb zespolonych: 0%" << endl;
}

