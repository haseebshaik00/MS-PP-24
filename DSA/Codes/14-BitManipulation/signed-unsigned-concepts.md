# 🧠 Summary: Signed vs Unsigned Integers, Two’s Complement, and Fixed-Width Types in C++/Java

## 🔹 1. Signed vs Unsigned Integers

| Type       | Can Store             | Value Range (`n`-bit)           |
|------------|------------------------|----------------------------------|
| `signed`   | Negative and positive  | −2ⁿ⁻¹ to 2ⁿ⁻¹ − 1               |
| `unsigned` | Only non-negative      | 0 to 2ⁿ − 1                      |

- `int`, `short`, and `char` are `signed` by default unless explicitly marked `unsigned`.
- Signed integers use **two's complement** representation.

## 🔹 2. Common Integer Data Types (64-bit system, LP64 model)

| Type         | Bits | Signed Range                    | Unsigned Range             |
|--------------|------|----------------------------------|----------------------------|
| `char`       | 8    | −2⁷ to 2⁷−1 = −128 to 127        | 0 to 2⁸−1 = 255            |
| `short`      | 16   | −2¹⁵ to 2¹⁵−1 = −32,768 to 32,767| 0 to 65,535                |
| `int`        | 32   | −2³¹ to 2³¹−1 = −2.1B to 2.1B    | 0 to 4.29B                 |
| `long`       | 64   | −2⁶³ to 2⁶³−1                    | 0 to 2⁶⁴−1                 |
| `long long`  | 64   | Same as `long`                  | Same                       |

> 💡 On Windows (LLP64), `long` is still 32 bits.

## 🔹 3. Fixed-Width Integer Types (`<cstdint>`)

| Type       | Bits | Signed Range                    | Unsigned Range             |
|------------|------|----------------------------------|----------------------------|
| `int8_t`   | 8    | −128 to 127                     | —                          |
| `uint8_t`  | 8    | —                               | 0 to 255                   |
| `int32_t`  | 32   | −2,147,483,648 to 2,147,483,647 | —                          |
| `uint32_t` | 32   | —                               | 0 to 4,294,967,295         |
| `int64_t`  | 64   | −2⁶³ to 2⁶³−1                   | —                          |
| `uint64_t` | 64   | —                               | 0 to 2⁶⁴−1                 |

## 🔹 4. Two’s Complement Representation

Used by all signed integers (`int`, `int32_t`, etc.) in C++ and Java.

- To represent `−x`:
  ```
  value = 2ⁿ − x
  ```

- Examples:
  - `-1` (32-bit) = `2³² − 1` = `0xFFFFFFFF`
  - `-2` (32-bit) = `2³² − 2` = `0xFFFFFFFE`

- Range of signed 32-bit int:
  ```
  −2³¹ to 2³¹ − 1 → −2,147,483,648 to 2,147,483,647
  ```

## 🔹 5. Why Max Signed Value = 2ⁿ⁻¹ − 1?

Because:
- One bit is used for the sign.
- You must reserve one pattern for the minimum value (`−2ⁿ⁻¹`)
- So the highest positive value becomes:
  ```
  Max = 2ⁿ⁻¹ − 1
  ```

## 🔹 6. What Happens if You Store a Negative in `uint32_t`?

```cpp
uint32_t x = -1;
```

- `-1` becomes:
  ```
  2³² − 1 = 4,294,967,295
  ```

Unsigned integers wrap around using modulo arithmetic:
```
x = x mod 2ⁿ
```

## 🔹 7. Binary Interpretation Example

### Input:
```
11111111 11111111 11111111 11111111  (32 bits)
```

| As Type      | Interpreted As         |
|--------------|------------------------|
| `uint32_t`   | 4,294,967,295          |
| `int32_t`    | −1                     |

## 🔹 8. Float Representation (IEEE 754)

| Type     | Bits | Approx Range             | Precision       |
|----------|------|--------------------------|-----------------|
| `float`  | 32   | ~2⁻¹²⁶ to 2¹²⁸            | ~7 digits       |
| `double` | 64   | ~2⁻¹⁰²² to 2¹⁰²³          | ~15-16 digits   |
