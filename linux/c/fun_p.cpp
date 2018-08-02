#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#include "fun_p.h"
#endif
using namespace std;

static int add(int a, int b) {
    return a+b;
}

#if 1
static Stru_t stru = {
    .add = add,
};
#endif

#ifdef __cplusplus
}
#endif

int main(int argc, char* argv[]) {
    int sum = stru.add(1,2);
    cout<<"sum:"<<sum<<endl;
    return 0;
}
