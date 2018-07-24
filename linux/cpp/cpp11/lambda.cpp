#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto func = [] {cout<<"this is lambda!"<<endl;};
    func();

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    for_each(vec.begin(), vec.end(), [](int iter) {
                cout<<"*iter:"<<iter<<endl;
            });
    return 0;
}
