# Variables • Chapter 11

Online read link: https://buildyourownlisp.com/chapter11_variables

### Question 1: Create a Macro to aid specifically with reporting type errors.


```c
#define LASSERT_TYPE(func, args, index, expect)                                          \
    LASSERT(args, args->cell[index]->type == expect,                                     \
            "Function '%s' passed incorrect type for argument %i. Got %s, Expected %s.", \
            func, index, ltype_name(args->cell[index]->type), ltype_name(expect))
```

---

### Question 2: Create a Macro to aid specifically with reporting argument count errors.

```c
#define LASSERT_NUM(func, args, num)                                                    \
    LASSERT(args, args->count == num,                                                   \
            "Function '%s' passed incorrect number of arguments. Got %i, Expected %i.", \
            func, args->count, num)
```

---

### Question 3: Create a Macro to aid specifically with reporting empty list errors.

```c
#define LASSERT_NOT_EMPTY(func, args, index)     \
    LASSERT(args, args->cell[index]->count != 0, \
            "Function '%s' passed {} for argument %i.", func, index);
```

### Question 4: Change printing a builtin function so that it prints its name.


### Question 5: Write a function for printing out all the named values in an environment.

Just like print `lval`, we create two function to print `lenv`

Take a look at the struct lenv first

```c
struct lenv
{
    int count; // Number of member
    char **syms; // List of symbol of member
    lval **vals; // List of value of member
};
```

```c
void lenv_print(lenv *e)
{
    puts("-----------------------------------");
    // Loop throught all value of lenv, print with format `<sym>: <value>``
    for (int i = 0; i < e->count; i++)
    {
        printf("%s: ", e->syms[i]);
        lval_print(e->vals[i]);
        putchar('\n');
    }
    puts("-----------------------------------");
}

void lenv_println(lenv *e)
{
    lenv_print(e);
    putchar('\n');
}
```

**Those two functions need to define after the declaration of lenv or it will return `error: invalid use of incomplete typedef ‘lenv’`**

### Question 6: Redefine one of the builtin variables to something different.
### Question 7: Change redefinition of one of the builtin variables to something different an error.
### Question 8: Create an exit function for stopping the prompt and exiting.
