#ifndef POSINT_H
#define POSINT_H

#include <iostream>
#include <string>

using namespace std;

class PosInt
{
public:
  //CTORS:
  PosInt();
  PosInt(int posNumb);

  //Mutators
  void Set(int posNumb);

  //Accessors
  int Get() const;

  //member functions
  PosInt add(PosInt other);
  //increment and decrement operators:
  PosInt& operator ++ ();               //prefix
  PosInt operator ++ (int notUsed);     //postfix

  friend PosInt operator + (const PosInt& left, const PosInt& right);

  friend ostream& operator<<(ostream& out, const PosInt &printMe);
  friend istream& operator>>(istream& ins, PosInt &inputMe);

  PosInt sub(PosInt other);
  void show();

  //Error functions:
  int Error(); //returns the value of error
  void Clear(); //resets the value of error
  string ErrorDescr(int e); //gives you the descr of error
private:
  int i;
  int error;
};

// Definition

#endif // POSINT_H