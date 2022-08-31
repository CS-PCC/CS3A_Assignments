#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"


//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

bool test_stack(bool debug = false)
{
  //-----------------------------------------
  // top -> 7 -> 3 -> 9 -> 2 -> 8 -> 5 -> |||
  //-----------------------------------------
  // stack push and pop on the top position
  Stack<int> s;
  cout << "stack.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    s.push(i);
    cout << s;
  }
  cout << "top of stack: " << s.top() << endl;
  cout << "pop stack: " << s.pop() << endl;
  cout << s << endl;
  cout << "size of the stack: " << s.size() << endl;
  cout << "is stack empty? " << boolalpha << s.empty() << endl;
  Stack<int>::Iterator s_it = s.begin();
  cout << "stack top to bottom: " << endl;
  cout << "| top |\n";
  for (; s_it != s.end(); s_it++)
  {
    cout << "| <" << *s_it << "> |" << endl;
  }
  cout << "|-----|\n\n";
  
  // copy CTOR
  Stack<int> s2(s);
  cout << "s2: " << s2;
  Stack<int>::Iterator s2_it = s2.begin();
  cout << "stack top to bottom: " << endl;
  cout << "| top |\n";
  for (; s2_it != s.end(); s2_it++)
  {
    cout << "| <" << *s2_it << "> |" << endl;
  }
  cout << "|-----|";

  cout << "\n\n--------- Stack DONE ---------\n\n" << endl;
  return true;
}

bool test_queue(bool debug = false)
{
  //----------------------------------------------
  // top -> 7 -> 3 -> 9 -> 2 -> 8 -> 5 -> rear |||
  //----------------------------------------------
  // queue push on the rear position
  // queue pop on the top position
  Queue<int> q;
  cout << "queue.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    q.push(i);
    cout << q;
  }
  cout << "front of queue: " << q.front() << endl;
  cout << "rear of queue: " << q.back() << endl;
  cout << "pop queue: " << q.pop() << endl;
  cout << q << endl;
  cout << "size of the queue: " << q.size() << endl;
  cout << "is queue empty? " << boolalpha << q.empty() << endl;
  Queue<int>::Iterator q_it = q.begin();
  cout << "queue top to bottom: " << endl;
  cout << "| top |\n";
  for (; q_it != q.end(); q_it++)
  {
    cout << "| <" << *q_it << "> |" << endl;
  }
  cout << "| rear|\n\n";
  // copy CTOR
  Queue<int> q2(q);
  cout << "q2: " << q2;
  Queue<int>::Iterator q2_it = q2.begin();
  cout << "queue top to bottom: " << endl;
  cout << "| top |\n";
  for (; q2_it != q2.end(); q2_it++)
  {
    cout << "| <" << *q2_it << "> |" << endl;
  }
  cout << "| rear|";

  cout << "\n\n--------- Queue DONE ---------\n\n" << endl;
  return true;
}


//Lord help me! 
bool debug = false;

TEST(BASIC_TEST, TestStack)
{
  bool success = test_stack(debug);
  EXPECT_EQ(success, true);
}

TEST(BASIC_TEST, TestQueue)
{
  bool success = test_queue(debug);
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv)
{
  if (argc>1) {
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*
build git:(master) ✗  😊 $> tree ../includes
../includes
├── linked_list_functions
│   └── linked_list_functions.h
├── node
│   └── node.h
├── queue
│   └── MyQueue.h
└── stack
    └── MyStack.h
4 directories, 5 files
build git:(master) ✗  😊 $> ./bin/basic_test
----------running testA.cpp---------
[==========] Running 2 test from 1 test case.
[----------] Global test environment set-up.
[----------] 2 test from BASIC_TEST
[ RUN      ] BASIC_TEST.TestStack
stack.push(): 
[0]->|||
[1]->[0]->|||
[2]->[1]->[0]->|||
[3]->[2]->[1]->[0]->|||
[4]->[3]->[2]->[1]->[0]->|||
top of stack: 4
pop stack: 4
[3]->[2]->[1]->[0]->|||

size of the stack: 4
is stack empty? false
stack top to bottom: 
| top |
| <3> |
| <2> |
| <1> |
| <0> |
|-----|

s2: [3]->[2]->[1]->[0]->|||
stack top to bottom: 
| top |
| <3> |
| <2> |
| <1> |
| <0> |
|-----|

--------- Stack DONE ---------


[       OK ] BASIC_TEST.TestStack (0 ms)
[ RUN      ] BASIC_TEST.TestQueue
queue.push(): 
[0]->|||
[0]->[1]->|||
[0]->[1]->[2]->|||
[0]->[1]->[2]->[3]->|||
[0]->[1]->[2]->[3]->[4]->|||
front of queue: 0
rear of queue: 4
pop queue: 0
[1]->[2]->[3]->[4]->|||

size of the queue: 4
is queue empty? false
queue top to bottom: 
| top |
| <1> |
| <2> |
| <3> |
| <4> |
| rear|

q2: [1]->[2]->[3]->[4]->|||
queue top to bottom: 
| top |
| <1> |
| <2> |
| <3> |
| <4> |
| rear|

--------- Queue DONE ---------


[       OK ] BASIC_TEST.TestQueue (2 ms)
[----------] 2 test from BASIC_TEST (0 ms total)
[----------] Global test environment tear-down
[==========] 2 test from 1 test case ran. (0 ms total)
[  PASSED  ] 2 test.
build git:(master) ✗  😊 $> 
*/