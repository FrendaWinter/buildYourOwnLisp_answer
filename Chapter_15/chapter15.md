# Standard Library • Chapter 15

Online read link: https://buildyourownlisp.com/chapter15_standard_library

### Question 1: Rewrite the len function using foldl.

The `len` function calculates the length of a list by using the `foldl` function. Here's a step-by-step explanation:

1. **Define the count function:**

```c
lispy> fun {count a _} {+ a 1}
```

  - This function takes two arguments: `a` and `_`.
  - `a` is an accumulator that keeps track of the count.
  - `_` represents each element in the list (but is not used in the function).
  - The function simply increments the accumulator `a` by 1 for each element in the list.

2. **Define the len function:**

```c
lispy> fun {len l} {foldl count 0 l}
```

  - This function takes one argument: `l`, which is the list whose length we want to calculate.
  - It uses the `foldl` function to apply the `count` function to each element in the list `l`, starting with an initial accumulator value of `0`.
  - `foldl` processes the list from left to right, applying the `count` function to each element and accumulating the result.

3. **Example usage:**

```c
lispy> len {134 541 45 56 24}
5
```

  - When the `len` function is called with the list `{134 541 45 56 24}`, the `foldl` function applies the count function to each element, starting with an initial value of `0`.
  - The result is the length of the list, which is `5`.

In summary, the len function uses `foldl` to traverse the list and count the number of elements by incrementing an accumulator for each element.

---

### Question 2: Rewrite the elem function using foldl.

The elem function checks if a given element exists in a list by using the foldl function. Here's a step-by-step explanation:

1. **Define the compare function:**

```
lispy> fun {compare z index} {if (or z (== x index)){true}{false}}
```

  - This function takes two arguments: `z` and index.
  - `z` is an accumulator that keeps track of whether the element has been found in the list.
  - `index` represents each element in the list.
  - The function checks if either `z` is true (indicating the element has already been found) or if index is equal to `x` (the element we are searching for).
  - If either condition is true, the function returns true; otherwise, it returns false.

2. **Define the elem function:**

```
lispy> fun {elem x l} {foldl compare false l}
```

  - This function takes two arguments: `x` (the element to search for) and `l` (the list to search in).
  - It uses the `foldl` function to apply the compare function to each element in the list `l`, starting with an initial accumulator value of `false`.
  - `foldl` processes the list from left to right, applying the compare function to each element and accumulating the result.

3. **Example usage:**

```
lispy> elem 45 {134 541 45 56 24}
1
```

  - When the elem function is called with the element `45` and the list `{134 541 45 56 24}`, the `foldl` function applies the compare function to each element, starting with an initial value of false.
  - The compare function checks each element in the list to see if it is equal to `45`.
  - When it finds `45`, it returns `true`, indicating that the element exists in the list.

In summary, the elem function uses `foldl` to traverse the list and check if the specified element exists by applying the compare function to each element and accumulating the result. If the element is found, the function returns true; otherwise, it returns false.

---

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

---

### Question 4: Write some documentation for your standard library, explaining what each of the functions do.

---

### Question 5: Write some example programs using your standard library, for users to learn from.

---

### Question 6: Write some test cases for each of the functions in your standard library.