# Strings • Chapter 14

Online read link: https://buildyourownlisp.com/chapter14_strings

### Question 1: Adapt the builtin function join to work on strings.

```
lispy> join "Hello" "World"
Error: Function 'join' passed incorrect type for argument 0. Got String, Expected Q-Expression.
```


```c
 switch (x->type) {
    case LVAL_QEXPR:
      for (int i = 0; i < a->count; i++) {
        LASSERT_TYPE("join", a, i + 1, LVAL_QEXPR);
      }    
      break;
    case LVAL_STR:
      for (int i = 0; i < a->count; i++) {
        LASSERT_TYPE("join", a, i + 1, LVAL_STR);
      }
      break;
    default:
      lval* err = lval_err("Function '%s' passed incorrect type for argument %i. Got %s, Expected %s or %s.", "join", 0, 
        ltype_name(x->type), ltype_name(LVAL_QEXPR), ltype_name(LVAL_STR));
      lval_del(a);
      return err;  
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
