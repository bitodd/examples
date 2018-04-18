#include <iostream>
#include <string>

using namespace std;
class IRtcEngineParameter
{
public:
    /**
    * release the resource
    */
    virtual void release() = 0;
};
class IRtcEngine
{
};

template<class T>
class AutoPtr {
    typedef T value_type;
    typedef T* pointer_type;
public:
    AutoPtr(pointer_type p=0)
        :ptr_(p)
    {}
    ~AutoPtr() {
        if (ptr_)
            ptr_->release();
    }
    operator bool() const { 
        cout<<"operator bool() const"<<endl;
        return ptr_ != (pointer_type)0;
    }
    value_type& operator*() const {
        return *get();
    }

    pointer_type operator->() const {
        return get();
    }

    pointer_type get() const {
        return ptr_;
    }

    pointer_type release() {
        pointer_type tmp = ptr_;
        ptr_ = 0;
        return tmp;
    }
    void reset2(){
        cout<<"reset2"<<endl;
    }
    void reset(pointer_type ptr = 0) {
        cout<<"Autor ptr reset"<<endl;
        if (ptr != ptr_ && ptr_)
            ptr_->release();
        ptr_ = ptr;
    }
    template<class C1, class C2>
    bool queryInterface(C1* c, C2 iid) {
        pointer_type p = NULL;
        if (c && !c->queryInterface(iid, (void**)&p))
        {
            reset(p);
        }
        return p != NULL;;
	}
private:
    AutoPtr(const AutoPtr&);
    AutoPtr& operator=(const AutoPtr&);
private:
    pointer_type ptr_;
};
class AParameter : public AutoPtr<IRtcEngineParameter>
{
public:
    AParameter(IRtcEngine& engine) {
        cout<<"IRtcEngine& engine"<<endl;    
        initialize(&engine);
    }
    AParameter(IRtcEngine* engine) {
        cout<<"IRtcEngine* engine"<<endl;    
        initialize(engine); 
    }
    AParameter(IRtcEngineParameter* p) :AutoPtr<IRtcEngineParameter>(p) {
        cout<<"IRtcEngineParameter* p"<<endl;
    }
private:
    bool initialize(IRtcEngine* engine)
    {
        cout<<"AParameter initialize"<<endl;
        IRtcEngineParameter* p = NULL;
        //if (engine && !engine->queryInterface(0, (void**)&p))
            reset(p);
            reset2();
        return p != NULL;
    }
};
class B{
public:
    void f1(){
        cout<<"B f1"<<endl;
    }
    bool operator ()(int) {
        cout<<"bool operator!"<<endl;
    }
};
class D : public B{
public:
    void f2(){
        cout<<"D f2"<<endl;
    }
};

int main()
{
#if 1
    IRtcEngine *applite_;
    AParameter msp(*applite_);
    return 0;
    msp.reset2();
    if(!msp)
        cout<<"msp is null"<<endl;
    cout<<"end"<<endl;
#else
    B b;
    bool ret = b(5);
    D d;
    //d(10);
    d.f1();
#endif
	return 0;
}
