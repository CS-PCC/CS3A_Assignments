#include "counter.h"

const int MAX_COUNTER = 20;

Counter::Counter() {
  const bool debug = true;
  if (debug)
    cout << "ZERO arg CTOR..." << endl;
  _count = 0;
}

Counter::Counter(int c) {
  const bool debug = true;
  if (debug)
    cout << "ONE arg CTOR("<<c<<")" << endl;
  _count = c;
  _error = is_error();
  if (error()){
    _count = -9999;
  }
}

void Counter::inc() {
  const bool debug = false;
  if (error())
    return;
  if (debug)
    cout << "incrementing..." << endl;
  if(_count <MAX_COUNTER)
    _count++;
}

// --------------- BIG 3 ---------------
Counter::Counter(const Counter& other) {
  cout << "CopyCTOR other: " << other << endl;
  //1. copy all non dynamic member variables.
  _count = other._count;
  _error = other._error;
  //2. allocate space for this object
  //    call your allocate function.
  //3. copy the dynamic block from other to this object.
  //  call your copy function.
}

Counter& Counter::operator =(const Counter& rhs) {
  // c1 = c5;  => c1.operator=(c5);
  cout << "assignment operator: "<<*this <<" = " << rhs << endl;
  //1. check for self reference.
  //2. copy all (non-dynamic) member variables.
  _count = rhs._count;
  _error = rhs._error;
  // p-->[   a, b, c, d             ]
  // rhs.p --->[  1,2,3,4,5,6,7,8  ]
  // 3. release dynamic memory for this object.
  // delete p;   //p--->|||
  // 4. allocate space and copy from rhs
  //allocate space as big as rhs's p:
  //p --->>[                          ]
  //copy from rhs.p into my p:
  //p -->>[  1,2,3,4,5,6,7,8  ]

  return *this;
}

Counter::~Counter() {
  cout << "destructor: " << *this << endl;
  //clear function, or delete[]
}

void Counter::dec() {
  const bool debug = false;
  if (error())
    return;
  if (debug)
    cout << "decrementing..." << endl;

  _count--;
  _error = is_error();
  if(error())
    _count = -9999;
}

void Counter::reset() {
  const bool debug = false;
  if (debug)
    cout << "restting..." << endl;
  _count = 0;
  _error = false;
}

void Counter::show() const {
  const bool debug = false;
  if (debug)
    cout << "showing..." << endl;
  cout <<"{"<< _count
        << "}" << endl;
}

int Counter::count() const {
  return _count;
}

Counter Counter::add(const Counter &left, const Counter &right) {
  Counter total;
  int sum = left.count() + right.count(); //uses accessor function
  sum = left._count + right._count;       //private member variable directly.
  
  //TERRIBLE IDEA!!!!!
  //Never alter the private member variables of a class in this way.
  //total._count = sum;

  //Good way:
  //always initialize member variables of a function through the ctors.
  total = Counter(sum);   //the right way.
  return total;

  //or...
  //Counter total_alt(sum); //just as good.
  //now return the total object.
  //return total_alt;   
}

Counter operator +(const Counter& left, const Counter& right) {
  int l = left._count;
  int r = right._count;
  int sum = l + r;
  //invokes the one arg ctor of Counter. Creates a temp object and returns it.
  return Counter(sum);
}

ostream &operator<<(ostream &outs, const Counter &print_me) {
  outs << "[" << setw(4) << print_me._count << "]";

  return outs;
}

istream &operator>>(istream &ins, Counter &read_me) {
  int count;
  ins >> count;
  read_me = Counter(count);
  return ins;
}

//----------------------------------
bool Counter::error() const {
  //returns the value of the _error flag
  return _error;
}

bool Counter::is_error() const {
  //checks to see if an error has occurred.
  if (_count < 0)
    return true;
  return false;
  // return _count < 0;
}

string Counter::error_descr(){
  //returns a description of the error
  return "_count is negative.";
}
