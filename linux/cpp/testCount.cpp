#include <string>
#include <iostream>
using namespace std;

void test(int& count) {
    if(count++ == 5)
    {
        cout<<"count:"<<count<<endl;
        count = 0;
    }
}

int main() {

    int count = 0;
    while(1){
        test(count); 
    }
    return 0;
}
