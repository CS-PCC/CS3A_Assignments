#include <iostream>
#include <iomanip>

#include "array_functions.h"

using namespace std;

int main() {
  cout << "\n" << endl;

  //------------------ Reference ------------------//
  int i = 42;
  int j = 17;
  int x = 10;
  cout << " i = " <<  i << endl;
  cout << "&i = " << &i << endl;
  cout << "---------------------------------" << endl;

  // Because references are not objects, there are
  // no arrays of references,     int& a[3]; // error
  // no pointers to references,   int&* p;   // error
  // no references to references, int& &r;   // error

  // It is permitted to form references to references 
  // through type manipulations in templates or typedefs
  // typedef int&  lref;
  // typedef int&& rref;
  // int n;
  // lref&  r1 = n; // type of r1 is int&
  // lref&& r2 = n; // type of r2 is int&
  // rref&  r3 = n; // type of r3 is int&
  // rref&& r4 = 1; // type of r4 is int&&


  int& ref = x; // ref is a reference to x.
  ref = 20;
  cout << "   x = " << x << endl;
  cout << " ref = " << ref << endl;
  cout << "&ref = " << &ref << endl;
  cout << "---------------------------------" << endl;

  // i = j;           // OK
  // &i = &j;         // error
  // int& ref;        // error
  // int& ref = NULL; // error
  // void &ar = i;    // error
  // &ref = i;        // error


  // NOTE:
  // 1. You cannot have NULL references.
  // 2. Once a reference is initialized to an object,
  //    it cannot be changed to refer to another object.
  // 3. A reference must be initialized when it is created.


  //------------------ Pointer ------------------//

  // Pointers: A pointer is a variable that holds memory address of another variable.
  // A pointer needs to be dereferenced with * operator to access the memory location it points to. 

  // General syntax
  // datatype* var_name;
  int* ptr;

  // To access address of a variable to a pointer, 
  // we use the unary operator & (ampersand) that 
  // returns the address of that variable.
  // For example &x gives us address of variable x. 

  // 1) Since there is * in declaration, ptr
  // becomes a pointer variable (a variable
  // that stores address of another variable)
  // 2) Since there is int before *, ptr is
  // pointer to an integer type variable
  // an int pointer cannot point to a double

  // the name of the variable is ptr
  // the type of this variable is int* 
  // it's an int pointer.
  // BUT, * does not mean pointer.

  int* ptr_i;
  ptr_i = &i; // point ptr_i to address of i

  cout << "ptr_i point to i:" << endl;
  cout << "i      = " << i << endl;
  cout << "&i     = " << &i << endl;
  cout << "ptr_i  = " << ptr_i << endl;
  cout << "*ptr_i = " << *ptr_i << endl;
  cout << "---------------------------------" << endl;

  cout << "ptr_i point to j: ptr_i = &j" << endl;
  ptr_i = &j; // ptr_i points to j
  cout << "j      = " << j << endl;
  cout << "*ptr_i = " << *ptr_i << endl;
  cout << "---------------------------------" << endl;

  cout << "ptr_i point to j and change value of ptr_i:" << endl;
  *ptr_i = 170; // changing value of j by indirect addressing
  cout << "*iptr = " << *ptr_i << endl;
  cout << "j     = " << j << endl;
  cout << "i     = " << i << endl;
  cout << "---------------------------------" << endl;

  // An example pointer "ptr" that holds
  // address of an integer variable or holds
  // address of a memory whose value(s) can
  // be accessed as integer values through "ptr"
  int var = 10;
  cout << "var = " << var << endl;
  
  int* ptr_var = &var;
      *ptr_var = 20;
  cout << "var = " << var << endl;
  
  int** pptr_var = &ptr_var;
      **pptr_var = 30;
  cout << "var = " << var << endl;
  cout << "---------------------------------" << endl;

  //---------------------------------
  //  &: address of: &i gives you the address of i
  //  *: dereferencing: *iptr: what iptr is pointing to.
  //                                the value of it, or..
  //                                the reference of it
  //  *: declaration of a pointer: datatype *var_name:
  //              in this case * means that the variable is
  //              a pointer of the TYPE that precedes it.
  //          e.g. double* dptr; means dptr is a pointer to a 
  //                  double variable / array.


  // Common mistakes when working with pointers

  // ptr_var = var; // Wrong! 
  // ptr_var is an address but var is not
  
  // *ptr_var = &var; // Wrong!
  // &var is an address
  // *ptr_var is the value stored in &var
  
  ptr_var = &var; // Correct! 
  // ptr_var is an address and so is &var
  
  *ptr_var = var; // Correct!
  // both *ptr_var and var are values


  //------------------ Swap ------------------//

  int a = 45, b = 35;
  cout << "Before Swap\n";
  cout << "a = " << a << " b = " << b << "\n";

  // &a is address of a
  // &b is address of b
  swap_pointers(&a, &b);
  // the address of the variable is passed during the function
  // call rather than the variable.

  cout << "After Swap with pass by pointer\n";
  cout << "a = " << a << " b = " << b << "\n";

  int* a_ptr = &a;
  int* b_ptr = &b;
  swap_pointers(a_ptr, b_ptr);
  cout << "After Swap with pass pointer\n";
  cout << "a = " << a << " b = " << b << "\n";

  swap_pointers_ref(a_ptr, b_ptr);
  cout << "After Swap with pass pointer by reference\n";
  cout << "a = " << a << " b = " << b << "\n";
  cout << "---------------------------------" << endl;

  // Note: The * operator is used after the data type to declare pointers
  int* p1; // preferred syntax
  int *p2;


  //------------------ Pointer with Array ------------------//
  const int MAX = 10;
  int arr[MAX] = {0,1,2,3,4,5,6,7,8,9};
  print_array(arr, MAX);

  double darr[MAX] = {0.5,1.5,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
  print_array(darr, MAX);
  cout << "---------------------------------" << endl;

  // call init_array with an array:
  int array[10];
  init_array(array, 7, 42);
  print_array_pointer(array, 7);
  cout << "---------------------------------" << endl;

  // now with a pointer:
  int* p;     // pointer: holds the address of a variable
              // contains GARBAGE: address of some unknown place.

              // NEVER WRITE INTO WHERE AN UNINITIALIZED POINTER IS POINTING TO.
              // POINT A POINTER TO AN ARRAY BEFORE YOU WRITE INTO
  
  // int arr[MAX] = {0,1,2,3,4,5,6,7,8,9};
  print_array_pointer(arr, 10);
  p = arr;  // now, p and array are interchangable.
  cout << "p: " << p << endl;                      // out:ref(0),   p->0
  cout << "*p: " << *p << endl;                    // out:0,        p->0
  cout << "*(p++): " << setw(6) << *(p++) << endl; // out:0,        p->1
  // cout << "*p++: " << setw(6) << *p++ << endl;     // out:0,        p->1
  cout << "p: " << p << endl;                      // out:ref(1),   p->1
  cout << "(*(p++))++: " << setw(2) << (*(p++))++ << endl;// out:1, p->2, arr[1]=2
  cout << "p: " << p << endl;                      // out:ref(2),   p->2
  cout << "*p: " << *p << endl;                    // out:2,        p->2
  cout << "*(p-1): " << setw(6) << *(p-1) << endl; // out:2,        p->2
  // cout << "*p-1: " << setw(6) << *p-1 << endl;     // out:1,        p->2
  cout << "p: " << p << endl;                      // out:ref(2),   p->2
  cout << "*(++p): " << setw(6) << *(++p) << endl; // out:ref(3),   p->3
  // cout << "*++p: " << setw(6) << *++p << endl;     // out:ref(3),   p->3
  cout << "p: " << p << endl;                      // out:ref(3),   p->3
  p -= 3;                                          //               p->0
  cout << "p: " << p << endl;                      // out:ref(0),   p->0
  cout << "---------------------------------" << endl;

  init_array(p, 7, -42);

  print_array_pointer(p, 3);
  print_array_pointer(p, 5);
  print_array_pointer(p, 7);
  cout << "---------------------------------" << endl;
  print_array(p, 3);
  print_array(p, 5);
  print_array(p, 7);
  cout << "---------------------------------" << endl;

  print_array_pointer(arr, 3);
  print_array_pointer(arr, 5);
  print_array_pointer(arr, 7);
  cout << "---------------------------------" << endl;


  //------------------ Dynamic Array ------------------//

  p = allocate<int>(15);
  // p = new int [15];
  // If you call allocate without <int> you will get this syntax error:
  // error: no matching function for call to 'allocate'

  // p is pointing to a dynamically allocated array of size 15.
  // this is not different than p pointing to a static array
  // or the static array itself.
  cout << "Dynamic array is created with size 15" << endl;
  cout << "Initializing the first 12 elements" << endl;
  init_array(p, 12, 55);
  print_array_pointer(p, 12);
  print_array_pointer(p, 22);
  cout << "---------------------------------" << endl;

  try_walker(p, 12);
  cout << "Print pointer in main:\n";
  print_array_pointer(p, 12);
  cout << "---------------------------------" << endl;

  cout << "delete it: delete[] p;" << endl;
  delete[] p;     // delete needs the address of the block you are deleting.
                  // if somehow you lose that address, you cannot delete the space
                  // and you will have a memory leak.
                  // this is bad. 
  cout << "---------------------------------" << endl;
  // print_array_pointer(p, 12); // error
  // NEVER access a pointer after deleting it.

  // deleting a pointer that has not been allocated:
  // int* bad;
  // delete[] bad; // error

  p = array;
  init_array(p, 7, -42);
  int* np = nullptr;
  if (p) // p != nullptr
    cout << "p is not nullptr" << endl;
  else
    cout << "p is nullptr" << endl;

  if (!p) // p == nullptr
    cout << "p is nullptr" << endl;
  else
    cout << "p is not nullptr" << endl;

  if (np)
    cout << "np is not nullptr" << endl;
  else
    cout << "np is nullptr" << endl;

  if (!np)
    cout << "np is nullptr" << endl;
  else
    cout << "np is not nullptr" << endl;

  cout << "\n\n\n==========================================" << endl;

  return 0;
}
