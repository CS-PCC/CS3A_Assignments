# Evaluate Reverse Polish Notation (RPN) and Shunting Yard Algorithm

- Accept [15_06_evaluate_rpn_shunting_yard](https://classroom.github.com/a/ut75d0cP)
- Get [basic_test.cpp](basic_test.cpp)

---

## Implement [Reverse Polish Notation (RPN)](https://docs.google.com/document/d/1orxcAaCVnN6MvZJwNDrMLkUtBxyXppl5y6dVaAzYjmA/edit?usp=sharing)

```c++
#ifndef RPN_H
#define RPN_H

#include <iostream>

#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"

using namespace std;

// Declaration
double rpn(Queue<char> &queue);

// Definition

// TODO

#endif //RPN_H
```


## Implement [Shunting Yard Algorithm](https://docs.google.com/document/d/1MAbJERpctca8mEh46BHBaSEpDREnuvHrVfwohcwrCck/edit?usp=sharing)

```c++
#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <iostream>
#include <cassert>

#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"

using namespace std;

// Declaration
Queue<char> shunting_yard(Queue<char> &queue);
int precedence(char o);

// Definition

// TODO

#endif //SHUNTING_YARD_H
```
