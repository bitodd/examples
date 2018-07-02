#include "stdio.h"
#include "stdlib.h"

int func(int a, int b)
{
    printf("\n var a:%d, b:%d\n", a, b);
}
//define a function pointer
int (*myfun)(int, int);
//defind a type of function pointer
typedef int (*MYFUNC)(int, int);

int main(int argc, char* argv[]){
    myfun = func;
    myfun(10,12);

    MYFUNC myfun2;
    myfun2 = func;
    myfun2(13,14);
    return 0;
}
