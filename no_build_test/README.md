## Main idea

The idea for this is we only use gcc to build our lisp interpreter.
And we only to run build.exe to build the lisp interpreter, no need to run gcc all the time.

```bash
# Build our build process
gcc -std=c99 build.c -o build
# Run build.exe -> It will automatically build the lisp interpreter and run it
build.exe
```

