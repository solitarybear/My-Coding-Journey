# lamdaas 
Perfect timing — lambdas are **one of the most important modern C++ features**, and Cherno introduces them exactly at the right moment.

I’ll explain this **from zero**, **term by term**, and then connect it to **`mutable`**, since that’s where you’re heading.

---

### The exact line you asked about

```cpp
auto f = []()
{
    std::cout << "Hello" << std::endl;
};
```

We’ll break this into **small pieces**.

---

## 1️⃣ What is a lambda (plain English)

A **lambda** is:

> A **function without a name** that you can store in a variable.

So instead of:

```cpp
void Print()
{
    std::cout << "Hello" << std::endl;
}
```

You write:

```cpp
auto f = []()
{
    std::cout << "Hello" << std::endl;
};
```

And call it with:

```cpp
f();
```

---

## 2️⃣ Why lambdas exist (the WHY)

Lambdas exist because:

* Sometimes you need a **small function**
* Used only **once or locally**
* Writing a full named function is overkill

They are heavily used in:

* callbacks
* algorithms (`std::sort`, `std::find_if`)
* threading
* event systems
* game engines (Cherno context)

---

## 3️⃣ Now break the syntax **character by character**

### 🔹 `auto f =`

```cpp
auto f =
```

This means:

> “Create a variable named `f`, and let the compiler figure out its type.”

The type of a lambda is:

* **anonymous**
* **compiler-generated**
* **ugly and unreadable**

So you **must** use `auto`.

---

### 🔹 `[]` — capture list (VERY IMPORTANT)

```cpp
[]
```

This is called the **capture list**.

It answers the question:

> “Which variables from the surrounding scope can this lambda use?”

In your code:

```cpp
[]
```

Means:

> “Capture NOTHING from outside.”

So this lambda:

* cannot use `x`
* cannot use any local variable
* is completely self-contained

---

### 🔹 `()` — parameters

```cpp
()
```

Same as a normal function:

* empty → no parameters
* you could write `(int a, int b)` etc.

---

### 🔹 `{ ... }` — function body

```cpp
{
    std::cout << "Hello" << std::endl;
}
```

This is the **code that runs when the lambda is called**.

---

## 4️⃣ What is `f` actually?

After compilation:

```cpp
f
```

is **not a function**.

It is an **object** (yes, an object) that:

* has a hidden `operator()`
* can be “called like a function”

So:

```cpp
f();
```

really means:

```cpp
f.operator()();
```

---

## 5️⃣ Calling the lambda

```cpp
f();
```

This simply invokes the lambda’s body.

Output:

```
Hello
```

---

## 6️⃣ Now about `x = 8` (important setup)

```cpp
int x = 8;
```

Right now:

* `x` exists
* But your lambda **cannot access it**

This would be illegal:

```cpp
auto f = []()
{
    std::cout << x;   // ❌ error
};
```

Because you captured nothing.

---

## 7️⃣ Capturing variables (preview)

To use `x`, you must capture it:

#### Capture by value

```cpp
auto f = [x]()
{
    std::cout << x;
};
```

#### Capture by reference

```cpp
auto f = [&x]()
{
    std::cout << x;
};
```

This is where `mutable` comes in.

---

## 8️⃣ What `mutable` does (important connection)

By default:

* **Captured-by-value variables are const inside lambdas**

Example:

```cpp
auto f = [x]()
{
    x++;   // ❌ error
};
```

To allow modification:

```cpp
auto f = [x]() mutable
{
    x++;   // ✅ allowed
};
```

Important:

* This modifies the **lambda’s copy**
* NOT the original `x`

Cherno is about to explain **this exact rule**.

---

## 9️⃣ Mental model (LOCK THIS IN 🔒)

> A lambda is a tiny object that behaves like a function, with optional access to surrounding variables.

---

### One-line takeaway 🔒

> `auto f = [](){}` creates a nameless function-like object (a lambda) and stores it in `f`.

