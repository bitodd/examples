#include "stdio.h"


int check_little_big_endian()
{
    union check
    {
        int i;
        char c;
    }c;
    printf("i:%d\n", &c.i);
    printf("c:%d\n", &c.c);
    c.i = 1;
    return (c.c == 1);
}

int main()
{
    int ret;
    ret = check_little_big_endian();
    if(ret == 1)
    {
        printf("little endian\n");  
    }
    else
    {
        printf("big endian\n");
    }
    return 0;
}
