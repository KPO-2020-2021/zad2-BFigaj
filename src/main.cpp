#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
  LZespolona odpowiedz,sprawdzenie;
  int i,dobre=0,zle=0;
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Podaj wartosc wyrazenia: ";
    Wyswietl(WyrZ_PytanieTestowe);
    cout << " Twoja odpowiedz: ";
    cin >> odpowiedz;/*Wczytujemy odpowiedz uzytkownika jako liczbe zespolona*/
    while (cin.fail())
    {
        cout << " Blad. Wpisz ponownie" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> odpowiedz;
    }
    sprawdzenie=Oblicz(WyrZ_PytanieTestowe);/*obliczamy poprawna wartosc liczby zespolonej*/
    i=3;/*indeksujemy ilosc prob dodatkowych*/
    while (i!=0)
    {
      i=i-1;
      if(odpowiedz == sprawdzenie)/*sprawdzamy czy wartosc wpisana przez uzytkownika jest taka sama jak obliczona*/
      {
        dobre=dobre+1;
        cout << " Odpowiedz poprawna :D" << endl;
        i=0;
      }
      else/*w przeciwnym przypadku informujemy o tym ze jest bladna i powtarzamy cala petle*/
      {
        zle=zle+1;
        cout << " Odpowiedz bledna :(" << endl;
        cout << " Masz jeszcze "<< i+1 << ". proby " << endl;/*piszemy uzytkownikowi ile ma jeszcze prob*/
        cout << " Twoja odpowiedz: ";
        cin >> odpowiedz;
        while (cin.fail())
        {
          cout << " Blad. Wpisz ponownie" << endl;
          cin.clear();
          cin.ignore(10000,'\n');
          cin >> odpowiedz;
        }
      }
      
    }
    cout << " Poprawna odpowiedz to: "<< sprawdzenie << endl;
    
    
    
    
  }

  stat(dobre,zle);/*wywolujemy funkcje statystyki*/
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
