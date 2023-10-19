# An Interactive Prompt • Chapter 4

### First question : Change the prompt from lispy> to something of your choice.

Just change `char* input = readline("lispy> ");` to whatever you like `char* input = readline("frenda> ");`

### Question 2: Change what is echoed back to the user.

Just change `printf("No you're a %s\n", input);` to something of your choice `printf("My input is %s\n", input);`

### Question 3: Add an extra message to the Version and Exit Information.

Add this two lines to the main function
```c
puts("Lispy Version 0.0.0.0.1");
puts("Press Ctrl+c to Exit\n");
```

### Question 4: What does the \n mean in those strings?

It is escape sequence for endline

Ref: https://www.geeksforgeeks.org/escape-sequence-in-c/"

### Question 5: What other patterns can be used with printf?

Fun ref: https://www.geeksforgeeks.org/pattern-programs-in-c/

### Question 6: What happens when you pass printf a variable that does not match the pattern?

### Question 7: What does the preprocessor command #ifndef do?

Short for `if not defined`

### Question 8: What does the preprocessor command #define do?

Ref: https://en.cppreference.com/w/cpp/preprocessor

### Question 9: If _WIN32 is defined on windows, what is defined for Linux or Mac?

`WIN32` `_WIN32` `__WIN32__` `__NT__` Defined as 1 when the compilation target is Windows (32 or 64 bit)

`_WIN64` Defined as 1 when the compilation target is 64-bit ARM or x64. Otherwise, undefined

`__APPLE__` Defined as 1 when the compilation target is MacOSX

`__ANDROID__` Defined as 1 when the compilation target is Android

`__linux__` Defined as 1 when the compilation target is linux

`__unix__` Defined as 1 when the compilation target is unix