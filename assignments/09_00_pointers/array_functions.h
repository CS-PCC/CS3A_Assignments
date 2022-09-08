#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// Declaration
// if we use template class, declaration and definition should be in one header file.
template <typename T>
void print_array(T arr[], int size);
void print_array_pointer(int* arr, int size);

void swap_pointers(int* one, int* two);
// passing pointers by reference:
// if you need to modify the pointer 
// rather than the object that the pointer is pointing to.
void swap_pointers_ref(int*& one, int*& two);

template <typename T>
T *allocate(int capacity = 3);
void init_array(int* arr, int size, int value);
void try_walker(int* arr, int size);

// Lab 0 functions

//initialize the first size elements of the array
template <typename T>
void _array_init(T* a, int size, T x=0);
//add append_me to the end of the array and size++
template <typename T>
void _append(T* a, int& size, T append_me);
//return index of find_me -1 if not found
template <typename T>
T* _find(const T* a, int size, T find_me);
//return item at index pos
template <typename T>
T& _at(T* a, int size, int pos);
//print the array
template <typename T>
void _print_array(const T a[], int size);


//--------------------------------------
template <typename T>
void print_array(T arr[], int size) {
  T* iptr;
  // iptr                  V
  // --------------------------------------------
  // |    |    |    |    |    |    |    |    |
  // --------------------------------------------
  iptr = &arr[0]; // point iptr to the first element in arr
  // print the elements of the array:
  cout << "(" << size << ")    [";
  for (int i = 0; i < size; i++) {
    cout << setw(4) << *iptr;
    iptr++;
  }
  cout << "]" << endl;
}

void print_array_pointer(int* arr, int size)
{
  int* walker = arr;  // walker is pointing to the start of the array.
  for (int i=0; i<size; i++, walker++){
    cout<<setw(4)<<*walker<<" ";
  }
  cout<<endl;
}

void swap_pointers(int* one, int* two)
{
  // passing pointers by reference.
  // Since the address is passed instead of value,
  // a dereference operator * must be used to 
  // access the value stored in that address.
  int temp = *one;
  *one = *two;
  *two = temp;
}

void swap_pointers_ref(int*& one, int*& two)
{
  // passing pointers by reference.
  int temp = *one;
  *one = *two;
  *two = temp;
}

template <typename T>
T* allocate(int capacity)
{
  T* hold = new T [capacity];   // new: allocates space of the given capacity
                                // and returns the address.
                                // the address is stored in hold;
  return hold;                  // return the address of the dynamically allocated
                                // array back to the caller.
                                // hold is destroyed along with all local variables
}

void init_array(int* arr, int size, int value)
{
  int* walker = arr;  // walker is pointing to the start of the array.
  for (int i=0; i<size; i++, walker++){
    *walker = value;
  }
}

void try_walker(int* arr, int size)
{
  int* walker = arr;  // walker is pointing to the start of the array.
  // change first half of array
  for (int i=0; i<size/2; i++) {
      *(walker++) = 99;
  }
  cout << "Print pointer in function:\n";
  print_array_pointer(arr, size);
}

#endif // ARRAY_FUNCTIONS_H