# Vector Class

- Accept [11_p1_vector](https://classroom.github.com/a/OkCDKcOM)
- Get [basic_test.cpp](basic_test.cpp)

---

Please read the [Guidelines for classes](https://docs.google.com/document/d/1dkqJa-h6e-GmlNwc-zgX7IPTrU8YJNMLrbrLS8idU3k/edit?usp=sharing) before you begin. 

Please read [counter](counter) class as reference.

Include and call functions in `add_entry.h`

## Vector

Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.


```c++
template <typename T>
class Vector
{
public:
  //Constructor: CTOR
  Vector(int capacity = 100);
  Vector(T* arr, int size);

  //BIG 3
  Vector (const Vector& x);           //Constructs a container with a copy of each of the elements in x, in the same order.
  ~Vector();                          //Destroys the container object.
  Vector& operator= (const Vector& x);//Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.

  //Element access:
  T& operator [] (int n);             //Returns a reference to the element at position n in the vector container.
  const T& operator [] (int n) const;
  T& at(int n);                       //Returns a reference to the element at position n in the vector container.
  const T& at(int n) const;
  T& front();                         //Returns a reference to the first element in the vector.
  T& back();                          //Returns a reference to the last element in the vector.
  
  //Modifiers:
  void push_back(const T& val);       //Adds a new element at the end of the vector
  void pop_back();                    //Removes the last element in the vector, effectively reducing the container size by one.
  void insert(int position, const T& val);//Insert elements val at position
  void erase(int position);           //Removes from the vector a single element at position
  int index_of(const T& val);         //Search for val. return index.

  //Capacity:
  int size() const {return _size;}    //return _size
  int capacity() const {return _capacity;} //return _capacity
  
  void resize(int n, T val = T());    //Resizes the container so that it contains n elements.
  // If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
  // If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
  // If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
  
  void reserve(int n);                //Requests that the vector capacity be at least enough to contain n elements.
  // If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n
  // In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
  // This function has no effect on the vector size and cannot alter its elements.
  
  bool empty() const;                 //Returns whether the vector is empty
  
  //Output:
  template <class U>
  friend ostream& operator <<(ostream& outs, const Vector<U>& _a);
private:
  int _capacity; //the space allocated
  int _size;     //the space used
  T* _arr;       //pointer of dynamic array
};
```