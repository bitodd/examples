#include <iostream>
#include <memory>
using namespace std;
class Distance;
class A{
    private:
        int data;
    public:
    A(){
        data = 10;
    }
    void test(){
        cout<<"A::test"<<endl;
        cout<<"data:"<<data<<endl;
    }

};

class Distance
{
   private:
      int feet;            
      int inches;      
      std::unique_ptr<A> m_a;
   public:
      // 所需的构造函数
      Distance() : m_a(nullptr){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // 重载函数调用运算符
      
      bool operator ()(int a, int b, int c)
      {
         Distance D;
         // 进行随机计算
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
      }
      // 显示距离的方法
      void displayDistance()
      {
          cout << "displayDistance"<<endl;
         //cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
      void init()
      {
#if 1
          m_a.reset(new A);
          m_a->test();
#else 
#endif
      }
      
};
int main()
{
#if 0
   Distance D1(11, 10), D2;
 
   cout << "First Distance : "; 
   D1.displayDistance();
 
   D1(10, 10, 10); // invoke operator()
   cout << "Second Distance :"; 
   D2.displayDistance();
#endif
   Distance* d = new Distance;
   d->init();
   return 0;
}
