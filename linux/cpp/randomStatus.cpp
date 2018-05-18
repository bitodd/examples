#include <string>
#include <iostream>
using namespace std;

bool isMachineBroken = false;
void broken()
{
    sleep(1);
    cout<<"broken isMachineBroken:"<<isMachineBroken<<endl;
    bool new_ = true;
    bool isChanged = (new_==isMachineBroken)?false:true;
    if(isChanged)
    {
        isMachineBroken = true;
        cout<<"changed,isMachineBroken:"<<isMachineBroken<<endl;
        sleep(1);
    }
}

void normal()
{
    sleep(1);
    bool new_ = false;
    bool isChanged = (new_==isMachineBroken)?false:true;
    if(isChanged)
    {
        isMachineBroken = false;
        cout<<"changed,isMachineBroken:"<<isMachineBroken<<endl;
        sleep(1);
    }
}
bool broken_status = false;
int main()
{
    int count = 0;
    while(1){
        count++;
        if(count > 5){
            count = 0;
            broken_status = !broken_status;
        }
        if(broken_status)
            broken();
        else
            normal();

    }
    return 0;
}
