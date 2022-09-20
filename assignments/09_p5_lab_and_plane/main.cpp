#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T* allocate(int capacity);

template <typename T>
void print_array(T arr[], int size);

template <typename T>
void init_array(T arr[], int size, T value);


int main()
{
  // Two Dimensional pointers
  cout << "\n\n" << endl;
  const int MAX = 10;
  // 1D pointer
  // int arr[];
  int i = 42;
  int* p = &i;  //p-->[i]  //pretty pointless.
                //            because i has a name;

  p = allocate<int>(20);   //p->[ ][ ][ ][ ][ ]...[ ][ ]

  // 2D pointer
  // int twoDArr[][];
  int** p2d = &p;          //int star... star. pointer... pointer.
                            //p2d->[p]->[ ][ ][ ][ ][ ]...[ ][ ]
                            // pretty pointless: p has a name

  int size = 5;
  init_array(p, size, 42);

  cout << "printing the dynamic array pointed to by p: ";
  print_array(p, size);
  cout << "how do I get the address of the array from p2d?" << endl;
  cout << "How do I get what's stored in p, using p2d?" << endl;
  cout << "printing the array using the p2d who is pointing to p: ";
  print_array(*p2d, size);
  cout << "see? *p2d is the same as p" << endl;
  cout << "just like *p and i were the same thing" << endl;

  cout << "try your best not to do this:" << endl;
  cout << "I can look at the int value of the first element of the array," << endl;
  cout << "the int that p is pointing to..." << endl;
  cout << "by double dereferencing p2d: " << **p2d << endl;
  **p2d = -42;
  cout << "printing the array again after changing the first value: ";
  
  print_array(*p2d, size);
  cout<<"instead, do this: "<<endl;
  int* iptr;
  iptr = *p2d;
  //p2d -> [p]->[ ][ ][ ][ ][ ]...[ ][ ]
  //      iptr---^
  cout << "iptr ---> " << *iptr << endl;
  iptr++;
  //p2d -> [p]->[ ][ ][ ][ ][ ]...[ ][ ]
  //         iptr---^

  cout << "now, after iptr++, iptr ---> " << *iptr << endl;
  *iptr = 420;
  cout << "now, after *iptr=420, iptr ---> " << *iptr << endl;
  cout << "the whole array: ";
  iptr--;
  //now:
  //p2d -> [p]->[ ][ ][ ][ ][ ]...[ ][ ]
  //      iptr---^
  print_array(iptr, size);

  // WHAT TYPE IS IT?
  //iptr: pointer to an int: int pointer
  //*iptr is an int. Like i or 13.
  //p is just iptr.
  //  they are both pointing to the same thing.
  //  two pointers that point to the same thing are the same type.
  //p2d is a pointer to an int pointer: int double pointer
  //*p2d: int pointer. an address. just like p or iptr
  //**p2d: int. just like i, 13, *p, *iptr
  //iptr can change the contents of the array
  //  so can p.
  // but iptr cannot change where p is pointing to.
  //p2d is the guy who can change where p is pointing to.
  //
  //be careful changing the pointer that points to a dynamic array.
  //don't lose your array:
  iptr = p;
  //now, iptr holds the address of the dynamic array.
  cout << "p should be pointing to -42: [" << *p <<"]" << endl;
  cout << "changing where p is pointing to using p2d: " << endl;
  //p++;  How do I do this without referencing p?
  (**p2d)++;
  cout << "after **p2d++, don't do this!!: ";
  print_array(p, size);
  
  //....
  (*p2d)++;
  cout << "p should be pointing to 420: [" << *p <<"]"<< endl;
  cout << "here is the array starting at where p is pointing to:  "<<endl;
  cout << " you may see garbage at the end, only size-1 elements are initialized after p" << endl;
  
  print_array(p, size);

  cout << "\n\n\n=====================" << endl;
  return 0;
}

template <typename T>
T* allocate(int capacity)
{
  return new T[capacity];
}

template <typename T>
void print_array(T arr[], int size)
{
  T *iptr;
  //  iptr                 -V
  // --------------------------------------------
  // |    |    |    |    |    |    |    |    |
  // --------------------------------------------
  iptr = arr; //point iptr to the first element in arr
  // iptr = &arr[0]; 
  //print the elements of the array:
  cout << "[" << size << "]    ";
  for (int i = 0; i < size; i++) {
    cout << setw(4) << *iptr;
    iptr++;
  }
  cout << endl;
}

template <typename T>
void init_array(T arr[], int size, T value)
{
  T *walker = arr;
  //  iptr                 -V
  // --------------------------------------------
  // |    |    |    |    |    |    |    |    |
  // --------------------------------------------
  for (int i = 0; i < size; i++) {
    *walker = value;
    walker++;
  }
  cout << endl;
}