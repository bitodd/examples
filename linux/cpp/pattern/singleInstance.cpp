#include "string"
#include "iostream"
#include "mutex"
#include "thread"
#include "stdlib.h"
using namespace std;

std::mutex m_mutex;
int instance_count;
int log_count;
class SingleInstance
{
private:
    static SingleInstance* m_instance;
    SingleInstance() : number(0)
    {
        instance_count++;
        cout<<"instance_count:"<<instance_count<<endl;
    }
    int number;
    const SingleInstance& operator=(const SingleInstance& lrs);
    SingleInstance(SingleInstance const &){}
public:
#if defined A 
    static SingleInstance* getInstance()
    {
        if(!m_instance)
        {
            cout<<"before lock_guard mutx"<<endl;
            //std::lock_guard<std::mutex> guard(m_mutex);
            if(!m_instance)
            {
                cout<<"new mutx"<<endl;
                instance_count++;
                m_instance = new SingleInstance;
            }
        }
        return m_instance;
    }
#elif defined B
    static SingleInstance* getInstance()
    {
        static SingleInstance p;
        return &p;
    }
#else
    static SingleInstance getInstance()
    {
        static SingleInstance p; 
        return p;
    }
#endif
public:
    void setNumber(const int & i)
    {
        number = i;
    }
    int getNumber()
    {
        return number;
    }
    void print()
    {
        log_count++;
        if(log_count%100 == 0)
            cout<<"SingleInstance print function!"<<endl;
    }
};

SingleInstance* SingleInstance::m_instance = NULL;

void run_instance(const int i)
{
#if defined A 
    SingleInstance* instance = SingleInstance::getInstance();
    instance->print();
#elif defined B
    if(i>2) return;
    SingleInstance* instance = SingleInstance::getInstance();
    instance->setNumber(i);
    cout<<"number is:"<<instance->getNumber()<<endl;

    SingleInstance* instance2 = SingleInstance::getInstance();
    instance2->setNumber(i+1);
    cout<<"number2 is:"<<instance2->getNumber()<<endl;
    cout<<"number1 is:"<<instance->getNumber()<<endl;
    
    instance->print();
    instance2->print();
#else 
    if(i>2) return;
    //SingleInstance instance = SingleInstance::getInstance();//compile error
#if 0
    instance.setNumber(i);
    cout<<"number is:"<<instance.getNumber()<<endl;

    SingleInstance instance2 = SingleInstance::getInstance();
    instance2.setNumber(i+1);
    cout<<"number2 is:"<<instance2.getNumber()<<endl;
    cout<<"number1 is:"<<instance.getNumber()<<endl;
    
    instance.print();
    instance2.print();
#endif
    SingleInstance::getInstance().setNumber(i);
    cout<<"number is:"<<SingleInstance::getInstance().getNumber()<<endl;
    SingleInstance::getInstance().setNumber(i+1);
    cout<<"number is2:"<<SingleInstance::getInstance().getNumber()<<endl;
#endif
}

void run_thread(int count)
{
    for(auto i = 0; i < count; ++i)
    {
        std::thread t(&run_instance, i);
        t.detach();
    }
}
void print_command_para(int argc, char* argv[])
{
    for(auto i = 0; i < argc; ++i)
    {
        cout<<"argv["<<i<<"]:"<<argv[i]<<endl;
    }
}

int main(int argc, char* argv[])
{
    print_command_para(argc, argv);
    int count = atoi(static_cast<char*>(argv[1]));
    cout<<"default normal global parameter:"<<instance_count<<", count:"<<count<<endl;
    run_thread(count);
    cout<<"instance_countanc:"<<instance_count<<endl;
    return 0;
}
