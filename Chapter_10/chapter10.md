# Q-Expressions • Chapter 10

Online read link: https://buildyourownlisp.com/chapter10_q_expressions

### Question 1: What are the four typical steps for adding new language features?

As reminder, in the lecture. We have 4 steps to add new Rule to the language

| Step           | Description                                                               |
| :------------- | :------------------------------------------------------------------------ |
| Syntax         | Add new rule to the language grammar for this feature.                    |
| Representation | Add new data type variation to represent this feature.                    |
| Parsing        | Add new functions for reading this feature from the abstract syntax tree. |
| Semantics      | Add new functions for evaluating and manipulating this feature.           |

### Question 2: Create a Macro specifically for testing for the incorrect number of arguments.

---

### Question 3: Create a Macro specifically for testing for being called with the empty list.

Let analysis a little bit here

In main function, we have `lval *x = lval_eval(lval_read(r.output));`

-> So it read the output from r.output with `lval_read` function

In the `lval_read` function, it wrapp our input in a big S-expr, if we input `head {12 432 5 6}` then it will be `(head {12 432 5 6})` 

-> Then in `lval_eval` function, it will call eval for that S-expr `lval_eval_sexpr`

```c
// lval_eval function call -> lval_eval_sexpr
lval *lval_eval(lval *v)
{
    if (v->type == LVAL_SEXPR)
    {
        return lval_eval_sexpr(v);
    }
    return v;
}
```

In `lval_eval_sexpr` it will loop throught all our input, that have a condition to check if the lval we eval is only one member or not, that the function we need to add our code to check list empty

```c
// In lval_eval_sexpr function
if (v->count == 1)
{
    // Before it return, let check if v is symbol and it is list or not
    lval *ls = lval_pop(v, 0);
    // If it right, return error empty
    LASSERT(ls, ls->type != LVAL_SYM && strcmp("list", ls->sym) != 0,
            "List retrun empty.");
    return lval_take(v, 0);
}
```

---

### Question 4: Add a builtin function cons that takes a value and a Q-Expression and appends it to the front.

### Question 5: Add a builtin function len that returns the number of elements in a Q-Expression.

Add new symbols to the language

```sh
symbol : \"list\" | \"head\" | \"tail\" | \"eval\" | \"len\" \
    | \"join\" | '+' | '-' | '*' | '/' ;        \
```

Add buildin function for `len`

```c
// Like the builtin_head function, but we only need to return length of the q-expression we evaluated
lval *builtin_len(lval *a)
{
    // Check if the lval a is only have 1 child (the child must be LVAL_QEXPR so we can cout)
    LASSERT(a, a->count == 1,
            "Function 'head' passed too many arguments.");
    LASSERT(a, a->cell[0]->type == LVAL_QEXPR,
            "Function 'head' passed incorrect type.");
    // Return count of first child of a (with is the q-expr we need to count) 
    return lval_num(a->cell[0]->count);
}
```

### Question 6: Add a builtin function init that returns all of a Q-Expression except the final element.


Add new symbols to the language

```sh
symbol : \"list\" | \"head\" | \"tail\" | \"eval\" | \"len\" | \"init\" \
    | \"join\" | '+' | '-' | '*' | '/' ;        \
```

Add buildin function for `init`

```c
// Like the builtin_head function, but we need pop out the last cell and remove it from q-expr
lval *builtin_init(lval *a)
{
    LASSERT(a, a->count == 1,
            "Function 'init' passed too many arguments.");
    LASSERT(a, a->cell[0]->type == LVAL_QEXPR,
            "Function 'init' passed incorrect type.");
    LASSERT(a, a->cell[0]->count != 0,
            "Function 'init' passed {}.");

    lval *v = lval_take(a, 0);
    lval_del(lval_pop(v, v->count - 1));
    return v;
}
```