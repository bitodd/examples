#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
#if 0
	vector<int> u(10,100);
    vector<int> v;
    v.push_back(1);
    copy(u.begin(),u.end(),v.begin());

    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
#else
    vector<int> v1;
#if 0
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
#endif
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    cout<<"v1:"<<v1.size()<<",v2:"<<v2.size()<<endl;
    copy(v2.begin(), v2.end(), v1.end());
#if 0
    cout<<"v1:"<<v1.size()<<",v2:"<<v2.size()<<endl;

    for(vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
    {
        cout<<"*iter:"<<*iter<<endl;
    }
#endif
    cout<<"end"<<endl;
#endif
    return 0;
}
