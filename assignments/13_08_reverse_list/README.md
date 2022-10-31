# Iterated List

- Accept [13_08_reverse_list](https://classroom.github.com/a/6BpNoCaJ)
- Get [basic_test.cpp](basic_test.cpp)

---

Add following functions to `list_literated.h` file.

```cpp
void clear();                         //clear list
node<T>* &head() { return _head; }
```

## 1. Reverse entire linked list

Given a singly linked list, reverse the list.

#### Example 1:
```
Input: list = [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||
Output: [1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
```

#### Example 2:
```
Input: list = []->|||
Output: []->|||
```

#### Constraints:
- The number of nodes in the list is the range [0, 50].


## 2. Reverse first N nodes in linked list

Given a singly linked list and an integer N, reverse the first N nodes in list.

#### Example 1:
```
Input: list = [1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||, N=3
Output: [3]->[2]->[1]->[4]->[5]->[6]->[7]->[8]->[9]->|||
```

#### Example 2:
```
Input: list = []->|||
Output: []->|||
```

#### Constraints:
- The number of nodes in the list is the range [0, 50].
- `0 <= N <= numbers of nodes`


## 3. Reverse partial nodes in linked list

Given a singly linked list and two integers m and n where m <= n, reverse the nodes of the list from position m to position n. m and n are **1-indexed** position in list.

#### Example 1:
```
Input: list = [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||, m=3, n=6
Output: [9]->[8]->[4]->[5]->[6]->[7]->[3]->[2]->[1]->|||
```

#### Example 2:
```
Input: list = [5]->|||, m=1, n=1
Output: [5]->|||
```

#### Constraints:
- The number of nodes in the list is the range [1, 50].
- `1 <= m <= n <= numbers of nodes`


## Two Pointers Functions

Implement following functions in `includes/reverse_list/reverse_list.h`

Try to understand and implement **Iterative** and **Recursive** methods for all three functions.

```cpp
#ifndef REVERSE_LIST_H
#define REVERSE_LIST_H

#include <iostream>

#include "../../includes/list_iterated/list_iterated.h"

using namespace std;

// Declaration

// 1. reverse entire linked list
template <typename T>
void reverseList(List<T>& list);

// 2. reverse first N nodes in linked list
template <typename T>
void reverseN(List<T>& list, int n);

// 3. reverse partial nodes of range [m, n] in linked list
template <typename T>
void reverseBetween(List<T>& list, int m, int n);

// Definition

// TODO

#endif // REVERSE_LIST_H
```