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

Or we can shorten the syntax `def {rv} (\ {x y z} {x z y})`

### Question 4: Define a Lisp function that calls a function with arguments, then passes the result to another function.

Here's a idea of the function:

- `compose` is the name of the function.
- It takes three parameters:
    - `x` as func1: The first function to be called.
    - `y` as func2: The second function to be called with the result of func1.
    - And other args, A list of arguments to be passed to func1.
        - If func 1 take 2 arguments, it will be 4 arguments
- In the case func 1 `x` take one arguments, we have `x y z` as parameters
    - We calls func1 `x` with the arguments args: `(x z)`, this will equal to `eval {x z}`, eval func x with z as argument. 
- Then we calls func2 `y` with the result of `(x z)`.
    - `{y (x z)}`, this will equal to `eval {y (x z)}`, eval func `y` with the result of `(x z)`

Here is a example: 

```
lispy> def {compose} (\ {x y z t} {y (x z t)})
()
lispy> def {add} (\ {x y} {+ x y})
()
lispy> def {square} (\ {x} {* x x})
()
lispy> compose add square 32 32
4096
```

### Question 5: Define a builtin_fun C function that is equivalent to the Lisp fun function.
### Question 6: Change variable arguments so at least one extra argument must be supplied before it is evaluated.

