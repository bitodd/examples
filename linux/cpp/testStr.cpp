#include "string"
#include "iostream"
using namespace std;

char* testChar(){
    char* test = "hello";
    //char test = "hellp";
    return test;
}
int main(void) {

    char* ret = testChar();
    char* tmp = NULL;
    delete tmp;
    cout<<"ret:"<<ret<<endl;
    return 0;

}
