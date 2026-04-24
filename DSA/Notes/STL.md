# STL Containers for LeetCode

This README summarizes commonly used C++ STL containers (vectors, map and set) and their important functions for solving LeetCode-style problems.

---

## `vector`

| Function | Time Complexity | Notes |
|---|---:|---|
| `push_back(x)` | `O(1)` amortized | Add element at the end. |
| `pop_back()` | `O(1)` | Remove the last element. |
| `v[i]` | `O(1)` | Direct index access. |
| `front()` | `O(1)` | Access the first element. |
| `back()` | `O(1)` | Access the last element. |
| `size()` | `O(1)` | Returns number of elements. |
| `empty()` | `O(1)` | Checks whether vector is empty. |
| `insert(pos, x)` | `O(n)` | Costly because elements may shift. |
| `erase(pos)` | `O(n)` | Costly because elements after `pos` shift left. |
| `sort(v.begin(), v.end())` | `O(n log n)` | Sorts the vector. |
| `reverse(v.begin(), v.end())` | `O(n)` | Reverses the vector in-place. |
| `lower_bound(...)` | `O(log n)` | Returns first element `>= x`; vector must be sorted. |
| `upper_bound(...)` | `O(log n)` | Returns first element `> x`; vector must be sorted. |

---

## `unordered_map`

| Function | Time Complexity | Notes |
|---|---:|---|
| `mp[key]` | `O(1)` average | Access or insert value by key. |
| `mp.at(key)` | `O(1)` average | Access existing key; throws error if absent. |
| `insert({key, val})` | `O(1)` average | Inserts key-value pair. |
| `find(key)` | `O(1)` average | Checks whether key exists. |
| `count(key)` | `O(1)` average | Returns `1` if key exists, else `0`. |
| `erase(key)` | `O(1)` average | Removes key-value pair. |
| `size()` | `O(1)` | Returns number of key-value pairs. |
| `empty()` | `O(1)` | Checks whether map is empty. |
| `clear()` | `O(n)` | Removes all key-value pairs. |

> Note: Worst-case time complexity can become `O(n)` due to hash collisions, but average case is usually `O(1)`.

---

## `map`

| Function | Time Complexity | Notes |
|---|---:|---|
| `mp[key]` | `O(log n)` | Access or insert value by key. |
| `mp.at(key)` | `O(log n)` | Access existing key; throws error if absent. |
| `insert({key, val})` | `O(log n)` | Inserts key-value pair. |
| `find(key)` | `O(log n)` | Checks whether key exists. |
| `count(key)` | `O(log n)` | Returns `1` if key exists, else `0`. |
| `erase(key)` | `O(log n)` | Removes key-value pair. |
| `lower_bound(key)` | `O(log n)` | First key `>= key`. |
| `upper_bound(key)` | `O(log n)` | First key `> key`. |
| `begin()` | `O(1)` | Iterator to smallest key. |
| `rbegin()` | `O(1)` | Iterator to largest key. |
| `size()` | `O(1)` | Returns number of key-value pairs. |
| `empty()` | `O(1)` | Checks whether map is empty. |
| `clear()` | `O(n)` | Removes all key-value pairs. |

---

## `unordered_set`

| Function | Time Complexity | Notes |
|---|---:|---|
| `insert(x)` | `O(1)` average | Inserts unique element. |
| `find(x)` | `O(1)` average | Checks whether element exists. |
| `count(x)` | `O(1)` average | Returns `1` if element exists, else `0`. |
| `erase(x)` | `O(1)` average | Removes element. |
| `size()` | `O(1)` | Returns number of elements. |
| `empty()` | `O(1)` | Checks whether set is empty. |
| `clear()` | `O(n)` | Removes all elements. |

> Note: Worst-case time complexity can become `O(n)` due to hash collisions, but average case is usually `O(1)`.

---

## `set`

| Function | Time Complexity | Notes |
|---|---:|---|
| `insert(x)` | `O(log n)` | Inserts unique element in sorted order. |
| `find(x)` | `O(log n)` | Checks whether element exists. |
| `count(x)` | `O(log n)` | Returns `1` if element exists, else `0`. |
| `erase(x)` | `O(log n)` | Removes element. |
| `lower_bound(x)` | `O(log n)` | First element `>= x`. |
| `upper_bound(x)` | `O(log n)` | First element `> x`. |
| `begin()` | `O(1)` | Iterator to smallest element. |
| `rbegin()` | `O(1)` | Iterator to largest element. |
| `size()` | `O(1)` | Returns number of elements. |
| `empty()` | `O(1)` | Checks whether set is empty. |
| `clear()` | `O(n)` | Removes all elements. |

---

## Quick Selection Rule

| Need | Use |
|---|---|
| Index-based access or dynamic array | `vector` |
| Fast average lookup/frequency count | `unordered_map` |
| Sorted key-value pairs | `map` |
| Fast average duplicate checking | `unordered_set` |
| Sorted unique values | `set` |

---

## Common LeetCode Usage

- Use `vector` for arrays, lists, DP tables, and sorting problems.
- Use `unordered_map` for frequency counting, two sum, grouping, and fast lookup.
- Use `map` when keys must stay sorted.
- Use `unordered_set` for visited checks, duplicate detection, and fast membership tests.
- Use `set` when you need sorted unique elements, smallest/largest value access, or range queries.
