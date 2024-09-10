# Standard Library • Chapter 15

Online read link: https://buildyourownlisp.com/chapter15_standard_library

### Question 1: Rewrite the len function using foldl.

```c
lispy> fun {count a _} {+ a 1}
()
lispy> fun {len l} {foldl count 0 l}
()
lispy> len {134 541 45 56 24}
5
lispy>
```

---

### Question 2: Rewrite the elem function using foldl.

```c
```

### Question 3: Incorporate your standard library directly into the language. Make it load at start-up.

To load the lib at start up, we load the file right after declare the global environment

```c
  lenv *e = lenv_new();
  lenv_add_builtins(e);
  
  // Load prelude lib before run
  lval *stdlib = lval_add(lval_sexpr(), lval_str("./prelude.lspy"));
  lval *tmp = builtin_load(e, stdlib);

  /* If the result is an error be sure to print it */
  if (tmp->type == LVAL_ERR)
  {
    lval_println(tmp);
  }
  lval_del(tmp);
```
### Question 4: Write some documentation for your standard library, explaining what each of the functions do.
### Question 5: Write some example programs using your standard library, for users to learn from.
### Question 6: Write some test cases for each of the functions in your standard library.