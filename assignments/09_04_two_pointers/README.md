# Two Pointers

- Accept [09_04_two_pointers](https://classroom.github.com/a/GDhvnWsM)
- Get [basic_test.cpp](basic_test.cpp)

---

Please read the [Guidelines for pointers](https://docs.google.com/document/d/1WDgzNbWrGjDA7739GjZ8Xna_RrUX95w6XqKL4mOmDpc/edit?usp=sharing) before you begin.

Implement following three functions **without** brute force (nested loop).


## 1. Remove Duplicates

Given an array `arr` sorted in **non-decreasing order**, remove the duplicates in-place such that each unique element appears only **once**. The **relative order** of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `arr`. More formally, The first `size` elements of `arr` should hold the final result. It does not matter what you leave beyond the first `size` elements.

Do **not** allocate extra space for another array. You must do this by **modifying the input array** `in-place` without extra memory.

#### Example 1:

```
Input:  arr = [1,1,2]
Output: arr = [1,2,_], size = 2
Explanation: Your function should change size = 2, with the first two elements of arr being 1 and 2 respectively.
It does not matter what you leave beyond the size (hence they are underscores).
```

#### Example 2:

```
Input:  arr = [0,0,1,1,1,2,2,3,3,4]
Output: arr = [0,1,2,3,4,_,_,_,_,_], size = 5
Explanation: Your function should change size = 5, with the first five elements of arr being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the size (hence they are underscores).
```

#### Example 3:

```
Input:  arr = [a,a,a,b,b,c,c,c,c,d,e,e,f,g,g,h]
Output: arr = [a,b,c,d,e,f,g,h], size = 8
```

#### Constraints:

- `1 <= nums.length <= 99`
- `-99 <= nums[i] <= 99`
- `nums` is sorted in **non-decreasing** order.

#### Hints:

We need to modify the array in-place and the size of the final array would potentially be smaller than the size of the input array. So, we ought to use a two-pointer approach here. One, that would keep track of the current element in the original array and another one for just the unique elements.


## 2. Two Sum

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the pointer of indices of the two numbers*, `index1` and `index2`, **added by one** *as an integer array* `[index1, index2]` *of length 2*.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

#### Example 1:

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

#### Example 2:

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

#### Example 3:

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

#### Constraints:

- `2 <= numbers.length <= 99`
- `-99 <= numbers[i] <= 99`
- `numbers` is sorted in **non-decreasing order**.
- `-99 <= target <= 99`
- The tests are generated such that there is **exactly one solution**.


## 3. Longest Substring Without Repeating Characters

Given an array of characters `s`. Find the length of the **longest substring** without repeating characters.

#### Example 1:

```
Input: s = [a,b,c,a,b,c,b,b]
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

#### Example 2:

```
Input: s = [b,b,b,b,b]
Output: 1
Explanation: The answer is "b", with the length of 1.
```

#### Example 3:

```
Input: s =[p,w,w,k,e,w]
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

#### Constraints:

- `0 <= s.length <= 99`
- `s` consists of English lowercase letters (a-z).


## Two Pointers Functions

Implement following functions in `includes/two_pointers/two_pointers.h`

```c++
#ifndef TWO_POINTERS_H
#define TWO_POINTERS_H

#include <iostream>

using namespace std;

// Declaration

template<typename T>
void removeDuplicates(T* arr, int& size);

template<typename T>
int* twoSum(T* numbers, const int size, int target);

template<typename T>
int lengthOfLongestSubstring(T* s, const int size);

// Definition

// TODO

#endif // TWO_POINTERS_H
```
