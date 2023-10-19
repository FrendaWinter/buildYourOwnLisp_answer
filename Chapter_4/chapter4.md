# An Interactive Prompt • Chapter 4

### First question : Change the prompt from lispy Question : to something of your choice.
### Question 2: Change what is echoed back to the user.
### Question 3: Add an extra message to the Version and Exit Information.
### Question 4: What does the \n mean in those strings?

It is escape sequence for endline
Ref: https://www.geeksforgeeks.org/escape-sequence-in-c/"

### Question 5: What other patterns can be used with printf?

### Question 6: What happens when you pass printf a variable that does not match the pattern?

### Question 7: What does the preprocessor command #ifndef do?

### Question 8: What does the preprocessor command #define do?

Ref: https://en.cppreference.com/w/cpp/preprocessor

### Question 9: If _WIN32 is defined on windows, what is defined for Linux or Mac?

`WIN32` `_WIN32` `__WIN32__` `__NT__` Defined as 1 when the compilation target is Windows (32 or 64 bit)

`_WIN64` Defined as 1 when the compilation target is 64-bit ARM or x64. Otherwise, undefined

`__APPLE__` Defined as 1 when the compilation target is MacOSX

`__ANDROID__` Defined as 1 when the compilation target is Android

`__linux__` Defined as 1 when the compilation target is linux

`__unix__` Defined as 1 when the compilation target is unix