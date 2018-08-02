#include "stdio.h"
#include "stdlib.h"

static int add(int a, int b) {
    printf("a:%d, b:%d", a, b);
    return a+b;
}

typedef struct {
    int (*add)(int a, int b);
}Stru_t;

#if 1
static Stru_t stru = {
    .add = add,
};
#endif

void test(int a, int b);
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
#if 1
    int sum = stru.add(1,2);
    printf("sum:%d\n", sum);
#endif
    return 0;
}
