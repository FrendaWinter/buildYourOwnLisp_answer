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
### Question 6: Redefine one of the builtin variables to something different.
### Question 7: Change redefinition of one of the builtin variables to something different an error.
### Question 8: Create an exit function for stopping the prompt and exiting.

