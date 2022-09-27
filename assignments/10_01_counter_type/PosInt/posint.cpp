#include "posint.h"

PosInt::PosInt() : i(0), error(0) {}

//PosInt::PosInt(string s)
PosInt::PosInt(int posNumb) : i(posNumb), error(0)
{
  if (i<0) {
    error = 1;
    i = 0;    //this i is "unreliable" "not a valid int"
  }
  //intend to leave blank
  //don't forget to check for negative value of posNumb
}

void PosInt::Set(int posNumb)
{
  i = posNumb;
  if (i<0){
    error = 1;
    i = 0;    //this i is "unreliable" "not a valid int"
  }
}

int PosInt::Get() const
{
  return i;
}

PosInt PosInt::add(PosInt other)
//the sum can be +/- depends on the input of other so we should create the error function to let the
//main knows about the error
{
  int sum;
  // sum = this->i + other.i;
  sum = i + other.i;
  //PosInt hold(sum);
  //return hold;
  return PosInt(sum);
}

PosInt PosInt::sub(PosInt other)
//the diff can be +/- depends on the input of other, so we should create the error function to let the
//main knows about the error
{
  int diff;
  diff = i - other.i;

  return PosInt(diff);
}

void PosInt::show()
{
  cout<<"i="<< i;
}

//------------------------------------------
//Error functions:
//------------------------------------------
int PosInt::Error()
{
  return error;
}

void PosInt::Clear()
{
  error = 0;
  i =0; //reset private member variables to default values
}

string PosInt::ErrorDescr(int e)
{
  switch (e){
    case 1:
      return "Negative Value Error";
      break;
    default:
      return "UNKNOWN ERROR";
      break;
  }
}

PosInt& PosInt::operator ++ ()
{
  //prefix: ++i
  i += 100;
  return *this;
}

PosInt PosInt::operator ++ (int notUsed)
{
  //postfix: i++
  int hold = i;
  i++;
  return PosInt(hold);
}

PosInt operator +(const PosInt& left, const PosInt& right)
{
  return PosInt(left.i + right.i);
}


ostream& operator<<(ostream& out, const PosInt &printMe)
{
  out<<"["<<printMe.i<<"]";
  return out;
}

istream& operator>>(istream& ins, PosInt &inputMe)
{
  ins>>inputMe.i;
  return ins;
}
