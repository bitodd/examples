#include <cstring>
#include <iostream>

#include <vector>

using namespace std;


int main(int argc, char* argv[]) {
    
    string str = "hello";
    std::vector<std::string> vec;
    // uses the rvalue reference push_back(T&&) overload, which means no strings will be copied;  
    // instead, the contents of str will be moved into the vector.  
    // This is less expensive, but also means str might now be empty. 
    vec.push_back(std::move(str));
    for(auto i : vec) {
        cout<<"v[i]:"<<i<<endl;
    }
    cout<<"after move str is:"<<str<<endl;
    return 0;
}
