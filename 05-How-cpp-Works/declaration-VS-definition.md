You are confused because of a subtle but critical difference in terminology.

**Cherno is right:** The code **compiles**.
**You are right:** The command `g++ log.cpp` **failed**.

Here is why: **`g++ log.cpp` tries to do TWO things: Compile AND Link.**

1.  **Compilation (Success):** The compiler checks your syntax. It sees the declaration `void Log(...)` and says, "Okay, I trust you that this function exists somewhere." **This part passed.**
2.  **Linking (Failure):** After compiling, the Linker looks for the *body* of `Log`. It cannot find it anywhere. So it crashes.

### **The Proof (How to see what Cherno saw)**

Cherno likely pressed "Compile" (Ctrl+F7), which stops before linking.
You can do the same on Linux. Run this command:

```bash
g++ -c log.cpp
```

  * **`-c`**: Means "Compile Only. Do not Link."
  * **Result:** It will run silently and produce a `log.o` file. **No error.**

This proves Cherno is correct: **The code is valid C++.** It just isn't a complete program yet.

-----

### **Understanding Your Error Message**

Look closely at the error you got. It actually tells you exactly what happened:

```text
/usr/bin/ld: ... undefined reference to `Log(char const*)'
collect2: error: ld returned 1 exit status
```

  * **`/usr/bin/ld`**: This is the **L**in**k**er (not the compiler).
  * **`undefined reference`**: This means "I looked for the body definition of `Log`, but it does not exist."

### **The "Unbiased Push"**

You are learning the most important lesson in C++: **Compilation and Linking are separate stages.**

  * **Compiler error:** "You typed the syntax wrong." (e.g., missing semicolon).
  * **Linker error:** "You promised a function exists (declaration), but you never built it (definition)."

**Next Step:**
To make `g++ log.cpp` work (the full build), you must provide the definition. Add the body back into your code or in a separate file, and the Linker `ld` will be happy.