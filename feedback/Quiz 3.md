## Quiz Question(s)

﻿# OOP244 – Quiz 3

**Coding Quiz | 10 Marks | 40 Minutes | 38 Points**

### Before You Start

If Notepad++ is not open, [click here to go to MyApps](https://myapps.senecapolytechnic.ca/), open **Notepad++**, and save a file named **quiz3.cpp** on your **Desktop**.

**DO NOT copy and paste your answer into the quiz answer box.**

Write and save your answer in quiz3.cpp. When you are finished, attach the file to your answer by either:

- Dragging and dropping quiz3.cpp from your Desktop into the answer area.
- Clicking the attachment icon and selecting quiz3.cpp.
- Do not attach more than one document.

---

## Quiz Instructions

You are given a partially implemented C++ class named `InventoryItem`.

The class stores a dynamically allocated C-string containing an item's name and an integer representing the number of units available in inventory.

Complete the missing parts of the class according to the numbered sections below.

Write all your answers in **one C++ source file**. Identify each section of your solution using a comment containing its section number, such as `// 2` or `// 3`.

**Implement all member functions inline inside the class.** Helper functions may be implemented outside the class.

Do not change the existing data members, constructor, or query functions.

You do not need to write a `main()` function.

Use C++11 or later.

The code examples in each section illustrate the expected behaviour. **Do not include these examples in your submitted code.**

## Section 1 – Submission Filename (1 point)

At the very beginning of your source code, write a C++ comment containing the answer to this question:

**What is the exact name of the file you must submit for this quiz?**

Your answer must be a C++ comment, for example:

```cpp
// Your answer goes here
```

## Provided Code

Use the following code as the starting point for your solution.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

class InventoryItem {
   char* m_name;
   int m_stock;

public:
   InventoryItem(const char* name, int stock) {
      m_name = nullptr;
      if (name != nullptr) {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
      m_stock = stock;
   }

   const char* name() const {
      return m_name;
   }

   int stock() const {
      return m_stock;
   }

   // Add your implementations here.
};

// Add helper functions here if needed.
```

Assume that inventory quantities are never negative. The item name may be `nullptr`.

## Section 2 – Prevent Copy Construction (2 points)

Modify the `InventoryItem` class to prevent objects from being created as copies of existing `InventoryItem` objects.

Copy assignment must remain possible.

After your implementation, the following must not compile:

```cpp
InventoryItem A("Markers", 15);
InventoryItem B = A;   // Must cause a compilation error
```

## Section 3 – Destructor (3 points)

Implement the destructor for the `InventoryItem` class.

The destructor must correctly release any dynamically allocated memory owned by the object without causing memory leaks.

For example:

```cpp
{
   InventoryItem I("Notebooks", 25);
   // I owns dynamically allocated memory
}
// I is destroyed here.
// Its dynamically allocated memory must be released.
```

## Section 4 – Copy Assignment Operator (10 points)

Overload the assignment operator (`=`) as a member of the `InventoryItem` class so that one existing inventory item can be assigned to another.

The assignment must:

- Correctly copy the item's name and stock quantity.
- Perform a deep assignment of the dynamically allocated name.
- Release any previously allocated memory that is no longer needed.
- Correctly handle a source object whose name is `nullptr`.
- Handle self-assignment safely.
- Allow chained assignments.

For example:

```cpp
InventoryItem A("Markers", 15);
InventoryItem B("Erasers", 30);
InventoryItem C("Folders", 50);

A = B;

// A now contains "Erasers" and 30.
// A and B must have independent names.

A = A;   // Must be safe and leave A unchanged.

A = B = C;

// Both A and B now contain "Folders" and 50.
// All three objects must own independent names.
```

## Section 5 – Member `-=` Operator (4 points)

Overload the `-=` operator as a member of the `InventoryItem` class.

The operator receives an integer and decreases the stock quantity of the current item by that amount.

It must allow chained operations and must not change the item's name.

Assume the received integer is never negative and never greater than the current stock quantity.

For example:

```cpp
InventoryItem I("Markers", 20);

I -= 5;
// I now contains 15 units.

(I -= 3) -= 4;
// I now contains 8 units.
```

## Section 6 – Member `*` Operator (5 points)

Overload the `*` operator as a member of the `InventoryItem` class.

The operator receives an integer and returns an integer equal to the product of the item's current stock quantity and the received value.

The operator must not modify the `InventoryItem` object.

Assume the received integer is never negative.

For example:

```cpp
InventoryItem I("Notebooks", 6);

int a = I * 10;  // a will hold 60.
int b = I * 4;   // b will hold 24.

// I still contains 6 units.
```

## Section 7 – Boolean Type Conversion (4 points)

Overload the `bool` type conversion operator as a member of the `InventoryItem` class.

An `InventoryItem` object is considered valid when:

- Its name is not `nullptr`.
- Its name is not an empty string.
- Its stock quantity is greater than zero.

The conversion must return `true` when all three conditions are satisfied, and `false` otherwise.

The conversion must not modify the object.

For example:

```cpp
InventoryItem A("Markers", 15);
InventoryItem B("", 20);
InventoryItem C(nullptr, 10);
InventoryItem D("Folders", 0);

if (A) {
   cout << "Valid";
}
// Displays: Valid

bool b = bool(B);  // false
bool c = bool(C);  // false
bool d = bool(D);  // false
```

## Section 8 – Helper Insertion Operator (5 points)

Overload the stream insertion operator (`<<`) as a **helper operator** so that an `InventoryItem` object can be inserted into an `ostream`.

The output format must be:

`Name: stock`

If the name is `nullptr`, display `"Unnamed"` in place of the name.

The operator must support chained insertions and must not modify the `InventoryItem` object.

For example:

```cpp
InventoryItem A("Markers", 15);
InventoryItem B(nullptr, 8);

cout << A << endl;
cout << B << endl;
```

Expected output:

```text
Markers: 15
Unnamed: 8
```

Chained insertion must also work:

```cpp
cout << A << " | " << B << endl;
```

Expected output:

```text
Markers: 15 | Unnamed: 8
```

## Section 9 – Unary Decrement Operator (4 points)

Overload the **prefix `--` operator** as a member of the `InventoryItem` class.

The operator must:

- Decrease the stock quantity of the current item by one.
- Leave the item's name unchanged.
- Return a reference to the current object so chained prefix decrements are possible.

Assume the operator is only used when the stock quantity is greater than zero.

For example:

```cpp
InventoryItem I("Markers", 10);

--I;
// I now contains 9 units.

----I;
// I now contains 7 units.
```

---

**End of Quiz**

## Original Student Answer

File: Quiz 3_lrayan_attempt_2026-11-20-09-28-29_quiz3.cpp

````cpp
// quiz3.cpp

#include <iostream>
#include <cstring>
 
using namespace std;
 
class InventoryItem {
	char *m_name;
	int m_stock;
 
public:
    InventoryItem(const char* name, int stock) {
		m_name = nullptr;
	  
        if (name != nullptr) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
        }
	  
		m_stock = stock;
    }
 
 
    const char* name() const {
		return m_name;
    }
 
 
    int stock() const {
		return m_stock;
    }
 
 
    InventoryItem(const InventoryItem&) = delete;
   
   
    ~InventoryItem() {
		if (name) {
			delete [] name;
			
			name = nullptr;
		}
    }
	
	
	InventoryItem& operator=(const InventoryItem& value) {
		if (this != &value) {
			m_stock = value.stock();
			
			if (m_name) {
				delete [] m_name;
				
				m_name = nullptr;
			}
			
			if (value.name()) {
				m_name = new char[strlen(value.name()];
				
				strcpy(m_name, value.name());
			}
		}
		
		return *this;
	}
	
	
	InventoryItem& operator-=(int value) {
		m_stock -= value;
		
		return *this;
	}
	
	
	int operator*(int value) const {
		return m_stock * value;
	}
	
	
	operator bool() const {
		return m_name && *m_name && m_stock > 0;
	}
	
	
	InventoryItem& operator--(int) {
		--m_stock;
		
		return *this;
	}
};


ostream& operator<<(ostream& os = cout, const InventoryItem& itm) {
	return os << (itm.name()) ? itm.name() : "Unnamed" << ":" << itm.stock();
}

````

## Feedback

# Quiz 3

Student: Labeeb Rayan
Seneca User ID: lrayan
Assessment Version: Version 2
Points: **35.5**/38
Final Mark: **9.34**/10

## Marking

### Section 1 - Submission filename
* 1/1 Correct filename: quiz3.cpp: 1

### Section 2 - Prevent copy construction
* 2/2 Copy constructor declaration: 1, = delete: 1

### Section 3 - Destructor
* 1/1 Correct destructor signature: 1
* 2/2 Correct delete[]: 1, correct pointer: 1

### Section 4 - Copy assignment operator
* 2/2 Signature - InventoryItem& return: 1, correct operator= with const InventoryItem& parameter: 1
* 1/1 Self-assignment protection: 1
* 2.5/3 Deep copy - null source handling: 1, correct allocation with length + 1: 1, copying string content: 1
  - The allocation does not include the extra character for the terminating null. Allocate strlen(value.name()) + 1 characters. Partial allocation credit is given.
* 2/2 Old memory released using delete[]: 1, new pointer assigned: 1
* 1/1 Correct stock assignment: 1
* 1/1 Returning current object for chained assignment: 1

### Section 5 - Member -= operator
* 2/2 Signature - correct member operator-= with int parameter: 1, InventoryItem& return type: 1
* 1/1 Correctly decreases stock without changing name: 1
* 1/1 Returns current object by reference: 1

### Section 6 - Member * operator
* 3/3 Signature - int return type: 1, correct operator* with int parameter: 1, const qualifier: 1
* 2/2 Correct multiplication: 1, returns result without modifying object: 1

### Section 7 - Boolean type conversion
* 2/2 Signature - operator bool(): 1, const qualifier: 1
* 2/2 Validity - non-null and non-empty name: 1, positive stock and correct combined result: 1

### Section 9 - Prefix decrement operator
* 1/2 Signature - InventoryItem& return type: 1, correct prefix operator--(): 1
  - The reference return is correct, but the int dummy parameter declares postfix decrement. The required prefix operator has no parameter.
* 1/1 Decreases stock by exactly one without changing name: 1
* 1/1 Returns current object by reference: 1

### Section 8 - Helper insertion operator
* 2/2 Signature - ostream& return and stream parameter: 1, const InventoryItem& parameter: 1
* 1/1 Uses name() and correctly handles nullptr: 1
* 1/1 Correct format and stock() accessor: 1
* 0/1 Returns output stream by reference for chaining: 1
  - The conditional expression needs parentheses before stream insertion. As written, operator precedence makes the return expression a conditional result rather than the output stream.

Points: **35.5**/38
Final Mark: **9.34**/10

## Feedback

Labeeb, your assignment, arithmetic, and bool conversion show good understanding. Remember to allocate one extra character for the string terminator. Use operator--() with no dummy parameter for prefix decrement. In the insertion helper, put parentheses around the conditional name expression before inserting it. Check member names in the destructor and complete the class and function punctuation.

## Rubric

````cpp
//# 10

//+ Section 1 - Submission filename
// quiz3.cpp
//- 1 Correct filename: quiz3.cpp: 1

#include <iostream>
#include <cstring>
using namespace std;

class InventoryItem {
   char* m_name;
   int m_stock;

public:
   InventoryItem(const char* name, int stock) {
      m_name = nullptr;
      if (name != nullptr) {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
      m_stock = stock;
   }

   const char* name() const {
      return m_name;
   }

   int stock() const {
      return m_stock;
   }

   //+ Section 2 - Prevent copy construction
   InventoryItem(const InventoryItem&) = delete;
   //- 2 Copy constructor declaration: 1, = delete: 1


   //+ Section 3 - Destructor
   ~InventoryItem() {
      //- 1 Correct destructor signature: 1

         //+
      delete[] m_name;
      //- 2 Correct delete[]: 1, correct pointer: 1
   }


   //+ Section 4 - Copy assignment operator
   InventoryItem& operator=(const InventoryItem& other) {
      //- 2 Signature - InventoryItem& return: 1, correct operator= with const InventoryItem& parameter: 1

         //+
      if (this != &other) {
         //- 1 Self-assignment protection: 1

            //+
         char* temp = nullptr;
         if (other.m_name != nullptr) {
            temp = new char[strlen(other.m_name) + 1];
            strcpy(temp, other.m_name);
         }
         //- 3 Deep copy - null source handling: 1, correct allocation with length + 1: 1, copying string content: 1

         //+
         delete[] m_name;
         m_name = temp;
         //- 2 Old memory released using delete[]: 1, new pointer assigned: 1

         //+
         m_stock = other.m_stock;
         //- 1 Correct stock assignment: 1
      }

      //+
      return *this;
      //- 1 Returning current object for chained assignment: 1
   }


   //+ Section 5 - Member -= operator
   InventoryItem& operator-=(int value) {
      //- 2 Signature - correct member operator-= with int parameter: 1, InventoryItem& return type: 1

         //+
      m_stock -= value;
      //- 1 Correctly decreases stock without changing name: 1

      //+
      return *this;
      //- 1 Returns current object by reference: 1
   }


   //+ Section 6 - Member * operator
   int operator*(int value) const {
      //- 3 Signature - int return type: 1, correct operator* with int parameter: 1, const qualifier: 1

         //+
      return m_stock * value;
      //- 2 Correct multiplication: 1, returns result without modifying object: 1
   }


   //+ Section 7 - Boolean type conversion
   operator bool() const {
      //- 2 Signature - operator bool(): 1, const qualifier: 1

         //+
      return m_name != nullptr
         && m_name[0] != '\0'
         && m_stock > 0;
      //- 2 Validity - non-null and non-empty name: 1, positive stock and correct combined result: 1
   }


   //+ Section 9 - Prefix decrement operator
   InventoryItem& operator--() {
      //- 2 Signature - InventoryItem& return type: 1, correct prefix operator--(): 1

         //+
      --m_stock;
      //- 1 Decreases stock by exactly one without changing name: 1

      //+
      return *this;
      //- 1 Returns current object by reference: 1
   }
};


//+ Section 8 - Helper insertion operator
// If friend is used instead of public accessors,
// award only half of this section's points (2.5 out of 5).

ostream& operator<<(ostream& ostr, const InventoryItem& I) {
   //- 2 Signature - ostream& return and stream parameter: 1, const InventoryItem& parameter: 1

      //+
   if (I.name() != nullptr) {
      ostr << I.name();
   }
   else {
      ostr << "Unnamed";
   }
   //- 1 Uses name() and correctly handles nullptr: 1

   //+
   ostr << ": " << I.stock();
   //- 1 Correct format and stock() accessor: 1

   //+
   return ostr;
   //- 1 Returns output stream by reference for chaining: 1
}

````
