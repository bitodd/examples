#include <pthread.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
#if defined d_thread
    pthread_t tid = pthread_self();
    cout<<"tid:"<<tid<<endl;
#endif


    return 0;
}
