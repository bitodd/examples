#include <string>
#include <iostream>
using namespace std;

#include <thread>


class TestA {
public:
    TestA():member(0) {}
    ~TestA() {
        cout<<"~testA and std thread id: "<< std::this_thread::get_id()<<endl;
    }
public:
    void release() {
       cout<<"release and std thread id: "<< std::this_thread::get_id()<<endl;
       //delete this;
       cout<<"release end"<<endl;
       cout<<"member:"<<member<<endl;

    }
    void runThread() { m_thread = std::thread(&TestA::release, this); }
private:
    std::thread m_thread;
    int member;
};



int main() {
#if 0
    TestA* test = new TestA;
    test->runThread();
#endif
    float a = 1.f;
    double b = 0.8;
    cout<<"a*b:"<<a*b<<endl;
    cout<<"a*(1/5):"<<a*(1/5)<<",a*(4/5):"<<a*(4/5)<<endl;
    cout<<"a*(0.2):"<<a*(0.2)<<",a*(0.8):"<<a*(0.8)<<endl;
    cout<<"a*(double(1/5)):"<<a*(double(1/5*1.0))<<",a*(double(4/5)):"<<a*(double(4/5*1.0))<<endl;
    return 0;
}
