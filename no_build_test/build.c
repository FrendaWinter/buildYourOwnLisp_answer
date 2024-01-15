#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define CFLAGS "-Wall", "-lm", "-std=c99", "-ledit"

int main(int argc, char **argv)
{
    GO_REBUILD_URSELF(argc, argv);

    INFO("Build Lisp interpreter");
    CMD("gcc", CFLAGS, "lisp.c", "mpc.c", "-o", "lisp");

    INFO("Running Lisp interpreter");
    CMD("lisp.exe");
    return 0;
}
