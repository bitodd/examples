#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <thread>
#include <algorithm>
#include <unordered_map>
#include <mutex>
#include <unistd.h>
using namespace std;


std::unordered_map<int, int> portMap;
std::unordered_map<int, int>::iterator iter;

std::mutex mtx;

void genRandomLowPort(int& lowUdpPort, const int highUdpPort) {
    int range = highUdpPort - lowUdpPort;
    if(range <= 20) return;
    lowUdpPort = (rand()%(range*2/5+1)) + lowUdpPort;
}

int dumplicateCount = 0;
int lowUdpPort = -1;
int highUdpPort = -1;
void join(int i) {
    int tmp_lowUdpPort = lowUdpPort;
    int tmp_highUdpPort = highUdpPort;
    //pthread_t tid;
    //tid = pthread_self();
    //std::thread::id tid = std::this_thread::get_id();
    size_t tid = std::hash<std::thread::id>{
    }(std::this_thread::get_id());
    cout<<"this thread id:"<<tid<<endl;
begin:
#if 1
    struct timeval tv;
    gettimeofday(&tv, NULL);
    cout<<"tv.tv_sec*1000*1000 + tv.tv_usec+tid:"<<tv.tv_sec*1000*1000 + tv.tv_usec+tid<<endl;
    //srand(tv.tv_sec*1000*1000 + tv.tv_usec);
#endif
#if 0
    cout<<"tid:"<<tid<<endl;
    srand(tid);
    struct timespec time1 = {0, 0};
    clock_gettime(CLOCK_MONOTONIC, &time1);
    printf("CLOCK_MONOTONIC: %lu, %lu\n", time1.tv_sec, time1.tv_nsec);
    srand(time1.tv_sec*1000000000+time1.tv_nsec);
#endif
    genRandomLowPort(tmp_lowUdpPort, tmp_highUdpPort);
    //all only read then no need lcok, once some thread write, then all need to lock
    std::lock_guard<std::mutex> lck (mtx);
    if((iter=portMap.find(tmp_lowUdpPort)) != portMap.end()) {
        dumplicateCount++;
        cout<<"the same port:"<<tmp_lowUdpPort<<",dumplicateCount:"<<dumplicateCount<<endl;
        goto begin;
    } else {
        portMap.insert(std::pair<int,int>(tmp_lowUdpPort, tmp_highUdpPort));
        //portMap[lowUdpPort] = highUdpPort;
    }
#if 0
    for(iter = portMap.begin(); iter!=portMap.end(); ++ iter){
        cout<<"iter->first:"<<iter->first<<",second:"<<iter->second<<endl;
    }
#endif
    cout<<"i:"<<i<<",dumplicateCount:"<<dumplicateCount<<",tmp_lowUdpPort:"<<tmp_lowUdpPort<<", tmp_highUdpPort:"<<tmp_highUdpPort<<",map size:"<<portMap.size()<<endl;
}

int main(int args, char* argv[]) {
    if(args != 3) {
        cout<<"./a.out threadCount lowUdpPort(highUdpPort=threadCount*4*5/2+lowUdpPort)"<<endl;
        return -1;
    }
    int n = atoi(argv[1]);
    lowUdpPort = atoi(argv[2]); 
    highUdpPort = n*4*5/2+lowUdpPort;
    cout<<"lowUdpPort:"<<lowUdpPort<<", highUdpPort:"<<highUdpPort<<endl;
    
    for(int i = 0; i<n; ++i) {
        thread t(join, i);
        cout<<"new thead id:"<<t.get_id()<<endl;
        t.detach();
    }
    while(1) {


    }
    return 0;
}

