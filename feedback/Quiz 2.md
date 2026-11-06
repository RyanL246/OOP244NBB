# Quiz Question(s)

# Quiz 2 – Version 4

## Before You Start

If Notepad++ is not open, [click here to go to MyApps](https://myapps.senecapolytechnic.ca), open **Notepad++**, and save a file named `test.cpp` on your **Desktop**.

**DO NOT copy and paste your answer into the quiz answer box.**

Write and save your answer in `test.cpp`. When you are finished, attach the file to your answer by either:

- Dragging and dropping `test.cpp` from your Desktop into the answer area.
- Clicking the attachment icon and selecting `test.cpp`.

---

## Quiz 2

The focus of this quiz is to assess your ability to **encapsulate data and behaviour in a class**, properly construct and destroy objects, and manage dynamic memory without memory leaks.

Create the required class as if the entire implementation is contained in **one file**. No separate module files are required. All the required code must be written **inside the class definition**.

Assume that all necessary header files have already been included.

### The `Storage` Class

Create a class called `Storage`.

A `Storage` object has:

- A dynamically allocated C-string that stores the name of the material held in the Storage.
- A `float` that stores the weight of the material in **kilograms**.

### Construction

Create the constructor or constructors needed to allow a `Storage` object to be created using:

- The material name.
- The weight of the material in kilograms.

If the weight is not provided, it must default to **5.0 kilograms**.

If the material name passed to the constructor is a **null pointer**, the `Storage` object must be placed in a **safe empty state**.

### Destruction

When a `Storage` object goes out of scope and is destroyed, make sure that any dynamically allocated memory owned by the object is properly deallocated.

**Note:** Assume that the values passed to the loading and unloading methods are always non-negative.

### Loading Material

Create a method that receives a `float` value and increases the current weight of material in the `Storage` by that amount.

The method must return a **reference to the current object**.

### Unloading Material

Create a method that receives a `float` value and decreases the current weight of material in the `Storage` by that amount.

The method must return a **reference to the current object**.

If decreasing the weight causes the weight to become negative, the `Storage` must be placed in a **safe empty state**.

### Empty-State Check

Create a method that returns `true` if the `Storage` is in a **safe empty state**, and `false` otherwise.

### Displaying the Storage

Create a method that prints the information of the `Storage` in the following format:

`[Material Name] ## kg.`

Where:

- `Material Name` is replaced by the name of the material held in the `Storage`.
- `##` is replaced by the weight of the material in kilograms.

For example:

`Sand 12.5 kg.`

If the `Storage` is in a safe empty state, print:

`[Empty Storage]`

The method must:

- Receive an `ostream` object by reference as its argument.
- Return a reference to that same `ostream` object.
- Default the `ostream` argument to `cout` when no argument is provided.

# Original Student Answer

## Quiz 2_lrayan_attempt_2026-10-16-09-36-35_test.cpp

````cpp
class Storage {
		private:
			char *m_material;
			float m_weight;
			
		public:
			Storage(const char *material, float weight = 0.0) {
				if (!material) {
					m_weight = 0.0;
					m_material = nullptr;
				}
				
				m_weight = (weight) ? weight : 5.0;
				m_material = new char[strlen(material)];
				
				strcpy(m_material, material);
			}
			
			~Storage() {
				if (m_material) delete [] m_material;
				
				m_weight = 0.0;
				m_material = nullptr;
			}
			
			Storage& load(float weight) {
				m_weight = m_weight + weight;
					
				return this;
			}
			
			Storage& unload(float weight) {
				m_weight = m_weight - weight;
					
				if (weight < 0.0) {
					if (m_material) delete [] m_material;
					
					m_weight = 0.0;
					m_material = nullptr;
				}
					
				return this;
			}
			
			bool is_empty() const {
				return !m_material && !m_weight;
			}
			
			std::ostream& dislpay(std::ostream& os = cout) const {
				if (this.is_empty()) {
					os << "[Empty Storage]";
				} else {
					os << "[" << m_material << "] " << m_weight << "kg";
				}
				
				return os;
			}
}
````

# Feedback

# Quiz 2

Student: Labeeb Rayan
Seneca User ID: lrayan
Assessment Version: Version 4
Points: **69**/75
Final Mark: **9.20**/10

## Marking

### Class declaration and attributes
* 2/2 Class declaration - class: 1, Storage: 1
* 4/4 Attributes - char*: 1, m_material: 1, float: 1, m_weight: 1

### Constructor
* 5/5 Signature - Storage: 1, const char*: 1, material: 1, float weight: 1, default value 5.0f: 1
* 2/2 Initial safe state - null pointer: 1, zero weight: 1
* 1/2 Validity check - if: 1, material != nullptr: 1
  - The null-pointer test is present, but execution continues into strlen and strcpy even when material is null. Put allocation and copying in an else block, or return after setting the empty state.
* 4/5 Dynamic allocation - m_material assignment: 1, new char[]: 1, strlen(): 1, material: 1, +1: 1
  - Allocate strlen(material) + 1 characters to leave room for the null terminator.
* 3/3 String copy - strcpy: 1, destination m_material: 1, source material: 1
* 1/2 Weight initialization - m_weight: 1, weight: 1
  - The fallback gives 5.0 when the argument is omitted, but it also changes an explicitly supplied zero weight to 5.0. Preserve a supplied zero; use 5.0 as the parameter default.

### Destructor
* 2/2 Signature - ~Storage: 2
* 3/3 Memory deallocation - delete[]: 2, m_material: 1

### Loading Material
* 4/4 Signature - Storage&: 2, load: 1, float weight: 1
* 2/3 Addition - validity check: 1, m_weight +=: 1, weight: 1
  - Check that the object is valid before changing its weight. This missing guard is deducted once for load and unload.
* 1/2 Return current object - return: 1, *this: 1
  - Return *this, which is the object, rather than this, which is a pointer. The same mistake in unload is not deducted again.

### Unloading Material
* 4/4 Signature - Storage&: 2, unload: 1, float weight: 1
* 3/3 Reduction - validity check: 1, m_weight -=: 1, weight: 1
* 1/2 Negative weight check - if: 1, m_weight < 0: 1
  - Check m_weight after subtraction, not the parameter weight. The parameter is non-negative, so the current check never triggers the cleanup.
* 5/5 Safe empty state - delete[]: 2, m_material: 1, nullptr: 1, m_weight = 0: 1
* 2/2 Return current object - return: 1, *this: 1

### Empty-state check
* 3/3 Signature - bool: 1, isEmpty: 1, const: 1
* 3/3 Empty-state detection - return: 1, m_material: 1, == nullptr: 1

### Displaying the Storage
* 5/5 Signature - ostream& return: 1, display: 1, ostream& argument: 1, default cout: 1, const: 1
* 3/3 Empty display - empty-state check: 1, ostr output: 1, exact "[Empty Storage]" text: 1
* 4/4 Valid display - ostr output: 1, material name: 1, weight: 1, correct spacing and " kg.": 1
* 2/2 Return output stream - return: 1, ostr: 1

Points: **69**/75
Final Mark: **9.20**/10

## Feedback

Labeeb, you showed the class structure, dynamic allocation and copying, destructor, arithmetic, and stream handling well. Stop the constructor after setting an empty state for a null name, and allocate one extra character for the string terminator. Keep a supplied zero weight unchanged. Guard empty objects before loading or unloading, return *this from both methods, and check the stored weight after subtraction so the cleanup runs when needed.

# Rubric

````cpp

//# 10

//+ Class declaration and attributes
class Storage {
   //- 2 Class declaration - class: 1, Storage: 1

      //+
   char* m_material;
   float m_weight;
   //- 4 Attributes - char*: 1, m_material: 1, float: 1, m_weight: 1

public:
   //+ Constructor
   Storage(const char* material, float weight = 5.0f) {
      //- 5 Signature - Storage: 1, const char*: 1, material: 1, float weight: 1, default value 5.0f: 1

         //+
      m_material = nullptr;
      m_weight = 0;
      //- 2 Initial safe state - null pointer: 1, zero weight: 1

      //+
      if (material != nullptr) {
         //- 2 Validity check - if: 1, material != nullptr: 1

            //+
         m_material = new char[strlen(material) + 1];
         //- 5 Dynamic allocation - m_material assignment: 1, new char[]: 1, strlen(): 1, material: 1, +1: 1

         //+
         strcpy(m_material, material);
         //- 3 String copy - strcpy: 1, destination m_material: 1, source material: 1

         //+
         m_weight = weight;
         //- 2 Weight initialization - m_weight: 1, weight: 1
      }
   }

   //+ Destructor
   ~Storage() {
      //- 2 Signature - ~Storage: 2

         //+
      delete[] m_material;
      //- 3 Memory deallocation - delete[]: 2, m_material: 1
   }

   //+ Loading Material
   Storage& load(float weight) {
      //- 4 Signature - Storage&: 2, load: 1, float weight: 1

         //+
      if (m_material != nullptr) {
         m_weight += weight;
      }
      //- 3 Addition - validity check: 1, m_weight +=: 1, weight: 1

      //+
      return *this;
      //- 2 Return current object - return: 1, *this: 1
   }

   //+ Unloading Material
   Storage& unload(float weight) {
      //- 4 Signature - Storage&: 2, unload: 1, float weight: 1

         //+
      if (m_material != nullptr) {
         m_weight -= weight;
         //- 3 Reduction - validity check: 1, m_weight -=: 1, weight: 1

            //+
         if (m_weight < 0) {
            //- 2 Negative weight check - if: 1, m_weight < 0: 1

               //+
            delete[] m_material;
            m_material = nullptr;
            m_weight = 0;
            //- 5 Safe empty state - delete[]: 2, m_material: 1, nullptr: 1, m_weight = 0: 1
         }
      }

      //+
      return *this;
      //- 2 Return current object - return: 1, *this: 1
   }

   //+ Empty-state check
   bool isEmpty() const {
      //- 3 Signature - bool: 1, isEmpty: 1, const: 1

         //+
      return m_material == nullptr;
      //- 3 Empty-state detection - return: 1, m_material: 1, == nullptr: 1
   }

   //+ Displaying the Storage
   ostream& display(ostream& ostr = cout) const {
      //- 5 Signature - ostream& return: 1, display: 1, ostream& argument: 1, default cout: 1, const: 1

         //+
      if (isEmpty()) {
         ostr << "[Empty Storage]";
      }
      //- 3 Empty display - empty-state check: 1, ostr output: 1, exact "[Empty Storage]" text: 1

      //+
      else {
         ostr << m_material << " " << m_weight << " kg.";
      }
      //- 4 Valid display - ostr output: 1, material name: 1, weight: 1, correct spacing and " kg.": 1

      //+
      return ostr;
      //- 2 Return output stream - return: 1, ostr: 1
   }
};

````
