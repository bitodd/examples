#include <cstdio>
#include <thread>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //std::thread::id this_id = std:;this_thread::get_id();
    //cout<<"thread id:"<<this_id<<endl;
    //return 0;
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("pid %u tid %u (0x%x)\n", (unsigned int)pid,
            (unsigned int)tid, (unsigned int)tid); /* tid是unsigned long int,这里只是方便转换 */
    cout<<"cout hex number:"<<std::hex<<tid<<std::dec<<endl;
    return 0;


}

