#include <iostream>
#include <bits/stdc++.h>
#include "LZespolona.hh"
#define Min_dif 0.01


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    this - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}
/*!
 * Odsyla liczbe przed ktora jest +, a nie jest to operacja dodawania.
 * Argumenty:
 *    this - skladnik ,
 *    
 * Zwraca:
 *    Niezmieniony skladnik.
 */
LZespolona LZespolona::operator + () const
{
  return *this;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    this - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
/*!
 * Zmienia znak danej liczby przed ktora stoi -, a nie jest to odejmowanie.
 * Argumenty:
 *    this - skladnik.
 *    
 * Zwraca:
 *    Skladnik z przeciwnymi znakami czesci zespolonej i urojonej.
 */
LZespolona LZespolona::operator - () const
{
  LZespolona Wynik;
  Wynik.re = -this->re;
  Wynik.im = -this->im;
  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch liczb zespolonych.
 */
LZespolona LZespolona::operator * (LZespolona  Skl2) const
{
  LZespolona  Wynik;
  Wynik.re=(this->re * Skl2.re)-(this->im * Skl2.im);
  Wynik.im=(this->re * Skl2.im)+(this->im * Skl2.re);
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
LZespolona LZespolona::operator * (double Skl2) const
{
  LZespolona  Wynik;
  Wynik.re=(this->re * Skl2);
  Wynik.im=(this->im * Skl2);
  return Wynik;
}
/*!
 * Realizuje mnozenia liczby zespolonej przez liczbe rzeczywista.
 * Jesli liczba rzeczywista stoi przed liczba zespolona.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 *    Skl2 - liczba rzeczywista.
 * Zwraca:
 *    Liczbe zespolona pomnozona przez liczbe rzeczywista.
 */
LZespolona operator * (double  Skl2,const LZespolona &Skl1)
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
LZespolona LZespolona::operator / (double  Skl2) const
{
  LZespolona  Wynik;

  if (Skl2==0)
  {
    std::cerr << "Blad nie dziel przez zero"<< std::endl;
    Wynik.re=0;
    Wynik.im=0;
    return Wynik;
  }
  Wynik.re=this->re/(Skl2);
  Wynik.im=this->im/(Skl2);
  return Wynik;
}
/*!
 * Tworzy sprzezenie liczby zespolonej
 */
LZespolona sprzezenie(LZespolona Skl1) 
{
  LZespolona  Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=-Skl1.im;
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
LZespolona LZespolona::operator / (LZespolona  Skl2) const
{
  LZespolona  Wynik,sprzeze,u,d;
  int s;
  if (Skl2.re==0 && Skl2.im==0)
  {
    std::cerr << "Blad nie dziel przez zero"<< std::endl;
    return Skl2;
  }
  sprzeze=sprzezenie(Skl2);
  u=*this * sprzeze;
  d=Skl2 * sprzeze;
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
bool LZespolona::operator ==(LZespolona Skl2) const
{
  if ((std::abs(this->re - Skl2.re)<= Min_dif) && (std::abs(this->im - Skl2.im)<= Min_dif))
    return true;
  return false;
}
LZespolona LZespolona::operator += (LZespolona Skl2) const
{
  Skl2.re+=this->re;
  Skl2.im+=this->im;
  return Skl2;
}
LZespolona LZespolona::operator /= (LZespolona Skl2) const
{
  Skl2=*this / Skl2;
  return Skl2;
}
/*!
 * Funkcja zwraca argument glowny liczby zespolonej
 * 
 */
double LZespolona::arg() const
{
  double wynik;
  if (this->re > 0)
  {
    wynik=atan2(this->im,this->re);
    std::cout << wynik  << std::endl;
    return wynik;
  }
  else
  {
    if(this->re < 0)
    {
      wynik=atan2(this->im,this->re)+3.14;
      std::cout << wynik << std::endl;
      return wynik;
    }
    else
    {
      std::cerr << "Blad nie zdefinowane dzialanie" << std::endl;
      return 0;
    }
  }
}
