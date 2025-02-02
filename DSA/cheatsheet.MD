# Cheatsheet

## Arrays

1) Size of array: sizeof(a)/sizeof(a[0])
2) Pass 1D array to a function
- Using a Pointer (Decay to Pointer): void func(int *arr, int size) : Array decays to a pointer, losing its original size.
- Using Array Syntax: void func(int arr[], int size) : same as above
- Using Fixed-Size Array: void func(int arr[3]) : Only works for fixed-size arrays
- Using References: void func(int (&arr)[3]) : Preserves size, doesn’t decay to a pointer, Works only for arrays of fixed size.
3) Pass 2D array to a function
- Using Pointer: void printArray(int (*arr)[3], int rows) //void printArray(int arr[2][3]); eventually decays to a pointer *arr[3]
- Using Array Syntax: void printArray(int arr[][3], int rows) 
- Use a Pointer to Pointer: void printArray(int** arr, int rows, int cols)
- Using Reference: void printArray(int (&arr)[2][3])

## Char

- cin.get(s, 10); // take input of a string
- cin.get(); //cin.ignore(); // use to ignore enter pressed after input
- instead of that, point 1 n 2, use -- cin.getline(x, 10);
- Functions:
isalnum(c) → Checks if c is alphanumeric (letter or digit).
isalpha(c) → Checks if c is a letter (A-Z, a-z).
islower(c) → Checks if c is a lowercase letter.
isupper(c) → Checks if c is an uppercase letter.
isdigit(c) → Checks if c is a digit (0-9).
isspace(c) → Checks if c is a whitespace character.
isblank(c) → Checks if c is a blank space.
ispunct(c) → Checks if c is a punctuation mark.
tolower(c) → Converts c to lowercase.
toupper(c) → Converts c to uppercase.
strlen(str) → Returns the length of the string.
strcmp(str1, str2) → Compares two strings.
strcpy(dest, src) → Copies src to dest.
strncpy(dest, src, n) → Copies first n characters of src to dest.
strcat(dest, src) → Appends src to dest.
strncat(dest, src, n) → Appends first n characters of src to dest.
string(1, c) → Converts char to string.
s.c_str() → Converts string to char*.

## Strings
- convert string to lowercase: transform(str.begin(), str.end(), str.begin(), ::tolower);
- 


## STL
The C++ Standard Template Library (STL) is a powerful set of generic classes and functions that provide common data structures and algorithms. It includes containers, iterators, algorithms, and function objects, making it easier to write efficient and reusable code.

### Containers
Sequential Containers: vector, deque, list, forward_list, array, string
Associative Containers: set, multiset, map, multimap
Unordered Containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap

### Iterators
Input Iterator: istream_iterator
Output Iterator: ostream_iterator
Forward Iterator: forward_list
Bidirectional Iterator: list, set, map
Random Access Iterator: vector, deque

### Algorithms
#include<algorithm>
Sorting: sort(), stable_sort(), partial_sort()
Searching: binary_search(), find(), equal_range()
Modifying: copy(), replace(), fill()
Numeric: accumulate(), inner_product(), partial_sum()
Set Operations: set_union(), set_intersection()
min() max()

### Function Objects (Functors)
greater<T>(), less<T>(), equal_to<T>(), Custom functors

### Utility Components
pair, tuple, optional, variant, any

## Miscellaneous
- #include<climits>: INT_MIN, INT_MAX
