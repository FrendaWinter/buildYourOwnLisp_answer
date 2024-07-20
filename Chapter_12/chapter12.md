# Functions • Chapter 12

Online read link: https://buildyourownlisp.com/chapter12_functions

### Question 1: Define a Lisp function that returns the first element from a list.

The idea for this function is it take one argument, the argument is Q-expr, and we return the head of that argument

`def {head} (\ {x} {head x})`

So, here is the output

```
lispy> def {first} (\ {x} {head x})
()
lispy> first {13 435 623 0}
{13}   
```

### Question 2: Define a Lisp function that returns the second element from a list.

Same idead with the first question, to get the second element of x, we can get the head of the tail of x

`def {head} (\ {x} {head (tail x)})`

So the output will be

```
lispy> def {second} (\ {x} {head (tail x)})
()
lispy> second {13 4224 5323 43}
{4224}
```

### Question 3: Define a Lisp function that calls a function with two arguments in reverse order.

So, the idea for this question is it take three argument, the first is the function name and the other is the argument for that function

Then we `eval` the function with reverse order of two argument

Here is my test

```
lispy> def {rv} (\ {x y z} {eval {x z y}})
()
lispy> def {sub} (\ {x y} {- x y})
()
lispy> sub 32 4
28
lispy> rv sub 32 4
-28
```

The `eval` take Q-expr of `x z y`, so it `eval` (func_x y z)

Or we can shorten the syntax `def {rv} (\ {x y z} {(x z y)})`

### Question 4: Define a Lisp function that calls a function with arguments, then passes the result to another function.
### Question 5: Define a builtin_fun C function that is equivalent to the Lisp fun function.
### Question 6: Change variable arguments so at least one extra argument must be supplied before it is evaluated.

