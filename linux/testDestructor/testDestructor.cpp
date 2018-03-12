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
    TestA* test = new TestA;
    test->runThread();
    return 0;
}
