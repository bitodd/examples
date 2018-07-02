#include "stdio.h"
#include "stdlib.h"

int func(int a, int b)
{
    printf("\n var a:%d, b:%d\n", a, b);
}

int (*myfun)(int, int);

int main(int argc, char* argv[]){
    myfun = func;
    myfun(10,12);
    return 0;
}
