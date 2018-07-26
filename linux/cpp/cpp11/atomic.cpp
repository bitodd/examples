#include <string>
#include <iostream>
#include <atomic>

using namespace std;
 
const int ERR1= 1<<2;
const int ERR2= 1<<3;


int main(int argc, char* argv[]) {
    cout<<"err:"<<ERR1<<endl;
    std::atomic<int32_t> val ;
    val = 0;//must set a default value
    val.fetch_or(ERR1);
    val.fetch_or(ERR2);
    cout<<"val:"<<val.load()<<endl;

    return 0;
}
