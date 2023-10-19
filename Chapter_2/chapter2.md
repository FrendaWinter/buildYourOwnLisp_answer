# Installation • Chapter 2

### ❓ First question: Change the Hello World! greeting given by your program to something different.
Example and referent document for printing method in C
```c
#include <stdio.h>

int main()
{
    char *name = "Frenda";
    // printf() displays the string inside quotation
    // We can format the output with format specifiers and variable like this
    printf("Hello, %s", name);

    printf("\n"); // Print with endline

    // Another example with integer
    printf("%i: %s\n", 1, "one");

    // Referent document
    printf("Ref for printf function: https://cplusplus.com/reference/cstdio/printf/\n");
    printf("Ref for escape sequence: https://www.geeksforgeeks.org/escape-sequence-in-c/\n");
    return 0;
}
```
We complie with this command
```sh
gcc -std=c99 -Wall .\test.c -o .\test
```
Output
```sh
Hello, Frenda
1: one
Ref for printf function: https://cplusplus.com/reference/cstdio/printf/
Ref for escape sequence: https://www.geeksforgeeks.org/escape-sequence-in-c/
```
<br></br>

### ❔ Question 2: What happens when no main function is given?

Main is the entry point of all c applications, if no main -> it no entry to the code -> Compiler error.

Ref: https://en.cppreference.com/w/c/language/main_function

Output
```sh
undefined reference to `WinMain'
```
<br></br>

### ❓ Question 3: Use the online documentation to lookup the puts function.

Referent document: https://en.cppreference.com/w/c/io/puts

What is puts: pust is like print method, but it add newline at the end of string (It's also doesn't copy the null-terminated \0)

Example code
```c
#include <stdio.h>

int main(void)
{
    int rc = puts("Hello World");

    /*
    Return value
        On success, returns a non-negative value.
        On failure, returns EOF and sets the error indicator (see ferror()) on stream.
    */
    printf("Value of rc: %i\n", rc);

    // Fail return
    // if (rc == EOF)
    //     perror("puts()"); // POSIX requires that errno is set
}
```

<br></br>

### ❔ Question 4: Look up how to use gdb and run it with your program.

The GNU Debugger (GDB) is a portable debugger that runs on many Unix-like systems and works for many programming languages, include C and C++.

Wiki page: https://en.wikipedia.org/wiki/GNU_Debugger

Referent document: https://www.geeksforgeeks.org/gdb-step-by-step-introduction/

Run Gdb with example code in Q3
```sh
gdb .\test.exe
# In the command prompt
(gdb) run
```
```sh
# Examples of commands
$ gdb program 	# Debug "program" (from the shell)
(gdb) run -v 	# Run the loaded program with the parameters
(gdb) bt 	    # Backtrace (in case the program crashed)
(gdb) info registers 	    # Dump all registers
(gdb) disas $pc-32, $pc+32 	# Disassembl
```

Output 
```sh
(gdb) run # Run the program
Starting program: D:\Code\Repo\buildYourOwnLisp_answer\test\test.exe
[New Thread 12864.0x3d6c] # Main thread
Hello World     # Output of the test program
Value of rc: 0  # Output of the test program
[Thread 12864.0x3d6c exited with code 0]
[Inferior 1 (process 12864) exited normally]
(gdb)
(gdb) exit # Exit the GDB
```