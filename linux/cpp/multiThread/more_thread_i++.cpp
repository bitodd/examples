#include <thread>
#include <cstring>
#include <iostream>
#include <mutex>
#include <csignal>
#include <unistd.h>
#include <atomic>

using namespace std;

std::atomic<bool> g_bSignalStop(false);

void signal_handler(int signo) {
    cerr<<"signal:"<<signo<<endl;
    g_bSignalStop = true;
}

int i=0;
class Test {
public:
    Test() : j(9.9){
        //i = 0;
    }
    ~Test(){}
    void print() {
        //std::lock_guard<std::mutex> lock(m_mutex);
        i++;
    }
#if 0
    void print(double j) {
        cout<<"j:"<<j<<endl;
    }
#endif
private:
    //int i;
    const double j;
    mutex m_mutex;

};

int main(int argc, char* argv[]) {

    signal(SIGQUIT, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGINT, signal_handler);
    int num = atoi(argv[1]);
    cout<<num<<endl;
    Test test;
#if 1
    for(auto i = 0; i < num; ++i) {
        thread t(&Test::print, &test);
        t.detach();
        cout<<"new next thread,i:"<<i<<endl;
    }
#endif
    while(1 && !g_bSignalStop){
        
    }
    cout<<"at last i:"<<i<<endl;
    return 0;
}
