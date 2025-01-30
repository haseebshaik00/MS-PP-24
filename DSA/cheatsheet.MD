# Cheatsheet

1) Size of array
sizeof(a)/sizeof(a[0])

#include<climits>
INT_MIN
INT_MAX

## STL
The C++ Standard Template Library (STL) is a powerful set of generic classes and functions that provide common data structures and algorithms. It includes containers, iterators, algorithms, and function objects, making it easier to write efficient and reusable code.

## Containers
Sequential Containers: vector, deque, list, forward_list, array, string
Associative Containers: set, multiset, map, multimap
Unordered Containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap

## Iterators
Input Iterator: istream_iterator
Output Iterator: ostream_iterator
Forward Iterator: forward_list
Bidirectional Iterator: list, set, map
Random Access Iterator: vector, deque

## Algorithms
#include<algorithm>
Sorting: sort(), stable_sort(), partial_sort()
Searching: binary_search(), find(), equal_range()
Modifying: copy(), replace(), fill()
Numeric: accumulate(), inner_product(), partial_sum()
Set Operations: set_union(), set_intersection()
min() max()

## Function Objects (Functors)
greater<T>(), less<T>(), equal_to<T>(), Custom functors

## Utility Components
pair, tuple, optional, variant, any

