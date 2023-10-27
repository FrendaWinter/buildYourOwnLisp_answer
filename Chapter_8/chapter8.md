# Error Handling • Chapter 8

Online read link: https://buildyourownlisp.com/chapter8_error_handling

### Question 1: Run the previous chapter's code through gdb and crash it. See what happens.

### Question 2: How do you give an enum a name?

Ref document: https://en.cppreference.com/w/cpp/language/enum

Their syntax is:
```sh
enum type_name {
  value1,
  value2,
  ...
} object_names;
```

Example in code, we can name the enumeration of *Possible Error Type* is `errorType`, and for *Possible lval Types* is `lvalType`
```c
/* Create Enumeration of Possible Error Types */
enum errorType
{
    LERR_DIV_ZERO,
    LERR_BAD_OP,
    LERR_BAD_NUM
};

/* Create Enumeration of Possible lval Types */
enum lvalType
{
    LVAL_NUM,
    LVAL_ERR
};

```
### Question 3: What are union data types and how do they work?

A union is a composite data type in C and C++ that allows you to store different data types in the same memory location. Unlike structures (struct), where each member has its memory space, a union allocates memory for only one member at a time. This means that a union's size is determined by its largest member.

### Question 4: What are the advantages over using a union instead of struct?

Memory save, and right purpose

- **Space Efficiency:** A union is more space-efficient than a struct. In a union, all the members share the same memory location, and only the largest member's size is allocated

- Union same right when your want to represent a data structure that have only one value but in different type depending on the use case;

- One of the uses of a union is to be able to access a value either in its entirety or as an array or structure of smaller elements. For example:
```c
union mix_t {
  int l; // It can be a number
  struct { // Or a struct
    short hi;
    short lo;
    } s;
  char c[4]; // or a string
} mix;

```

### Question 5: Can you use a union in the definition of lval?

Yes, we can use a union as Anonymous in `struct`
```c
typedef struct
{
    int type;
    union {
        long num;
        int err;
    }
} lval;
```

### Question 6: Extend parsing and evaluation to support the remainder operator %.


### Question 7: Extend parsing and evaluation to support decimal types using a double field.


## Side Note

## My question 1:

**Why this?**
```c
typedef struct
{
    int type;
    long num;
    int err;
} lval;
```
**Not this?**
```c
struct lval
{
    int type;
    long num;
    int err;
};
```

Because in the `typedef` version, you are declaring an anonymous struct and immediately providing a typedef alias for it. This means that you can create variables of this struct type using the name lval directly, without using the struct keyword

1. `lval myValue;`

2. `struct lval myValue;`

However you can `typedef struct lval lval;` now `struct lval` is alias as `lval`