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

```c
#include <stdio.h>

int main()
{
    char *a = "Frenda";
    printf("Hello, %i\n", a);
    return 0;
}
```

Output mismatch type error
```sh
.\test.c: In function 'main':
.\test.c:6:21: warning: format '%i' expects argument of type 'int', but argument 2 has type 'char *' [-Wformat=]
    6 |     printf("Hello, %i\n", a);
      |                    ~^     ~
      |                     |     |
      |                     int   char *
      |                    %s
```

### Question 7: What does the preprocessor command #ifndef do?

Short for `if not defined` These directives is equivalent to `#if !defined`

If the identifier hasn't been defined, or if its definition has been removed with `#undef`, the condition is true (nonzero). Otherwise, the condition is false (0).

### Question 8: What does the preprocessor command #define do?

Ref: https://en.cppreference.com/w/cpp/preprocessor or https://cplusplus.com/doc/tutorial/preprocessor/

It replaces any occurrence of **identifier** in the rest of the code by **replacement**. This **replacement** can be an expression, a statement, a block or simply anything. The preprocessor does not understand C++ proper, it simply replaces any occurrence of identifier by **replacement**.

Ref: https://www.youtube.com/watch?v=j3mYki1SrKE&t=198s

### Question 9: If _WIN32 is defined on windows, what is defined for Linux or Mac?

`WIN32` `_WIN32` `__WIN32__` `__NT__` Defined as 1 when the compilation target is Windows (32 or 64 bit)

`_WIN64` Defined as 1 when the compilation target is 64-bit ARM or x64. Otherwise, undefined

`__APPLE__` Defined as 1 when the compilation target is MacOSX

`__ANDROID__` Defined as 1 when the compilation target is Android

`__linux__` Defined as 1 when the compilation target is linux

`__unix__` Defined as 1 when the compilation target is unix