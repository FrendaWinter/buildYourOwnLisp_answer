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

---

### Question 4: Change printing a builtin function so that it prints its name.

To able to print builtin function name, you first need to add a symbol of that function into it's `lval`

In the declaration of `lval_fun` we add one more parameter to insert their symbol

```c
lval *lval_fun(lbuiltin func, char *name)
{
    lval *v = malloc(sizeof(lval));
    v->type = LVAL_FUN;
    v->sym = name; // Add their symbol to sym variable
    v->fun = func;
    return v;
}
```

Then we change all referent to `lval_fun` as well

```c
void lenv_add_builtin(lenv *e, char *name, lbuiltin func)
{
    lval *k = lval_sym(name);
    lval *v = lval_fun(func, k->sym); // We ssignment symbol to k->sym
    lenv_put(e, k, v);
    lval_del(k);
    lval_del(v);
}
```

Next in the code, we need to print it out!

```c
void lval_print(lval *v)
{
    switch (v->type)
    {
    case LVAL_FUN:
        printf("Function: %s", v->sym);
        // printf("<function>");
        // lval_print(v->cell[0]);
        break;
        /*Rest of the code*/
    }
}   
```

It not done yet, if you read the code carefully, in `main` before we print out of result, we `eval` it, and in the `lval_eval` function, we `lenv_get` the `lval`, it check in `lenv` **e**, if it match the builtin function it will `lval_copy` it. And in this `lval_copy` function, we need to proper copy the builtin function 

```c
case LVAL_FUN:
    x->fun = v->fun;
    // Add code for copy the sym of builtin function
    x->sym = malloc(strlen(v->sym) + 1);
    strcpy(x->sym, v->sym);
    break;
```

Now, when we call builtin function alone, it returns it's symbol

```sh
lispy> eval
Function: eval
```

---

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

So the function to print all variable in lenv is

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

---

### Question 6: Redefine one of the builtin variables to something different.

In this question, I will change the builtin variable `tail` to something different

`tail` will return the last token of Q-expr, not all token after the first

So, take a look at the original function

```c 
lval* builtin_tail(lenv* e, lval* a) {
    
    // Validation part
    LASSERT_NUM("tail", a, 1);
    LASSERT_TYPE("tail", a, 0, LVAL_QEXPR);
    LASSERT_NOT_EMPTY("tail", a, 0);

    lval* v = lval_take(a, 0); // Copy lval a to lval v  
    lval_del(lval_pop(v, 0)); // Delete the first token of lval v
    return v; // Return v
}
```

So to only take the last token, not the whole tail, we need to delete all the token before the last one.

To do that, we get the length of v first, then we delete all until remain the last one.

```c 
lval* builtin_tail(lenv* e, lval* a) {
    
    // Validation part
    LASSERT_NUM("tail", a, 1);
    LASSERT_TYPE("tail", a, 0, LVAL_QEXPR);
    LASSERT_NOT_EMPTY("tail", a, 0);

    lval* v = lval_take(a, 0); // Copy lval a to lval v  
    
    int count = v->count;
    for (int i = 0;i < count - 1; i++) { // loop from 0 to the index before the last element
        lval_del(lval_pop(v, 0)); // Delete all token before the last one
    }
    return v; // Return v
}
```

So we got the function, let run it and print more detail

```
lispy> tail {1 2 3 4}
----------------
{1 2 3 4}
----------------
{2 3 4}
----------------
{3 4}
----------------
{4}
----------------
{4}
```

It will delete each token until the last one as we expect


### Question 7: Change redefinition of one of the builtin variables to something different an error.



---

### Question 8: Create an exit function for stopping the prompt and exiting.

First, we define the builtin function for `exit`

`lenv_add_builtin(e, "exit", builtin_exit);`

```c
lval *builtin_exit(lenv *e, lval *a)
{
    lval_del(a);
    printf("Call exit\n");
    exit(1);
}
```

Now, complie the code and test it

-> Here the thing, when we call `exit` alone, it still not exit the `lisp`, because in the code, when we `eval` a `lval`, we check if it have zero or one cell, if it true, we simply return it, not continue eval

-> So we need to call exit with minimal one argument, like `exit 1` or `exit 0`

-> To enforce the user will input `0` or `1` for `exit`, we need to add some validation for the `lval_exit` function

```c
lval *builtin_exit(lenv *e, lval *a)
{
    LASSERT_TYPE("exit", a, 0, LVAL_NUM);

    LASSERT(a, (a->cell[0]->num == 1 || a->cell[0]->num == 0),
            "Function 'exit' passed invalid arguments. Got % i, Expected 1 or 0.", a->cell[0]->num);

    lval_del(a);
    // printf("Call exit\n");
    exit(1);
}
```

-> Now, it will enforce the user to input `0` or `1` for `exit`
