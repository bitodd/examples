#include <string>
#include <iostream>

using namespace std;


class Test {
    private:
        mutable int a;
    public:
        Test() : a(0) {

        }
        void f() const {
            a++;
            cout<<"a:"<<a<<endl;
        }
};

int main() {
    Test t;
    t.f();
    return 0;
}
