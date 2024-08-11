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
---

### Question 2: Define a recursive Lisp function that returns the nth item of that list.

The idea is counting n to 0 and reduce the list by one element then return head of the list.

`def {nth} (\ {n list} {if (== n 0) {head list} {(nth (- n 1) (tail list))}})`

Base Case: If n is 0, the function returns the first item of the list (head list).

Recursive Case: If n is greater than 0, the function recursively calls itself with n-1 and the rest of the list (tail list).

```
# Testing

lispy> def {nth} (\ {n list} {if (== n 0) {head list} {(nth (- n 1) (tail list))}})
()
lispy> nth 3 {1 432 5 213 234}
{213}
lispy> nth 0 {1 432 5 213 234}
{1}
lispy> nth 7 {1 432 5 213 234}
Error: Function 'tail' passed {} for argument 0.

```

---

### Question 3: Define a recursive Lisp function that returns 1 if an element is a member of a list, otherwise 0.

`def {isMember} (\ {x l} { if (== l {}) {0} { if (== (eval (head l)) x) {1} {isMember x (tail l)} } } )`

The idea for this function is 
- First if check the list is empty then return 0
- The second if checks if the head of the list match the element that we looking for, then return 1
    - Otherwise, it recursively check the rest (tail) of the list

---

### Question 4: Define a Lisp function that returns the last element of a list.

`def {last} (\ {l} {if (== (tail l) {}) {head l} {last (tail l)} } )`

The idea for this function is 
- Check if the tail of the list is empty, it mean that the list have only one left element
    - If true, return head of that list (the only element left)
    - Otherwise, it recursively loop through the rest (tail) of the list

---

### Question 5: Define in Lisp logical operator functions such as or, and and not.

It is the same with Q1, but we define the operator is `and` `or` `not`, instead of `&&` `||` `!`

---

### Question 6: Add a specific boolean type to the language with the builtin variables true and false.
