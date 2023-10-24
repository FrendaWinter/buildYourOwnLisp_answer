# Evaluation • Chapter 7

Online read link: https://buildyourownlisp.com/chapter7_evaluation

### Question 1: Write a recursive function to compute the number of leaves of a tree.

In the lecture, we have the function to find the number of nodes, it is a recursive function that loop all over the tree then foreach nodes it `+ 1`

```c
int number_of_nodes(mpc_ast_t *t)
{
    if (t->children_num == 0)
    {
        return 1;
    }
    if (t->children_num >= 1)
    {
        int total = 1;
        for (int i = 0; i < t->children_num; i++)
        {
            total = total + number_of_nodes(t->children[i]);
        }
        return total;
    }
    return 0;
}
```

In our `number_of_leafs` function, we only want to count the number of leaf, so we set the total = 0, that make the counter count 0 if the nodes isn't leaf

```c
int number_of_leafs(mpc_ast_t *t)
{
    if (t->children_num == 0)
    {
        return 1;
    }
    if (t->children_num >= 1)
    {
        int total = 0; // We set total = 0 here
        for (int i = 0; i < t->children_num; i++)
        {
            total = total + number_of_leafs(t->children[i]);
        }
        return total;
    }
    return 0;
}
```


### Question 2: Write a recursive function to compute the number of branches of a tree.




### Question 3: Write a recursive function to compute the most number of children spanning from one branch of a tree.


### Question 4: How would you use strstr to see if a node was tagged as an expr?


### Question 5: How would you use strcmp to see if a node had the contents '(' or ')'?


## Before Q-6-7-8-9-10

As reminder, in the lecture. We have 4 steps to add new Rule to the language

| Step           | Description                                                               |
| :------------- | :------------------------------------------------------------------------ |
| Syntax         | Add new rule to the language grammar for this feature.                    |
| Representation | Add new data type variation to represent this feature.                    |
| Parsing        | Add new functions for reading this feature from the abstract syntax tree. |
| Semantics      | Add new functions for evaluating and manipulating this feature.           |

We will follow above steps to adding new Rule to own language

### Question 6: Add the operator %, which returns the remainder of division. For example % 10 6 is 4

**S1**: `Syntax`

```c
operator : '+' | '-' | '*' | '/' | '%' ; 
```

**S2**: `Representation` -> No need to add new type because we still using integer for now

**S3**: `Parsing` + **S4**: `Semantics` 

We add both `Parsing` and `Semantics` in the `eval_op` function

```c
/* Use operator string to see which operation to perform */
long eval_op(long x, char *op, long y)
{
    if (strcmp(op, "+") == 0) ...
    if (strcmp(op, "-") == 0) ...
    if (strcmp(op, "*") == 0) ...
    if (strcmp(op, "/") == 0) ...
    if (strcmp(op, "%") == 0) {
        return x % y;
    }
    return 0;
}
```

### Question 7: Add the operator ^, which raises one number to another. For example ^ 4 2 is 16.

Like the Q6, we have

**S1**: `Syntax`

```c
operator : '+' | '-' | '*' | '/' | '%' | '^' ; 
```

With `Semantics`, we have 2 way

1. Using for loop

```c
if (strcmp(op, "^") == 0) {
    long result = 1;
    for(long i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}
```
2. Using recursive

```c
if (strcmp(op, "^") == 0) {
    return multiples(x, y);
}

// Multiples function
long multiples(const long x, const long y)
{
    if (y == 0)
        return 1;
    return x * multiples(x, y - 1);
}
```

### Question 8: Add the function min, which returns the smallest number. For example min 1 5 3 is 1.

**S1**: `Syntax`

```c
operator : '+' | '-' | '*' | '/' | '%' | '^' | 'min' ; 
```

With `Semantics`, we will loop through all member of `expr` to find the `min`

### Question 9: Add the function max, which returns the biggest number. For example max 1 5 3 is 5.

**S1**: `Syntax`

```c
operator : '+' | '-' | '*' | '/' | '%' | '^' | 'min' | 'max'; 
```

Same with `min`, we will loop through all member of `expr` to find the `max`

### Question 10: Change the minus operator - so that when it receives one argument it negates it.







