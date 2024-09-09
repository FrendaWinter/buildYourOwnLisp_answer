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

```c
lval* builtin_head(lenv* e, lval* a) {
  LASSERT_NUM("head", a, 1);

  // Validate data type of input for join, must be Q-expr or String
  switch (a->cell[0]->type) {
    case LVAL_QEXPR:
      LASSERT_TYPE("head", a, 0, LVAL_QEXPR);
      LASSERT_NOT_EMPTY("head", a, 0);
      break;
    case LVAL_STR:
      LASSERT_TYPE("head", a, 0, LVAL_STR);
      LASSERT_NOT_EMPTY_STR("head", a, 0);
      break;
    default:
      lval* err = lval_err("Function '%s' passed incorrect type for argument %i. Got %s, Expected %s or %s.", "head", 0, ltype_name(a->cell[0]->type), ltype_name(LVAL_QEXPR), ltype_name(LVAL_STR));
      lval_del(a);
      return err;  
  }

  lval* v = lval_take(a, 0);
  if (v->type == LVAL_QEXPR) {
    while (v->count > 1) { lval_del(lval_pop(v, 1)); }
  } else {
    char* new_str = malloc(2 * sizeof(char));
    new_str[0] = v->str[0];
    new_str[1] = '\0';
    free(v->str);
    v->str = new_str;
  }
  return v;
}
```

---

### Question 3: Adapt the builtin function tail to work on strings.

```c 
lval* builtin_tail(lenv* e, lval* a) {
  LASSERT_NUM("tail", a, 1);

  // Validate data type of input for join, must be Q-expr or String
  switch (a->cell[0]->type) {
    case LVAL_QEXPR:
      LASSERT_TYPE("tail", a, 0, LVAL_QEXPR);
      LASSERT_NOT_EMPTY("tail", a, 0);
      break;
    case LVAL_STR:
      LASSERT_TYPE("tail", a, 0, LVAL_STR);
      LASSERT_NOT_EMPTY_STR("tail", a, 0);
      break;
    default:
      lval* err = lval_err("Function '%s' passed incorrect type for argument %i. Got %s, Expected %s or %s.", "tail", 0, ltype_name(a->cell[0]->type), ltype_name(LVAL_QEXPR), ltype_name(LVAL_STR));
      lval_del(a);
      return err;  
  }

  lval* v = lval_take(a, 0);  
  if (v->type == LVAL_QEXPR) {
    lval_del(lval_pop(v, 0));
  } else {
    char* new_str = malloc(sizeof(char) * strlen(v->str));
    memcpy(new_str, v->str + sizeof(char), strlen(v->str));
    free(v->str);
    v->str = new_str;
  }
  return v;
}

```

---

### Question 4: Create a builtin function read that reads in and converts a string to a Q-expression.

**Design:**

- Function call is `read`
- We can call read with string or variable, but it should be string. `read "adfhj adsf"` or `read x`
- String will be split by blank space `read "Hello manh"` will output `{"Hello" "manh"}`
    - Multiple blank space next each other will be treat as one blank space

---

### Question 5: Create a builtin function show that can print the contents of strings as they are (unescaped).

---

### Question 6: Create a special value `ok` to return instead of empty expressions `()`.

We create new lval type for this

```c
enum
{
  LVAL_ERR,
  // .... //
  LVAL_QEXPR,
  LVAL_OK // New type
};

lval *lval_ok(void)
{
  lval *v = malloc(sizeof(lval));
  v->type = LVAL_OK;
  v->count = 0;
  v->cell = NULL;
  return v;
};

```

To be able to `eval` new lval type, In `lval_eval_qexpr` function, instead of return empty expressions, we return `lval_ok`

```c
lval* lval_eval_qexpr(lenv* e, lval* v) {
  if (v->count == 0) { return lval_ok(); } // Return `ok` for empty Q-expressions
  // ... rest of the code
}
```

To it can print out properly in the shell, we need to add new case for `lval_ok` in `lval_print` function

```c
void lval_print(lval *v)
{
  switch (v->type)
  {
    // ... //
    case LVAL_OK:
      printf("ok");
      break;
  }
}
```

For handle error when we pass the empty expressions to operator `+` `-` or `*` `/` like this one 

```
lispy> eval ()
Error: Function 'eval' passed incorrect type for argument 0. Got Unknown, Expected Q-Expression.
lispy> eval {()}
ok
lispy> eval {+ 3 ()}
Error: Function '+' passed incorrect type for argument 1. Got Unknown, Expected Number.
```

Instead of return `Unknown type`, it should return something more meaningful

```c
char *ltype_name(int t)
{
  switch (t)
  {
    // ... //
    case LVAL_OK:
      return "Empty expression";
    default:
      return "Unknown";
  }
}
```

---

### Question 7: Add functions to wrap all of C's file handling functions such as fopen and fgets.

To wrap C's file handling functions such as `fopen` and `fgets`, we can create new builtin functions in our Lisp environment. Here's an example implementation:

```c
lval* builtin_fopen(lenv* e, lval* a) {
  LASSERT_NUM("fopen", a, 2);
  LASSERT_TYPE("fopen", a, 0, LVAL_STR);
  LASSERT_TYPE("fopen", a, 1, LVAL_STR);

  char* filename = a->cell[0]->str;
  char* mode = a->cell[1]->str;
  FILE* file = fopen(filename, mode);

  if (file == NULL) {
    return lval_err("Unable to open file '%s' with mode '%s'", filename, mode);
  }

  return lval_file(file);
}

lval* builtin_fgets(lenv* e, lval* a) {
  LASSERT_NUM("fgets", a, 1);
  LASSERT_TYPE("fgets", a, 0, LVAL_FILE);

  FILE* file = a->cell[0]->file;
  char* buffer = malloc(sizeof(char) * 1024);
  if (fgets(buffer, 1024, file) == NULL) {
    free(buffer);
    return lval_err("Error reading from file");
  }

  lval* result = lval_str(buffer);
  free(buffer);
  return result;
}

lval* lval_file(FILE* file) {
  lval* v = malloc(sizeof(lval));
  v->type = LVAL_FILE;
  v->file = file;
  return v;
}
```