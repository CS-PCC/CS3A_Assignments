#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

class Counter{
public:
  //constructor: CTOR
  //same name as the class, NO RETURN TYPE:
  Counter();
  Counter(int c);
  //(public) member functions

  // --------------- BIG 3 ---------------
  Counter(const Counter& other); //copy CTOR
  Counter& operator =(const Counter& rhs);  //assignment operator
  ~Counter(); //Destructor: squiggly + class name + no args.
  // -------------------------------------
  
  void inc();
  void dec();
  void reset();
  void show() const;
  int count() const;
  Counter add(const Counter &left, const Counter &right);
  //------------------
  bool error() const ;    //returns the value of the _error flag
  bool is_error() const;  //checks to see if an error has occurred.
  string error_descr();   //returns a description of the error
  // ----------------

  friend Counter operator + (const Counter &left, const Counter &right);
  friend ostream& operator << (ostream &outs, const Counter &print_me);
  friend istream& operator >> (istream &ins, Counter &read_me);

private:
  int _count;   //member variables
  bool _error;
};

#endif // COUNTER_H
