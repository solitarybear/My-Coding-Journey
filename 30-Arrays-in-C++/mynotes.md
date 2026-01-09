# standard array from C++ 11
* standard array from C++ 11

Good — this is a **clean, focused question**.
Let’s explain **only this expression**, exactly what you asked:

```cpp
another.size()
```

---

## 1️⃣ What is `another`?

From your class:

```cpp
std::array<int, 5> another;
```

This means:

* `another` is an object of type `std::array<int, 5>`
* It stores **5 integers**
* It behaves like a fixed-size array, but as a **class**

So:

> `another` is **not** a raw C-style array — it’s a C++ container.

---

## 2️⃣ What is `std::array`?

`std::array` is a **template class** provided by the C++ standard library.

```cpp
std::array<T, N>
```

* `T` → element type
* `N` → number of elements (**known at compile time**)

So:

```cpp
std::array<int, 5>
```

means:

> An array of 5 integers, stored contiguously.

---

## 3️⃣ What does `.size()` mean?

```cpp
another.size()
```

* `size()` is a **member function** of `std::array`
* It returns:

  > the **number of elements** in the array

In your case:

```cpp
another.size() == 5
```

---

## 4️⃣ What is the return type of `size()`?

`another.size()` returns:

```cpp
std::size_t
```

Which is:

* An **unsigned integer type**
* Used for sizes and counts

So internally:

```cpp
std::size_t = unsigned long (usually)
```

---

## 5️⃣ How does `size()` know the value?

Important point:

> `std::array` stores its size as a **compile-time constant**, not at runtime.

So:

* No memory lookup
* No stored variable
* The compiler already knows the value

`size()` is essentially:

```cpp
constexpr std::size_t size() const { return 5; }
```

---

## 6️⃣ Why you can call `.size()` but not on raw arrays

### Raw array:

```cpp
int example[5];
```

❌ This does NOT work:

```cpp
example.size(); // ❌ not a class
```

Because:

* Raw arrays have no methods
* They decay to pointers in many cases

---

### `std::array`:

```cpp
std::array<int, 5> another;
```

✅ This works:

```cpp
another.size();
```

Because:

* `std::array` is a class
* It has member functions

---

## 7️⃣ Why using `.size()` is safer

If you change:

```cpp
std::array<int, 10> another;
```

Then:

```cpp
another.size()  // automatically becomes 10
```

No magic numbers.
No mismatch.
Less bugs.

---

## 8️⃣ Why Cherno prefers `std::array`

Because:

* Fixed size (like raw arrays)
* Safer
* Has `.size()`
* Works with STL algorithms
* No pointer decay

---

## 🔒 Mental model (lock this in)

> `another.size()` asks the array object: “How many elements do you contain?”

The answer is known at compile time.

---

## One-line takeaway 🔒

> `another.size()` returns the number of elements in the `std::array`, which is known at compile time and equals `5` here.

