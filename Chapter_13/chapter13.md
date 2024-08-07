# Conditionals • Chapter 13

Online read link: https://buildyourownlisp.com/chapter13_conditionals

### Question 1: Create builtin logical operators or ||, and && and not ! and add them to the language.

First, the character `|` is not accepted in our language yet, so we need to add that character to symbol list

`symbol : /[a-zA-Z0-9_+\\-*\\/\\\\=<>!&\\|]+/ ;`

Then, we add those logical operator like another builtin operator


```
  lenv_add_builtin(e, "||", builtin_or);
  lenv_add_builtin(e, "&&", builtin_and);
  lenv_add_builtin(e, "!", builtin_not);
```

For builtin_or and builtin_and, we can follow another operators

```
lval* builtin_and(lenv* e, lval* a) {
  return builtin_ord(e, a, "&&");
}

lval* builtin_or(lenv* e, lval* a) {
  return builtin_ord(e, a, "||");
}
```

In `builtin_ord`, we implement the `and` and `or` logical

```
  if (strcmp(op, "||")  == 0) {
    r = (a->cell[0]->num || a->cell[1]->num);
  }
  if (strcmp(op, "&&") == 0) {
    r = (a->cell[0]->num && a->cell[1]->num);
  }
```

For the not operator, it only need one argument, so I rewrite the `builtin_ord` function, but take only one argument

```
lval* builtin_not(lenv* e, lval* a) {
  char* op = "!";

  LASSERT_NUM(op, a, 1);
  LASSERT_TYPE(op, a, 0, LVAL_NUM);
  
  int r;
  if (strcmp(op, "!") == 0) {
    r = (!a->cell[0]->num);
  }
  // -------------------------- //
  lval_del(a);
  return lval_num(r);
}

```

### Question 2: Define a recursive Lisp function that returns the nth item of that list.
### Question 3: Define a recursive Lisp function that returns 1 if an element is a member of a list, otherwise 0.
### Question 4: Define a Lisp function that returns the last element of a list.
### Question 5: Define in Lisp logical operator functions such as or, and and not.
### Question 6: Add a specific boolean type to the language with the builtin variables true and false.
