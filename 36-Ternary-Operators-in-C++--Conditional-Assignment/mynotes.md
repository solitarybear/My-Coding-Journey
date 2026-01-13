# what does it mean by Nested code and Non Nested code
"Nested code" means placing one control structure (like an  statement, loop, or function) inside another similar structure, creating layers where the inner code only runs if the outer condition is met, while "non-nested" code has elements at the same level, often using compound conditions (like  or ) or separate  statements for independent checks. Nesting allows for complex, dependent decisions, but too much can make code hard to read; non-nested approaches can be cleaner for independent conditions. [1, 2, 3, 4, 5, 6]  



* Nested Code 

• Definition: An  statement (or loop, function) placed inside another  statement (or loop, function). 
• How it Works: The inner code only executes if the outer code's condition is true. 
• Example: 


>python
if age >= 18:  # Outer condition
    if is_citizen: # Inner condition (only checked if age >= 18)
        print("Eligible to vote.")



• When to Use: When conditions are dependent on each other (e.g., checking citizenship only if the person is old enough). [2, 4, 7, 8]  


---------------------------------------------------------------


* Non-Nested Code (or Flattened) 

• Definition:  statements or conditions are at the same level, or combined into one. 
• How it Works: Checks conditions independently or as a single compound check. 


• Example (Combined Condition): 
>python
if age >= 18 and is_citizen: # Single, compound condition
    print("Eligible to vote.")




• Example (Separate): 
>python
if age >= 18:
    print("Is an adult.")
if is_citizen:
    print("Is a citizen.") # These can run independently




• When to Use: For conditions that aren't strictly dependent, or to avoid deep, hard-to-read nesting. [1, 3, 4, 6, 9]  

Key Difference 

• Nesting: Sequential, layered checks (Outer -&gt; Inner). 

• Non-Nesting: Parallel or combined checks (Condition A and Condition B). [6]  

Choosing between them depends on the logic: nested for dependent steps, non-nested (combined or separate) for independent checks or to improve readability. [3, 6]  



# ask ai by sending a a code having ternary operato with more than 1 question mark and ask explain me this code  