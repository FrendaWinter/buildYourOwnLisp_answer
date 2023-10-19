# Basics • Chapter 3

### First question: Use a for loop to print out Hello World! five times.

```c
#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Hello, World\n");
    }
    return 0;
}
```

### Question 2: Use a while loop to print out Hello World! five times.

```c
#include <stdio.h>

int main()
{
    int i = 5;
    while (i > 0)
    {
        printf("Hello, World\n");
        i--;
    }
    return 0;
}
```

### Question 3: Declare a function that outputs Hello World! n number of times. Call this from main.

```c
#include <stdio.h>

void pHello(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Hello, World\n");
    }
}
int main()
{
    pHello(5);
    return 0;
}
```

### Question 4: What built in types are there other than the ones listed?

You can look up other data types in https://en.wikipedia.org/wiki/C_data_types

**Some other types:**

Interger -> Have some prefix to determine how large the number is, or it negative or not?
- signed 
- unsigned
- short
- long

**Boolean -> C99 added a boolean (true/false) type `_Bool`.**
    The <stdbool.h> header defines bool as a convenient alias for this type, and also provides macros for true and false

```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // True is 1, false is 0
    bool ret = true;

    printf("%d\n", ret); // prints 1

    // If you want to print true or false, maybe add the condition for that :)
    printf("Your boolean variable is: %s", ret ? "true" : "false");
    return 0;
}
```

### Question 5: What other conditional operators are there other than greater than >, and less than <?

Ref: https://en.cppreference.com/w/c/language/operator_comparison

### Question 6: What other mathematical operators are there other than add +, and subtract -?

Ref: https://en.cppreference.com/w/c/language/expressions#Operators

### Question 7: What is the += operator, and how does it work?

It plus the value in the left operator with itself

`a += 1` is equivalent to `a = a + 1`

### Question 8: What is the do loop, and how does it work?

Ref: https://en.cppreference.com/w/c/language/do

Executes a statement repeatedly until the value of the condition expression becomes false.

Unlike while (check the condition expression first), do loop will execute the block of code first then check the condition expression.

### Question 9: What is the switch statement and how does it work?

Ref: https://en.cppreference.com/w/c/language/switch

Executes code according to the value of an integral argument.

Used where one or several out of many branches of code need to be executed according to an integral value. 

```c
switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```

### Question 10: What is the break keyword and what does it do?

Causes the enclosing for, while or do-while loop or switch statement to terminate.

Used when it is otherwise awkward to terminate the loop using the condition expression and conditional statements. 

Ref: https://en.cppreference.com/w/c/language/break

### Question 11: What is the continue keyword and what does it do?

Causes the remaining portion of the enclosing for, while or do-while loop body to be skipped.

Used when it is otherwise awkward to ignore the remaining portion of the loop using conditional statements. 

Ref: https://en.cppreference.com/w/c/language/continue

### Question 12: What does the typedef keyword do exactly?

Ref: https://en.cppreference.com/w/c/language/typedef

The `typedef` declaration provides a way to declare an identifier as a type alias, to be used to replace a possibly complex type name.

```c
typedef int int_t; // declares int_t to be an alias for the type int
```