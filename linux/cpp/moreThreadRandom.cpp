#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <thread>
#include <algorithm>
#include <unordered_map>
using namespace std;


std::unordered_map<int, int> portMap;
std::unordered_map<int, int>::iterator iter;

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

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec + tv.tv_usec);
    genRandomLowPort(tmp_lowUdpPort, tmp_highUdpPort);
    if((iter=portMap.find(tmp_lowUdpPort)) != portMap.end()) {
        dumplicateCount++;
        cout<<"the same port:"<<lowUdpPort<<",dumplicateCount:"<<dumplicateCount<<endl;
    } else {
        //portMap.insert(std::make_pair<int,int>(lowUdpPort, highUdpPort));
        portMap[lowUdpPort] = highUdpPort;
    }
    cout<<"i:"<<i<<",dumplicateCount:"<<dumplicateCount<<",tmp_lowUdpPort:"<<tmp_lowUdpPort<<", tmp_highUdpPort:"<<tmp_highUdpPort<<endl;
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
        t.detach();
    }
    while(1) {


    }
    return 0;
}

