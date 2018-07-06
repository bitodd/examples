#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string"

using std::cout;
using std::endl;

int main()
{
    unsigned int uNum = 4294967295;
    cout<<"nun:"<<uNum<<endl;
    printf("\n uNum:%d\n", uNum);
    printf("\n uNum,ld:%ld\n", uNum);
    printf("\n uNum,u:%u\n", uNum);
    unsigned int nNum2 = 0xfffe;

    printf("\n uNum2:%d\n", uNum);
    return 0;
}
