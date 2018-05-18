#include <iostream>
using namespace std;

int recursive(int num) {

    if(num ==1) {
        return 1;
    } else {
        return num * recursive(num-1);
    }
}

int FirstFactorial(int num) { 

    num = recursive(num);
    cout<<"result:"<<num<<endl;
    return num; 

}

int main() { 
    int num = 0;
    cin>>num;
    cout << FirstFactorial(num);
    return 0;

} 
