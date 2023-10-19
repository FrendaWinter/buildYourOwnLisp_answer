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

### Question 5: What other conditional operators are there other than greater than >, and less than <?

Ref: https://en.cppreference.com/w/c/language/operator_comparison

### Question 6: What other mathematical operators are there other than add +, and subtract -?

Ref: https://en.cppreference.com/w/c/language/expressions#Operators

### Question 7: What is the += operator, and how does it work?

### Question 8: What is the do loop, and how does it work?

Ref: https://en.cppreference.com/w/c/language/do

### Question 9: What is the switch statement and how does it work?

Ref: https://en.cppreference.com/w/c/language/switch

### Question 10: What is the break keyword and what does it do?

Ref: https://en.cppreference.com/w/c/language/break

### Question 11: What is the continue keyword and what does it do?

Ref: https://en.cppreference.com/w/c/language/continue

### Question 12: What does the typedef keyword do exactly?

Ref: https://en.cppreference.com/w/c/language/typedef