#include <iostream>
using namespace std;

#include <string.h>

string FirstReverse(string str) { 

  string temp = "";
  int i = strlen(str.c_str());
  while(0<i--) {
      temp.push_back(str[i]);
  }
  str=temp;
  // code goes here   
  return str; 
            
}

int main() {
    string str;
    getline(cin, str);
    cout<<"input:"<<str<<endl;
    cout<<FirstReverse(str)<<endl;
    return 0;
}
