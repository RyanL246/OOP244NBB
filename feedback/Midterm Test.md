# Quiz Question(s)

## Question 1.4 — Overloading and References

**10 marks, estimated completion time: 14 minutes**

Begin your answer with the following comment:

```cpp
// Question 1.4
```

Write two overloaded functions named `keepWithin`:

- One works with `long long` values.
- The other works with `double` values.

Each function receives three parameters of its corresponding type:

- a value **by reference**;
- a minimum limit **by value**; and
- a maximum limit **by value**.

Each function must:

- Change the referenced value to the minimum limit if it is below that limit.
- Change the referenced value to the maximum limit if it is above that limit.
- Leave the referenced value unchanged if it is within the limits, including either endpoint.
- Return `true` if the referenced value was changed, or `false` otherwise.

Assume the minimum limit is never greater than the maximum limit.

**Write both complete function definitions.** Use one return statement at the end of each function. You do not need to write header inclusions or a `main()` function.

## Question 2.1 — Dynamic Memory

**18 marks, estimated completion time: 22 minutes**

Begin your answer with the following comment:

```cpp
// Question 2.1
```

Implement the following function:

```cpp
int* positiveValues(const int* source, int size, int& count);
```

The function creates a dynamically allocated array containing only the **positive values** from `source`, in their original order.

The function must:

- Set `count` to the number of positive values found.
- Allocate an array with exactly that many elements.
- Copy the positive values into the allocated array.
- Return the address of the allocated array.
- Leave the source array unchanged.

If `size` is zero or negative, or `source` is `nullptr`, the function must set `count` to zero and return `nullptr`.

If the source contains no positive values, the function must also set `count` to zero and return `nullptr`, without allocating an array.

Assume that, when `source` is not `nullptr` and `size` is positive, `source` points to at least `size` elements. Assume all dynamic memory allocations succeed.

### Example

Given:

```cpp
int values[] = {4, -2, 0, 7, -5, 3};
int count;
int* result = positiveValues(values, 6, count);
```

`count` must become `3`, and the allocated array must contain:

```text
4 7 3
```

### Required Answer

Write:

1. The complete function definition. Use one return statement at the end of the function.
2. The statement that the caller should execute to release the array returned in `result`.

You do not need to write header inclusions or a `main()` function.

## Question 3.2 — The `PrintAccount` Module

**42 marks, estimated completion time: 54 minutes**

Begin your answer with the following comment:

```cpp
// Question 3.2
```

Create a module named `PrintAccount` in the `seneca` namespace.

A `PrintAccount` object represents a collection of unused printing credits for one account holder.

Write the complete contents of:

- `PrintAccount.h`
- `PrintAccount.cpp`

Clearly label the beginning of each file in your answer.

### A. Module and Data Members

The header must have an appropriate inclusion guard.

The class must contain the following **private** data members:

- `m_holder`: a pointer to a dynamically allocated C-style string containing the account holder’s name.
- `m_credits`: a `long` containing the number of unused printing credits.

Declare the required public member functions in the header and define them in the implementation file.

Any `using namespace std;` directive must appear only in the implementation file.

### B. Construction and Destruction

Implement the following:

**Default constructor**

Places the object in a safe empty state:

- `m_holder` is `nullptr`.
- `m_credits` is zero.

**Two-argument constructor**

Receives an account holder’s name as a pointer to constant characters and an initial credit count as a `long`.

The arguments are valid when:

- The holder’s name is neither `nullptr` nor an empty string.
- The credit count is zero or greater.

For valid arguments, allocate exactly enough memory for an independent copy of the holder’s name, including its null terminator, and store the credit count.

If either argument is invalid, place the object in the safe empty state without allocating memory.

**Destructor**

Releases the dynamically allocated holder’s name.

### C. Queries

**Conversion to `bool`**

Returns `true` when the object has a holder’s name and `false` when it is in the safe empty state.

An object with a valid holder’s name and zero credits must still convert to `true`.

**`credits()`**

Returns the number of unused printing credits as a `long`.

Both queries must be callable on a constant object.

### D. Member Operators

**`operator+=`**

Receives a `long` number of credits to add.

- Add the amount only when the object has a holder’s name and the amount is positive.
- Otherwise, leave the object unchanged.
- Return a reference to the current object.

**`operator-=`**

Receives a `long` number of credits to use.

- Subtract the amount only when the object has a holder’s name, the amount is positive, and enough credits are available.
- Otherwise, leave the object unchanged.
- Return a reference to the current object.

Using all remaining credits must leave the holder’s name unchanged and the credit count at zero.

### E. Output

Implement a `show()` member function that returns `void` and is callable on a constant object.

For an object with holder’s name `Alex` and five credits, display:

```text
Alex: 5 credits
```

For an object in the safe empty state, display:

```text
Invalid print account
```

End either output with a newline.

### Additional Instructions and Assumptions

- Do not write a `main()` function.
- Include the necessary headers.
- Use C-style strings; do not use `std::string`.
- You may use `strlen` and `strcpy` from `<cstring>`.
- Use one return statement at the end of each function that returns a value.
- Assume all dynamic memory allocations succeed and all arithmetic results fit within a `long`.
- You may add private member functions if needed.

# Original Student Answer

## Midterm Test_lrayan_attempt_2026-10-23-09-22-10_testQ2.cpp

````cpp
// Question 2.1

int * positiveValues(const int *source, int size, int& count) {
	int *destination = nullptr;
	
	count = 0;
	
	if (source != nullptr && size > 0) {
		for (int i = 0; i < size; i++) {
			if (source[i] > 0) count++;
		}
	}

	if (count) {
		destination = new int[count];
		
		int j = 0;
		
		for (int i = 0; i < size; i++) {
			if (source[i] > 0) destination[j++] = source[i];
		}
	}
	
	return destination;
}

// Statement to release resource allocation
delete [] result;

````

## Midterm Test_lrayan_attempt_2026-10-23-09-22-10_testq1p4.cpp

````cpp
// Question 1.4

bool keepWithin(long long& value, long long min, long long max) {
	bool ret = false;
	
	if (value < min) {
		value = min;
		ret = true;
	}
	
	if (value > max) {
		value = max;
		ret = true;
	}
	
	return ret;
}


bool keepWithin(double& value, double min, double max) {
	bool ret = false;
	
	if (value < min) {
		value = min;
		ret = true;
	}
	
	if (value > max) {
		value = max;
		ret = true;
	}
	
	return ret;
}

````

## Midterm Test_lrayan_attempt_2026-10-23-09-22-10_testq3p2.cpp

````cpp
// Question 3.2

// PrintAccount.h
#pragma once
#ifndef PRINT_ACCOUNT_H
#define PRINT_ACCOUNT_H

namespace seneca {
	class PrintAccount {
		private:
			char *m_holder;
			long m_credits;
		public:
			PrintAccount();
			PrintAccount(const char *holder, long credits);
			~PrintAccount();
			long credits() const;
			void show() const;
			operator bool() const;
			operator+=(long credits);
			operator-=(long credits);
	}
}

#endif

// PrintAccount.cpp
#include <iostream>
#include <cstring>

#include "PrintAccount.h"

using namespace seneca;

PrintAccount::PrintAccount() {
	m_holder = nullptr;
	m_credits = 0;
}


PrintAccount::PrintAccount(const char *holder, long credits) {
	if (holder == nullptr || !holder[0] || credits < 0) {
		m_credits = 0;
		m_holder = nullptr;
	} else {
		int len = strlen(holder);
		
		m_credits = credits;
		m_holder = new char[len + 1];
		
		strcpy(m_holder, holder);
	}
}


PrintAccount::~PrintAccount() {
	if (m_holder) delete [] m_holder;
	
	m_holder = nullptr;
}


long PrintAccount::credits() const {
	return m_credits;
}


PrintAccount::operator bool() const {
	return m_holder != nullptr;
}


PrintAccount::operator+=(long credits) {
	if (m_holder != nullptr && m_credits > 0) m_credits += credits;
	
	return this;
}


PrintAccount::operator+=(long credits) {
	if (m_holder != nullptr && m_credits > 0 && credits <= m_credits) m_credits -= credits;
	
	return this;
}


void PrintAccount::show() const {
	if (this) {
		std::cout << m_holder << ": " << m_credits << " credits" << std::endl;
	} else {
		std::cout << "Invalid print account" << std::endl;
	}
}

````

# Feedback

# Midterm Test

Student: Labeeb Rayan
Seneca User ID: lrayan
Assessment Version: Question 1.4, Question 2.1, Question 3.2
Points: **120.0**/124
Final Mark: **67.45**/70

## Marking

### Question 1.4

#### Long long overload

* 5/5 signature - bool return type: 1, function name keepWithin: 1, long long reference parameter: 1, long long minimum limit by value: 1, long long maximum limit by value: 1
* 1/1 initialize change tracking to false: 1
* 3/3 minimum limit handling - identify value below minimum limit: 1, assign minimum limit to referenced value: 1, record the change: 1
* 3/3 maximum limit handling - identify value above maximum limit: 1, assign maximum limit to referenced value: 1, record the change: 1
* 1/1 return correct change status using a single return statement at the end: 1
#### Double overload

* 5/5 signature - bool return type: 1, function name keepWithin: 1, double reference parameter: 1, double minimum limit by value: 1, double maximum limit by value: 1
* 1/1 initialize change tracking to false: 1
* 3/3 minimum limit handling - identify value below minimum limit: 1, assign minimum limit to referenced value: 1, record the change: 1
* 3/3 maximum limit handling - identify value above maximum limit: 1, assign maximum limit to referenced value: 1, record the change: 1
* 1/1 return correct change status using a single return statement at the end: 1

Question points: **26**/26. Question mark: **10.00**/10.

### Question 2.1

#### Function definition

* 6/6 signature - int* return type: 1, function name positiveValues: 1, const source elements: 1, int pointer parameter: 1, int size by value: 1, int count by reference: 1
* 2/2 initialization - result initialized to nullptr: 1, output count initialized to zero: 1
* 3/3 input validation - check source is not nullptr: 1, check size is positive: 1, process source only when both conditions hold: 1
* 5/5 counting - start at index zero: 1, traverse exactly size elements: 1, advance index: 1, identify strictly positive values: 1, increment output count for each positive value: 1
* 1/1 allocate and copy only when positive values exist: 1
* 3/3 allocation - use new[]: 1, allocate int elements: 1, allocate exactly count elements and retain their address: 1
* 1/1 initialize destination index to zero: 1
* 3/3 source traversal - start at index zero: 1, traverse exactly size elements: 1, advance index: 1
* 4/4 copying - select strictly positive values: 1, copy source value into destination: 1, advance destination index only after copying: 1, preserve original order without modifying source: 1
* 2/2 return - return allocated address or nullptr as appropriate: 1, use a single return statement at the end: 1
#### Caller cleanup

* 2/2 deallocation - use array delete[]: 1, apply it to the caller's result pointer: 1

Question points: **32**/32. Question mark: **18.00**/18.

### Question 3.2

#### Inclusion guard

* 2/2 inclusion guard - matching #ifndef and #define: 1, closing #endif: 1
#### Header namespace

* 1/1 place class in namespace seneca: 1
#### Class and private data

* 6/6 class and data - class declaration: 1, private data members: 1, char pointer for holder name: 2, long for credit count: 2
#### Header inclusions

* 3/3 inclusions - iostream: 1, cstring: 1, PrintAccount.h: 1
#### Implementation namespace

* 1/1 define member functions in namespace seneca: 1
#### Default constructor

* 1/1 correct default constructor signature and class scope: 1
* 2/2 safe empty state - holder pointer set to nullptr: 1, credit count set to zero: 1
#### Two-argument constructor

* 3/3 signature - constructor name and class scope: 1, const char* holder parameter: 1, long credit parameter: 1
* 4/4 validation - reject nullptr before dereferencing: 1, reject empty holder name: 1, accept only nonnegative credit counts: 1, leave invalid objects in safe empty state without allocation: 1
* 5/5 independent string storage - allocate character array: 1, determine holder name length: 1, include space for null terminator: 1, retain allocated address in m_holder: 1, copy complete holder string: 1
* 1/1 store valid initial credit count: 1
#### Destructor

* 1/1 correct destructor signature and class scope: 1
* 2/2 release holder storage - use array delete[]: 1, apply to m_holder: 1
#### Conversion to bool

* 2/2 signature - conversion operator with no return type and correct class scope: 1, const qualification: 1
* 1/1 return validity based on holder name, including true for valid objects with zero credits: 1
#### Credit count query

* 3/3 signature - long return type: 1, credits name and class scope: 1, const qualification: 1
* 1/1 return stored credit count: 1
#### Addition assignment operator

* 2/3 signature - PrintAccount& return type: 1, operator+= name and class scope: 1, long parameter: 1
  - Declare and define both operators with a PrintAccount& return type. This repeated missing-return-type error is counted here once.
* 1.5/3 validation - require valid holder name: 1, require positive amount: 1, leave object unchanged when either condition fails: 1
  - Check credits > 0, not m_credits > 0. The current check can accept a negative amount and prevents adding credits to a valid zero balance. The same check in subtraction is counted here once.
* 1/1 increase credit count by the specified amount: 1
* 0.5/1 return current object by reference using a single return statement at the end: 1
  - Return *this, not this, to return the current object by reference. This repeated return-expression mistake is counted here once.
#### Subtraction assignment operator

* 3/3 signature - PrintAccount& return type: 1, operator-= name and class scope: 1, long parameter: 1
* 4/4 validation - require valid holder name: 1, require positive amount: 1, require sufficient credits including exact remaining amount: 1, leave object unchanged when any condition fails: 1
* 1/1 subtract specified amount while preserving holder name: 1
* 1/1 return current object by reference using a single return statement at the end: 1
#### Output

* 3/3 signature - void return type: 1, show name and class scope: 1, const qualification: 1
* 0/1 distinguish valid objects from the safe empty state using holder name: 1
  - Test the object through its conversion operator or m_holder. this is a pointer to the current object and does not indicate whether the account is valid.
* 4/4 valid output - holder name: 1, colon and space: 1, credit count: 1, space followed by credits: 1
* 1/1 display required message for safe empty state: 1
* 1/1 end either output with a newline: 1

Question points: **62.0**/66. Question mark: **39.45**/42.

Points: **120.0**/124
Final Mark: **67.45**/70

## Feedback

Labeeb, both range functions and the dynamic array function are correct. Your constructors, string storage, cleanup, and queries are also well structured. Review the reference return type and return *this for the assignment operators. Validate the amount being added or subtracted, rather than the current balance. In show(), test the account validity instead of the this pointer.

# Rubric

## Question 1.4

````cpp
//# 10
// Question1.4

//+ Long long overload
bool keepWithin(long long& value, long long minimum, long long maximum) {
   //- 5 signature - bool return type: 1, function name keepWithin: 1, long long reference parameter: 1, long long minimum limit by value: 1, long long maximum limit by value: 1

   //+
   bool changed = false;
   //- 1 initialize change tracking to false: 1

   //+
   if (value < minimum) {
      value = minimum;
      changed = true;
   }
   //- 3 minimum limit handling - identify value below minimum limit: 1, assign minimum limit to referenced value: 1, record the change: 1

   //+
   else if (value > maximum) {
      value = maximum;
      changed = true;
   }
   //- 3 maximum limit handling - identify value above maximum limit: 1, assign maximum limit to referenced value: 1, record the change: 1

   //+
   return changed;
   //- 1 return correct change status using a single return statement at the end: 1
}

//+ Double overload
bool keepWithin(double& value, double minimum, double maximum) {
   //- 5 signature - bool return type: 1, function name keepWithin: 1, double reference parameter: 1, double minimum limit by value: 1, double maximum limit by value: 1

   //+
   bool changed = false;
   //- 1 initialize change tracking to false: 1

   //+
   if (value < minimum) {
      value = minimum;
      changed = true;
   }
   //- 3 minimum limit handling - identify value below minimum limit: 1, assign minimum limit to referenced value: 1, record the change: 1

   //+
   else if (value > maximum) {
      value = maximum;
      changed = true;
   }
   //- 3 maximum limit handling - identify value above maximum limit: 1, assign maximum limit to referenced value: 1, record the change: 1

   //+
   return changed;
   //- 1 return correct change status using a single return statement at the end: 1
}
````

## Question 2.1

````cpp
//# 18
// Question2.1

//+ Function definition
int* positiveValues(const int* source, int size, int& count) {
   //- 6 signature - int* return type: 1, function name positiveValues: 1, const source elements: 1, int pointer parameter: 1, int size by value: 1, int count by reference: 1

   //+
   int* result = nullptr;
   count = 0;
   //- 2 initialization - result initialized to nullptr: 1, output count initialized to zero: 1

   //+
   if (source != nullptr && size > 0) {
      //- 3 input validation - check source is not nullptr: 1, check size is positive: 1, process source only when both conditions hold: 1

      //+
      for (int i = 0; i < size; i++) {
         if (source[i] > 0) {
            count++;
         }
      }
      //- 5 counting - start at index zero: 1, traverse exactly size elements: 1, advance index: 1, identify strictly positive values: 1, increment output count for each positive value: 1

      //+
      if (count > 0) {
         //- 1 allocate and copy only when positive values exist: 1

         //+
         result = new int[count];
         //- 3 allocation - use new[]: 1, allocate int elements: 1, allocate exactly count elements and retain their address: 1

         //+
         int next = 0;
         //- 1 initialize destination index to zero: 1

         //+
         for (int i = 0; i < size; i++) {
            //- 3 source traversal - start at index zero: 1, traverse exactly size elements: 1, advance index: 1

            //+
            if (source[i] > 0) {
               result[next] = source[i];
               next++;
            }
            //- 4 copying - select strictly positive values: 1, copy source value into destination: 1, advance destination index only after copying: 1, preserve original order without modifying source: 1
         }
      }
   }

   //+
   return result;
   //- 2 return - return allocated address or nullptr as appropriate: 1, use a single return statement at the end: 1
}

//+ Caller cleanup
delete[] result;
//- 2 deallocation - use array delete[]: 1, apply it to the caller's result pointer: 1
````

## Question 3.2

````cpp
//# 42
// Question3.2

// PrintAccount.h

//+ Inclusion guard
#ifndef SENECA_PRINTACCOUNT_H
#define SENECA_PRINTACCOUNT_H
//- 2 inclusion guard - matching #ifndef and #define: 1, closing #endif: 1

//+ Header namespace
namespace seneca {
   //- 1 place class in namespace seneca: 1

   //+ Class and private data
   class PrintAccount {
      char* m_holder;
      long m_credits;
      //- 6 class and data - class declaration: 1, private data members: 1, char pointer for holder name: 2, long for credit count: 2

   public:
      PrintAccount();
      PrintAccount(const char* holder, long credits);
      ~PrintAccount();
      operator bool() const;
      long credits() const;
      PrintAccount& operator+=(long amount);
      PrintAccount& operator-=(long amount);
      void show() const;
   };
}
#endif


// PrintAccount.cpp

//+ Header inclusions
#include <iostream>
#include <cstring>
#include "PrintAccount.h"
//- 3 inclusions - iostream: 1, cstring: 1, PrintAccount.h: 1

using namespace std;

//+ Implementation namespace
namespace seneca {
   //- 1 define member functions in namespace seneca: 1

   //+ Default constructor
   PrintAccount::PrintAccount() {
      //- 1 correct default constructor signature and class scope: 1

      //+
      m_holder = nullptr;
      m_credits = 0;
      //- 2 safe empty state - holder pointer set to nullptr: 1, credit count set to zero: 1
   }

   //+ Two-argument constructor
   PrintAccount::PrintAccount(const char* holder, long credits) {
      //- 3 signature - constructor name and class scope: 1, const char* holder parameter: 1, long credit parameter: 1

      //+
      m_holder = nullptr;
      m_credits = 0;
      if (holder != nullptr && holder[0] != '\0' && credits >= 0) {
         //- 4 validation - reject nullptr before dereferencing: 1, reject empty holder name: 1, accept only nonnegative credit counts: 1, leave invalid objects in safe empty state without allocation: 1

         //+
         m_holder = new char[strlen(holder) + 1];
         strcpy(m_holder, holder);
         //- 5 independent string storage - allocate character array: 1, determine holder name length: 1, include space for null terminator: 1, retain allocated address in m_holder: 1, copy complete holder string: 1

         //+
         m_credits = credits;
         //- 1 store valid initial credit count: 1
      }
   }

   //+ Destructor
   PrintAccount::~PrintAccount() {
      //- 1 correct destructor signature and class scope: 1

      //+
      delete[] m_holder;
      //- 2 release holder storage - use array delete[]: 1, apply to m_holder: 1
   }

   //+ Conversion to bool
   PrintAccount::operator bool() const {
      //- 2 signature - conversion operator with no return type and correct class scope: 1, const qualification: 1

      //+
      return m_holder != nullptr;
      //- 1 return validity based on holder name, including true for valid objects with zero credits: 1
   }

   //+ Credit count query
   long PrintAccount::credits() const {
      //- 3 signature - long return type: 1, credits name and class scope: 1, const qualification: 1

      //+
      return m_credits;
      //- 1 return stored credit count: 1
   }

   //+ Addition assignment operator
   PrintAccount& PrintAccount::operator+=(long amount) {
      //- 3 signature - PrintAccount& return type: 1, operator+= name and class scope: 1, long parameter: 1

      //+
      if (m_holder != nullptr && amount > 0) {
         //- 3 validation - require valid holder name: 1, require positive amount: 1, leave object unchanged when either condition fails: 1

         //+
         m_credits += amount;
         //- 1 increase credit count by the specified amount: 1
      }

      //+
      return *this;
      //- 1 return current object by reference using a single return statement at the end: 1
   }

   //+ Subtraction assignment operator
   PrintAccount& PrintAccount::operator-=(long amount) {
      //- 3 signature - PrintAccount& return type: 1, operator-= name and class scope: 1, long parameter: 1

      //+
      if (m_holder != nullptr && amount > 0 && amount <= m_credits) {
         //- 4 validation - require valid holder name: 1, require positive amount: 1, require sufficient credits including exact remaining amount: 1, leave object unchanged when any condition fails: 1

         //+
         m_credits -= amount;
         //- 1 subtract specified amount while preserving holder name: 1
      }

      //+
      return *this;
      //- 1 return current object by reference using a single return statement at the end: 1
   }

   //+ Output
   void PrintAccount::show() const {
      //- 3 signature - void return type: 1, show name and class scope: 1, const qualification: 1

      //+
      if (m_holder != nullptr) {
         //- 1 distinguish valid objects from the safe empty state using holder name: 1

         //+
         cout << m_holder << ": " << m_credits << " credits";
         //- 4 valid output - holder name: 1, colon and space: 1, credit count: 1, space followed by credits: 1
      }
      else {
         //+
         cout << "Invalid print account";
         //- 1 display required message for safe empty state: 1
      }

      //+
      cout << endl;
      //- 1 end either output with a newline: 1
   }
}
````

