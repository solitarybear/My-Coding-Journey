# Explaination to code # 13
You have hit a very subtle but critical rule in C++ called **Const Correctness**.

Here is the straightforward engineering answer:

If you have a **Read-Only Object** (like `const Entity& e`), you are **ONLY** allowed to call functions that have promised they are **Read-Only Functions** (`const`).

### **1. The Problem: The "Suspicious" Compiler**

Look at your function `PrintEntity`:

```cpp
void PrintEntity(const Entity& e) // <--- "e" is Read-Only (CONST)
{
    std::cout << e.GetX() << std::endl; // <--- Call GetX()
}

```

**Scenario A: `GetX()` does NOT have `const**`

* **You:** "Compiler, please run `e.GetX()`."
* **The Compiler:** "Whoa, stop. `e` is `const`. I promised the caller I wouldn't touch it. But `GetX()` hasn't promised anything! For all I know, `GetX()` changes `m_X` to 5000. I cannot take that risk. **Error.**"

**Scenario B: `GetX()` HAS `const**`

* **You:** "Compiler, please run `e.GetX()`."
* **The Compiler:** "Okay, let me check `GetX`. Ah, I see the `const` keyword at the end. That is a legally binding contract that this function will not touch `m_X`. Proceed."

---

### **2. The "Secret" Technical Reason (The `this` Pointer)**

Remember how I told you that methods have a secret `this` pointer? The `const` keyword changes that pointer.

**Normal Method:**

```cpp
int GetX() 
// Secretly becomes: 
// int GetX(Entity* this)

```

* The `this` pointer is **writeable**. You can do `this->m_X = 5`.

**Const Method:**

```cpp
int GetX() const 
// Secretly becomes: 
// int GetX(const Entity* this)

```

* The `this` pointer is **Read-Only**.
* If you try to write `m_X = 5` inside `GetX`, the compiler sees `this` is const and throws an error immediately inside the function.

### **3. Why Cherno said "It stops people from using it"**

This is the "Unbiased Push" for your coding habits.

If you write a "Getter" function (like `GetX`, `GetName`, `IsDead`) and you **forget** to mark it `const`, you are breaking code for everyone else.

**Example:**
I write a function that takes a const reference because I want to be efficient:

```cpp
void ProcessRobot(const Robot& r) {
    if (r.IsActive()) { ... } // CRASH! Compile Error!
}

```

If you (the creator of `Robot`) forgot to put `const` on `IsActive()`, I **cannot** use your function in my efficient code. I am forced to remove the `const` from my function (making it unsafe) just to accommodate your "lazy" code.

### **Summary**

1. **`const Entity& e`** = "I promise not to change `e`."
2. **`int GetX()`** (No const) = "I might change `e`."
3. **Result:** The compiler forbids calling #2 on #1.

**Next Step:**
Go to your `main.cpp`.

1. Remove `const` from `GetX()`.
2. Try to compile.
3. Read the error message. It will say something like: *"passing 'const Entity' as 'this' argument discards qualifiers."*
* **Translation:** "You passed a Read-Only object (Const Entity) to a function that wants a Writeable object."

### screenshot of task for error is provided in assests name as 1.png


# 