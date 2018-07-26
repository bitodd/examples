#include <memory>
#include <string>
#include <iostream>


using namespace std;

class Aircraft {
    public:
        Aircraft() {
            cout<<"_Generic Aircraft"<<endl;
        }
        ~Aircraft() {
            cout<<"~Aircraft"<<endl;
        }
};

int main(int argc, char* argv[]) {
    Aircraft* myAircraft = new Aircraft;
    {
        shared_ptr<Aircraft> spAircraft(myAircraft);
        cout<<"ref count:"<<spAircraft.use_count()<<endl;
    }

    shared_ptr<Aircraft> spAircraft2(myAircraft);
    cout<<"ref count:"<<spAircraft2.use_count()<<endl;
    return 0;
}
