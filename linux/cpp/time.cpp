#include <sys/time.h>
#include <time.h>
#include <cstdio>
#include <iostream>
using namespace std;

void time2string(char *buffer, int len) {
    timespec spec = {0, 0};
    tm t;
    if(clock_gettime(CLOCK_MONOTONIC, &spec) == -1) return;
    int used = (int)strftime(buffer, len, "%Y%m%d%H%M%S", localtime_r(&spec.tv_sec, &t));
    if(used > 0 && used < len - 4)  // we have enough space 
        snprintf(buffer+used, len-used, "%03u", (unsigned int)(24969604/1000)); 

}
void time2string2(char *buffer, int len) 
{
    timeval now;
    now.tv_sec = 24969604/1000;
    gettimeofday(&now, NULL); 
    struct tm * timeinfo;
    timeinfo = gmtime(&now.tv_sec);
    int used = (int)strftime(buffer, len, "%Y%m%d%H%M%S", timeinfo);
    if(used > 0 && used < len - 4)  // we have enough space
        snprintf(buffer+used, len-used, "%03u", (unsigned int)now.tv_usec/1000); 
}

int main() {
    char tmp[80];
    time2string(tmp, 80);
    cout<<"tmp:"<<(string)tmp<<endl;
    return 0;
}
