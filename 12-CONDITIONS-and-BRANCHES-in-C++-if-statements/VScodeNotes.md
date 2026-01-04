# disassembly view in vs code 

there is some different approch to get disassemply view in <VSCode compared to <VisualStudio

Good question — this is **tooling**, not C++, and VS Code does it **differently from Visual Studio**.
I’ll give you **exact steps** that match what Cherno is *conceptually* doing.

---

## Important first truth (set expectations)

> **VS Code does NOT have a simple “Right-click → Disassembly” like Visual Studio.**

But you **can still see disassembly**, just through the **debugger views**.

---

## Step 1️⃣ Start debugging in VS Code

1. Open your `.cpp` file
2. Set a breakpoint (click left gutter, red dot)
3. Press:

```
F5
```

Or:

```
Run → Start Debugging
```

Make sure you are using **C++ (GDB/LLDB)** debugger.

---

## Step 2️⃣ Open the Disassembly view (THIS is the key)
* this method works 
> Method 1 (recommended, closest to Cherno)

1. While debugger is **paused at breakpoint**
2. Press:

```
Ctrl + Shift + P
```

3. Type:

```
Debug: Open Disassembly View
```

4. Press Enter

👉 This opens the **assembly corresponding to the current instruction**.

This is the **VS Code equivalent** of Cherno’s right-click → Disassembly.

---

## Step 3️⃣ Alternative: Disassembly in Debug Console

You can also manually ask GDB for assembly.

1. When paused at breakpoint
2. Open **Debug Console**
3. Type:

```gdb
disassemble
```

Or:

```gdb
disassemble /m
```

`/m` shows **mixed source + assembly** (VERY useful).

---

## Step 4️⃣ Best learning mode (source + assembly together)

This is the closest to Cherno’s teaching style.

In Debug Console:

```gdb
layout asm
```

or:

```gdb
layout src
```

To switch back:

```gdb
layout split
```

(Works best in terminal-style GDB; VS Code supports parts of this.)

---

## Step 5️⃣ If you want assembly without debugging

You already learned this, but reminder:

```bash
g++ -S -O0 -g -masm=intel main.cpp
```

This gives you `.s` file (static assembly, not runtime).

Cherno uses **runtime disassembly**, you’re now doing the same.

---

## Common reasons it doesn’t work (check this)

If disassembly is empty or weird:

* ❌ compiled without `-g`
* ❌ optimization enabled (`-O2`, `-O3`)
* ❌ breakpoint never hit
* ❌ wrong debugger selected (not GDB)



> In VS Code, Debug → Open Disassembly View is the equivalent of Cherno’s “Right-click → Disassembly”.

