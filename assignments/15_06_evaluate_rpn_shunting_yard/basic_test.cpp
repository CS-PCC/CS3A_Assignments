#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/queue/MyQueue.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"

//------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

bool test_rpn(bool debug = false)
{
  Queue<char> postfix; // postfix expression: 3 5 *
  postfix.push('3');
  postfix.push('5');
  postfix.push('*');
  cout << "3 5 *: " << rpn(postfix) << endl << endl;

  Queue<char> postfix2; // postfix expression: 3 2 *
  postfix2.push('3');
  postfix2.push('2');
  postfix2.push('*');
  cout << "3 2 *: " << rpn(postfix2) << endl << endl;

  Queue<char> postfix3; // postfix expression: 3 5 6 + 2 - * 9 /
  postfix3.push('3');
  postfix3.push('5');
  postfix3.push('6');
  postfix3.push('+');
  postfix3.push('2');
  postfix3.push('-');
  postfix3.push('*');
  postfix3.push('9');
  postfix3.push('/');
  cout << "3 5 6 + 2 - * 9 /: " << rpn(postfix3) << endl;

  cout << "\n\n--------- RPN DONE ---------\n\n" << endl;
  return true;
}

bool test_shunting_yard(bool debug = false)
{
  Queue<char> infix; // infix expression: 3 * 5
  infix.push('3');
  infix.push('*');
  infix.push('5');
  cout << "3 * 5: " << shunting_yard(infix) << endl;

  Queue<char> infix2;
  infix2.push('3');
  infix2.push('*');
  infix2.push('(');
  infix2.push('5');
  infix2.push('+');
  infix2.push('6');
  infix2.push('-');
  infix2.push('7');
  infix2.push(')');
  infix2.push('/');
  infix2.push('9');
  cout << "3*(5+6-7)/9: " << shunting_yard(infix2) << endl;

  cout << "\n\n--------- Shunting Yard DONE ---------\n\n" << endl;
  return true;
}


//Lord help me! 
bool debug = false;

TEST(TEST_RPN, TestRPN)
{
  bool success = test_rpn(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_SHUNTING_YARD, TestShuntingYard)
{
  bool success = test_shunting_yard(debug);
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv) 
{
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
├── rpn
│   └── rpn.h
├── shunting_yard
│   └── shunting_yard.h
└── stack
    └── MyStack.h

6 directories, 6 files
build git:(master) ✗  😊 $> ./bin/basic_test
----------running basic_test.cpp---------
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_RPN
[ RUN      ] TEST_RPN.TestRPN
3 5 *: 15

3 2 *: 6

3 5 6 + 2 - * 9 /: 3


--------- RPN DONE ---------


[       OK ] TEST_RPN.TestRPN (1 ms)
[----------] 1 test from TEST_RPN (1 ms total)

[----------] 1 test from TEST_SHUNTING_YARD
[ RUN      ] TEST_SHUNTING_YARD.TestShuntingYard
3 * 5: [3]->[5]->[*]->|||

3*(5+6-7)/9: [3]->[5]->[6]->[+]->[7]->[-]->[*]->[9]->[/]->|||


--------- Shunting Yard DONE ---------


[       OK ] TEST_SHUNTING_YARD.TestShuntingYard (0 ms)
[----------] 1 test from TEST_SHUNTING_YARD (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 2 tests.
build git:(master) ✗  😊 $> 
*/