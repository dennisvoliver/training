#include<stdio.h>

#define assert(x) printf((x) ? "" : "WARNING: The assertion " #x " is false.\n")  
#define tprint(x, t) printf("%" #t, x)


