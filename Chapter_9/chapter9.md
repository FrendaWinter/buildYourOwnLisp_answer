# S-Expressions • Chapter 9

Online read link: https://buildyourownlisp.com/chapter9_s_expressions

### Question 1: Give an example of a variable in our program that lives on The Stack.
### Question 2: Give an example of a variable in our program that points to The Heap.

When using `malloc` -> The value of the pointer will be store in Heap, the poiter is store in Stack

When using `free` the memory for store the value of the pointer will be free and give back to the computer

### Question 3: What does the strcpy function do?

Ref: https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm

The C library function char *strcpy(char *dest, const char *src) copies the string pointed to, by src to dest.

### Question 4: What does the realloc function do?

Ref: https://en.cppreference.com/w/c/memory/realloc

Reallocates the given area of memory. If ptr is not NULL, it must be previously allocated by malloc, calloc or realloc and not yet freed with a call to free or realloc. Otherwise, the results are undefined.

The reallocation is done by either:
a. expanding or contracting the existing area pointed to by ptr, if possible. The contents of the area remain unchanged up to the lesser of the new and old sizes. If the area is expanded, the contents of the new part of the array are undefined.
b. allocating a new memory block of size new_size bytes, copying memory area with size equal the lesser of the new and the old sizes, and freeing the old block.

If there is not enough memory, the old memory block is not freed and null pointer is returned.

If ptr is NULL, the behavior is the same as calling malloc(new_size). 

### Question 5: What does the memmove function do?

Ref: https://learn.microsoft.com/vi-vn/cpp/c-runtime-library/reference/memmove-wmemmove?view=msvc-160

Moves one buffer to another

```c
void *memmove( // Parameters
   void *dest, // Destination object.
   const void *src, // Source object.
   size_t count // Number of bytes (memmove) or characters (wmemmove) to copy.
); // Return value - The value of dest.

wchar_t *wmemmove(
   wchar_t *dest,
   const wchar_t *src,
   size_t count
);
```


### Question 6: How does memmove differ from memcpy?

Overlapping Memory:
    memcpy does not handle overlapping memory regions correctly. If the source and destination memory areas overlap, using memcpy can lead to undefined behavior. In such cases, the results are unpredictable, and it can corrupt data.
    memmove, on the other hand, is designed to handle overlapping memory regions. It ensures that the data is correctly copied, even if the source and destination memory areas overlap. memmove does this by temporarily copying data to a separate buffer before copying it to the destination.

Performance:
    Due to the additional checks and temporary buffer in the case of overlapping regions, memmove may be slightly slower than memcpy when there is no overlap. If you are sure that there is no overlap, memcpy is often more efficient.
    In situations where you know there is no overlap, using memcpy is typically more performant because it doesn't incur the additional overhead of checking for overlap.

### Question 7: Extend parsing and evaluation to support the remainder operator %.

### Question 8: Extend parsing and evaluation to support decimal types using a double field.




