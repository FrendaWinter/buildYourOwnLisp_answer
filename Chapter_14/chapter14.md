# Strings • Chapter 14

Online read link: https://buildyourownlisp.com/chapter14_strings

### Question 1: Adapt the builtin function join to work on strings.

First, let check what happen when we call join for strings

```
lispy> join "Hello" "World"
Error: Function 'join' passed incorrect type for argument 0. Got String, Expected Q-Expression.
```

In the builtin_join function, right now, it only accept Q-Expression. We need to change the function to check the first lval*
- If it String, all lval after that should be String
- If it's Q-expression, all lval after that should be Q-Expression
- The rest of function keep the same.

```c
lval* builtin_join(lenv* e, lval* a) {
  // Validate data type of input for join, must be Q-expr or String
  switch (a->cell[0]->type) {
    case LVAL_QEXPR:
      for (int i = 0; i < a->count; i++) {
        LASSERT_TYPE("join", a, i, LVAL_QEXPR);
      }    
      break;
    case LVAL_STR:
      for (int i = 0; i < a->count; i++) {
        LASSERT_TYPE("join", a, i, LVAL_STR);
      }
      break;
    default:
      lval* err = lval_err("Function '%s' passed incorrect type for argument %i. Got %s, Expected %s or %s.", "join", 0, ltype_name(a->cell[0]->type), ltype_name(LVAL_QEXPR), ltype_name(LVAL_STR));
      lval_del(a);
      return err;  
  }

  lval* x = lval_pop(a, 0);
  
  while (a->count) {
    lval* y = lval_pop(a, 0);
    x = lval_join(x, y);
  }
  
  lval_del(a);
  return x;
}
```

In the code, `builtin_join` call `lval_join` for each `lval`

Example:
- If the input is `join {1 2 3 4} {123 13 43} {213 12 43}`
- So lval 1 as x is `{1 2 3 4}`, lval 2 as y `{123 13 43}`, lval 3 as z `{213 12 43}`
- It join x with y, delele y, then join x with z, delete z

That the idea, now we apply for string
- First, we check if the `lval` we got is String, then we call `lval_add` for x and y
- Because `LVAL_STR` not use cell, so don't need to call `lval_add` for each cell

```c

lval* lval_join(lval* x, lval* y) {
  if (y->type == LVAL_STR) {
    x = lval_add(x, y);
    lval_del(y);
  } 
  else {
    for (int i = 0; i < y->count; i++) {  
      x = lval_add(x, y->cell[i]);
    }
    free(y->cell);
    free(y); 
  }
  return x;
}

```

```c
lval* lval_add(lval* v, lval* x) {
  if (v->type == LVAL_STR && x->type == LVAL_STR) {
    v->str = realloc(v->str, sizeof(char) * ( strlen(v->str) + strlen(x->str) + 1));
    strcat(v->str, " ");
    strcat(v->str, x->str);
  } else {
    v->count++;
    v->cell = realloc(v->cell, sizeof(lval*) * v->count);
    v->cell[v->count-1] = x;
  }
  return v;
}
```

---

### Question 2: Adapt the builtin function head to work on strings.

---

### Question 3: Adapt the builtin function tail to work on strings.

---

### Question 4: Create a builtin function read that reads in and converts a string to a Q-expression.

---

### Question 5: Create a builtin function show that can print the contents of strings as it is (unescaped).

---

### Question 6: Create a special value ok to return instead of empty expressions ().

---

### Question 7: Add functions to wrap all of C's file handling functions such as fopen and fgets.
