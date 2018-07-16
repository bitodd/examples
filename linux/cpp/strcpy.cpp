#include "iostream"
#include "string.h"
#include "cassert"
#include "array"

using std::string;
using std::cout;
using std::endl;


char* mystrcpy(char* strDest, char* strSrc) {

    assert((strDest) && (strSrc));
    char* address = strDest;
    while((*strDest++ = *strSrc++) != '\0') ;
    
    return address;

}

void test()
{
    char s[]="123456789";
    char d[]="123";
    strcpy(d,s);
    printf("d=%s,\ns=%s",d,s);
}
int main(int argc, char* argv[]) {
#if 1
    char* strDest = new char[17];
    memset(strDest, 17, 0);
#else 
    array<char, 7> strDest{0};
#endif
#if defined atsfsaf
    cout<<"ret:"<<(strDest==NULL ? "true":"false")<<endl;
    char* strSrc = const_cast<char*>("hello strcpy");
    cout<<mystrcpy(strDest, strSrc)<<endl;
    cout<<strcpy(strDest, strSrc)<<endl;
#endif
    test();
    return 0;
}

