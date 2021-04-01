#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona operator + (LZespolona  Skl2) const;
  LZespolona operator + () const;
  LZespolona operator - (LZespolona  Skl2) const;
  LZespolona operator - () const;
  LZespolona operator * (LZespolona  Skl2) const;
  LZespolona operator * (double  Skl2) const;
  LZespolona operator / (double  Skl2) const;
  LZespolona operator / (LZespolona  Skl2) const;
  bool operator == (LZespolona Skl2) const;
  LZespolona operator +=(LZespolona Skl2) const;
  LZespolona operator /=(LZespolona Skl2) const;
  double arg() const;
};


/*
 * Poniewaz operatora mnozenia gdzie liczba jest z lewej 
 * da sie zrobic w formie metody jest jako funkcja 
 */
LZespolona operator * (double  Skl2,const LZespolona &Skl1);
LZespolona sprzezenie (LZespolona Skl1);






#endif
