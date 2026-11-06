# Quiz Question(s)

## Dynamic Double Array Management

Create a module consisting of a **header file** and a **CPP file** for managing dynamically allocated arrays of `double` values.

Your module must provide the following three functions.

### `allocate`

The `allocate` function receives two arguments:

- A `size_t` value specifying the number of elements to allocate.
- A `double` value used to initialize every element of the array.

The function must:

1. Dynamically allocate an array of `double` values with the specified number of elements.
2. Initialize every element of the array to the supplied value.
3. Return a `double*` pointing to the dynamically allocated array.

### `free`

The `free` function receives a **reference to a pointer** to a dynamically allocated array of `double` values.

The function must:

1. Deallocate the dynamic array.
2. Set the pointer passed by reference to `nullptr`.

This function does not return a value.

### `resize`

The `resize` function receives three arguments:

- A reference to a pointer to a dynamically allocated array of `double` values.
- A `size_t` value specifying the current number of elements.
- A `size_t` value specifying the new number of elements.

If the new size is zero, the function must call `free` to deallocate the original array and set the pointer to `nullptr`.

Otherwise, the function must:

1. Dynamically allocate a new array of `double` values using the new size and store its address in a temporary pointer.
2. Copy elements from the original array to the new array, up to the smaller of the current size and the new size.
3. Deallocate the original array.
4. Update the pointer passed by reference so it points to the newly allocated array.

If the new array is larger than the original array, the additional elements do **not** need to be initialized.

This function does not return a value.

## Submission Format

Use **Notepad++**, installed through MyApps, to create a **single text file** containing the contents of both your header file and CPP file.

Use the following format and replace the placeholders with your chosen filenames and code:

```text
// Header file
// Header file name: [name goes here]
// Header file content goes here:




// CPP file
// CPP file name: [name goes here]
// CPP file content goes here:
```

# Original Student Answer

File: test.cpp

```cpp
// Header file
// Header file name: DynamicDouble.h

double * allocate(size_t, double);
void free(double& *);
void resize(double& *, size_t, size_t);

// CPP file
// CPP file name: DynamicDouble.cpp
double * allocate(size_t n, double value) {
	double *alloc = new double[n];
	
	for (size_t i = 0; i < n; i++) alloc[i] = value;
	
	return alloc;
}


void free(double& *src) {
	delete [] src;
	
	src = nullptr;
}


void resize(double& *src, size_t old_size, size_t new_size) {
	double *dst = new double[new_size];
	
	for (size_t i = 0; i < old_size; i++) dst[i] = src[i];
	
	delete [] src;
	
	src = dst;
}

```

# Feedback

# Quiz 1

Student: Labeeb Rayan
Seneca User ID: lrayan
Assessment Version: Version 1
Points: **59**/70
Final Mark: **8.43**/10

## Marking

### Header
* 0/2 Opening header safeguard
  - The #ifndef and #define header guard is missing.
* 0/1 Required include for size_t
  - Include <cstddef> in the header to declare size_t.
* 4/4 allocate prototype
* 4/4 free prototype
* 6/6 resize prototype
* 0/1 Closing header safeguard
  - The closing #endif is missing.

### Module Implementation
* 0/1 Include module header
  - The CPP file must include DynamicDouble.h.

### allocate Implementation
* 4/4 Signature
* 4/4 Dynamic allocation
* 6/6 Initialization loop
* 1/1 Return allocated array address

### free Implementation
* 4/4 Signature
* 2/2 Array deallocation
* 1/1 Nullify caller's pointer

### resize Implementation
* 6/6 Signature
* 0/3 Zero-size handling
  - Check whether new_size is zero. In that case, call free(src) and do not allocate or copy an array.
* 4/4 Replacement allocation
* 2/5 Determine smaller copy size
  - Using old_size as the copy limit handles growth. The comparison with new_size and the smaller limit are missing. When shrinking, the loop writes past the end of dst.
* 7/7 Copy elements
* 2/2 Deallocate original array
* 2/2 Update caller's pointer

Points: **59**/70
Final Mark: **8.43**/10

## Feedback

Labeeb, your allocation and initialization logic is correct. You also delete the old array and update the caller's pointer correctly. Add the header guards, the include for size_t, and the module header include. In resize, handle a new size of zero by calling free. Copy only the smaller of the old and new sizes so shrinking does not write outside the new array. Write a reference to a pointer as double*& rather than double& *. Practise these changes with both growing and shrinking arrays.

# Rubric

```cpp
//# 10

// Header file
// Header file name: DoubleArray.h

//+ Header safeguard
#ifndef SENECA_DOUBLEARRAY_H
#define SENECA_DOUBLEARRAY_H
//- 2 header safeguard - #ifndef: 1, #define: 1

//+
#include <cstddef>
//- 1 required include for size_t: 1

//+ allocate prototype
double* allocate(size_t size, double value);
//- 4 allocate prototype - double* return type: 1, function name: 1, size_t parameter: 1, double parameter: 1

//+ free prototype
void free(double*& array);
//- 4 free prototype - void return type: 1, function name: 1, double* parameter: 1, reference &: 1

//+ resize prototype
void resize(double*& array, size_t currentSize, size_t newSize);
//- 6 resize prototype - void return type: 1, function name: 1, double* parameter: 1, reference &: 1, current size parameter: 1, new size parameter: 1

//+
#endif
//- 1 closing header safeguard: 1


// CPP file
// CPP file name: DoubleArray.cpp

//+ Module implementation
#include "DoubleArray.h"
//- 1 include module header: 1

using namespace std;


//+ allocate implementation
double* allocate(size_t size, double value) {
   //- 4 signature - double* return type: 1, function name: 1, size_t parameter: 1, double parameter: 1

      //+
   double* array = new double[size];
   //- 4 dynamic allocation - pointer declaration: 1, new: 1, double array: 1, requested size used: 1

   //+
   for (size_t i = 0; i < size; i++) {
      array[i] = value;
   }
   //- 6 initialization loop - for loop: 1, index initialization: 1, condition: 1, increment: 1, array element access: 1, supplied value assignment: 1

   //+
   return array;
   //- 1 returns allocated array address: 1
}


//+ free implementation
void free(double*& array) {
   //- 4 signature - void return type: 1, function name: 1, double* parameter: 1, reference &: 1

      //+
   delete[] array;
   //- 2 deallocation - delete[]: 1, correct pointer: 1

   //+
   array = nullptr;
   //- 1 nullifies caller's pointer: 1
}


//+ resize implementation
void resize(double*& array, size_t currentSize, size_t newSize) {
   //- 6 signature - void return type: 1, function name: 1, double* parameter: 1, reference &: 1, current size parameter: 1, new size parameter: 1

      //+
   if (newSize == 0) {
      free(array);
   }
   //- 3 zero-size handling - checks newSize == 0: 1, calls free: 1, passes original pointer: 1

   else {

      //+
      double* temp = new double[newSize];
      //- 4 replacement allocation - temporary pointer: 1, new: 1, double array: 1, newSize used: 1

      //+
      size_t copySize = currentSize;
      if (newSize < currentSize) {
         copySize = newSize;
      }
      //- 5 copy-size determination - initialized from currentSize: 1, compares sizes: 1, uses newSize: 1, uses currentSize: 1, updates copySize to newSize: 1

      //+
      for (size_t i = 0; i < copySize; i++) {
         temp[i] = array[i];
      }
      //- 7 copying elements - for loop: 1, index initialization: 1, copySize condition: 1, increment: 1, destination element: 1, assignment: 1, source element: 1

      //+
      delete[] array;
      //- 2 original array deallocation - delete[]: 1, original pointer: 1

      //+
      array = temp;
      //- 2 updates caller's pointer - original pointer assigned: 1, temporary pointer used: 1
   }
}
```
