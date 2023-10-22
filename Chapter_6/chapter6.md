# Parsing • Chapter 6

Regex referent:

To test: https://regex101.com/

Quick learn: https://www.youtube.com/watch?v=rhzKDrUiJVk

### Question 1: Write a regular expression matching strings of all a or b such as aababa or bbaa.

`[a|b]+`  

Explain:

`[a|b]` ~ Matches a single character in the list a|b (case sensitive)

`+` ~ Matches the previous token between one and unlimited times

### Question 2: Write a regular expression matching strings of consecutive a and b such as ababab or aba.

`\b(((ab)+a?)|((ba)+b?))\b`

`\b` ~ Word boundary

Ref: https://stackoverflow.com/questions/22895015/what-regex-matches-strings-of-consecutive-a-and-b

### Question 3: Write a regular expression matching pit, pot and respite but not peat, spit, or part.

`(\bpit\b|\bpot\b|\brespite\b)`

`\b` ~ Word boundary

Wrap the word between `\b` for matches the characters `pit` literally

The use group and `|` to choose between 3 alternative option

### Question 4: Change the grammar to add a new operator such as %.

```c
/* Add new operator `%` to the operator */
mpca_lang(MPCA_LANG_DEFAULT,
            "                                           \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' | '%' ;            \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
",
            Number, Operator, Expr, Lispy);
```

### Question 5: Change the grammar to recognise operators written in textual format add, sub, mul, div.

```c
/* Change symbol operator to word operator */
mpca_lang(MPCA_LANG_DEFAULT,
            "                                           \
    number   : /-?[0-9]+/ ;                             \
    operator : 'add' | 'sub' | 'mul' | 'div' | 'rem' ;  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
",
            Number, Operator, Expr, Lispy);
```

### Question 6: Change the grammar to recognize decimal numbers such as 0.01, 5.21, or 10.2.

```c
/* Change the regex of number to it recognize decimal numbers */
mpca_lang(MPCA_LANG_DEFAULT,
            "                                \
    number : /-?[0-9]+(\\.[0-9]*)?/ ;        \
    operator : '+' | '-' | '*' | '/' ;            \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
",
            Number, Operator, Expr, Lispy);
```

### Question 7: Change the grammar to make the operators written conventionally, between two expressions.

```c
/* Change the regex of lispy to make the operators written conventionally */
mpca_lang(MPCA_LANG_DEFAULT,
            "                                           \
    number : /-?[0-9]+(\\.[0-9]*)?/ ;                   \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <expr> <operator> <expr> /$/ ;       \
",
            Number, Operator, Expr, Lispy);
```

### Question 8: Use the grammar from the previous chapter to parse Doge. You must add start and end of input.


