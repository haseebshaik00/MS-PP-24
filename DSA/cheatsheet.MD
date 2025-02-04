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
- String i/o
    char *s= NULL; // null string - char pointer not pointing to anything - dangerous to handle - not a valid string - shows undefined behaviour
    string s0; // null string
    string s1="Hello", s2("ji"), s3(s2);
    string s4=s3;
    char a[] ={'j','o','\0'};
    string s5(a);
    cout<<s0<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<endl;
- C++ String Functions
- `str1 + str2` – Concatenates two strings.  
- `str1.append(str2);` – Appends `str2` to `str1`.  
- `str[index]` – Accesses character at the given index.  
- `str.at(index);` – Accesses character at the given index with bounds checking.  
- `str.front();` – Returns the first character of the string.  
- `str.back();` – Returns the last character of the string.  
- `str.length();` – Returns the length of the string.  
- `str.size();` – Returns the number of characters (same as `length()`).  
- `str.capacity();` – Returns the storage capacity of the string.  
- `str.empty();` – Checks if the string is empty.  
- `str.resize(new_size);` – Resizes the string to the given size.  
- `str.substr(pos, len);` – Extracts a substring from the string.  
- `str.find("word");` – Finds the first occurrence of "word".  
- `str.rfind("word");` – Finds the last occurrence of "word".  
- `str1.compare(str2);` – Compares two strings lexicographically.  
- `str.insert(pos, "text");` – Inserts "text" at a given position.  
- `str.erase(pos, len);` – Erases `len` characters from `pos`.  
- `str.replace(pos, len, "new text");` – Replaces a portion with new text.  
- `str.push_back('A');` – Appends a character at the end.  
- `str.pop_back();` – Removes the last character.  
- `std::stoi(str);` – Converts string to an integer.  
- `std::to_string(num);` – Converts a number to a string.
- `std::stol(str);` – Converts string to a long.  
- `std::stoll(str);` – Converts string to a long long.  
- `std::stof(str);` – Converts string to a float.  
- `std::stod(str);` – Converts string to a double.  
- `std::stold(str);` – Converts string to a long double.
- `std::transform(str.begin(), str.end(), str.begin(), ::toupper);` – Converts to uppercase.  
- `std::transform(str.begin(), str.end(), str.begin(), ::tolower);` – Converts to lowercase.  
- `str.c_str();` – Returns a `const char*` (C-style string).
- `str a(c)` - char array to string where c is char* array
- `if(a.find(b) != string::npos) return true;` check if string b is a substring of a or not

## Utility - Pair
#include <utility> 
pair<int, string> p = {1, "Hello"};
pair<int, char> p1(10, 'A');  // Using constructor
pair<string, double> p2 = make_pair("Price", 99.99); // Using make_pair
map m.insert(pair<int, string>(2, "Two"));

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
