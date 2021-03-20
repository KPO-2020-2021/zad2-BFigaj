#include <iostream>
#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Odsyla liczbe przed ktora jest +, a nie jest to operacja dodawania.
 * Argumenty:
 *    Skl1 - skladnik ,
 *    
 * Zwraca:
 *    Niezmieniony skladnik.
 */
LZespolona operator + (LZespolona  Skl1)
{
  return Skl1;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!
 * Zmienia znak danej liczby przed ktora stoi -, a nie jest to odejmowanie.
 * Argumenty:
 *    Skl1 - skladnik.
 *    
 * Zwraca:
 *    Skladnik z przeciwnymi znakami czesci zespolonej i urojonej.
 */
LZespolona operator - (LZespolona  Skl1)
{
  Skl1.re = -Skl1.re;
  Skl1.im = -Skl1.im;
  return Skl1;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch liczb zespolonych.
 */
LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re=(Skl1.re * Skl2.re)-(Skl1.im * Skl2.im);
  Wynik.im=(Skl1.re * Skl2.im)+(Skl1.im * Skl2.re);
  return Wynik;
}
/*!
 * Realizuje mnozenia liczby zespolonej przez liczbe rzeczywista.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 *    Skl2 - liczba rzeczywista.
 * Zwraca:
 *    Liczbe zespolona pomnozona przez liczbe rzeczywista.
 */
LZespolona operator * (LZespolona  Skl1,double Skl2)
{
  LZespolona  Wynik;

  Wynik.re=(Skl1.re * Skl2);
  Wynik.im=(Skl1.im * Skl2);
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * Zalozenia:
 *    Skl2 nie moze byc rowne zero.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 *    Skl2 - liczba rzeczywista.
 * Zwraca:
 *    Liczbe zespolona podzielona przez liczbe rzeczywista.
 */
LZespolona operator / (LZespolona  Skl1,double  Skl2)
{
  LZespolona  Wynik;
  if (Skl2==0)
  {
    std::cerr << "Blad nie dziel przez zero"<< std::endl;
  }
  Wynik.re=Skl1.re/(Skl2);
  Wynik.im=Skl1.im/(Skl2);
  return Wynik;
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Zalozenia:
 *    Skl2 nie moze byc rowne zero.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz liczb zespolonych.
 */
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik,spzerzenie,u,d;
  int s;
  if (Skl2.re==0 && Skl2.im==0)
  {
    std::cerr << "Blad nie dziel przez zero"<< std::endl;
  }
  spzerzenie.re=Skl2.re;
  spzerzenie.im=-Skl2.im;
  u=Skl1 * spzerzenie;
  d=Skl2 * spzerzenie;
  s=(d.re+d.im);
  Wynik=u / s;
  return Wynik;
}
/*!
 * Funkcja operatorowa sprawdzajaca 2 liczby zespolone.
 * Argumenty:
 *    Skl1 - liczba zespolona 1,
 *    Skl2 - liczba zespolona 2.
 * Zwraca:
 *    True-jesli czesci zeczywiste i urojone sa rowne.
 *    False-jesli czesci zeczywiste albo urojone sa sobie nie rowne.
 */
bool operator ==(LZespolona Skl1,  LZespolona Skl2)
{
  if ((Skl1.re==Skl2.re) && (Skl1.im==Skl2.im))
    return true;
  return false;
}


