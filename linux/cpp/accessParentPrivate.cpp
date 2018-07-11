#include "string.h"
#include "iostream"

using namespace std;

class Base {
private:
    virtual void f1() {
        cout<<"base private fun1"<<endl;
    }
};


class Derive : public Base {
public:
    void fun1() {
        cout<<"derive public func1"<<endl;
    }
};

typedef void (*FUNC)();


int main()
{
    Derive d;
    FUNC f = (FUNC)((int*)(*(int*)(*(int*)(&d))));
    f();
    return 0;
}
