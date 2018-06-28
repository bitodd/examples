#include <iostream>
#include <memory>
using namespace std;
class Distance;
class A{
    A(Distance& d){

    }

} ;
class Distance
{
   private:
      int feet;            
      int inches;      
      std::unique_ptr<A> a;
   public:
      // 所需的构造函数
      Distance(){
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
         cout << "F: " << feet <<  " I:" <<  inches << endl;
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
   int var = 2;
   if(var){
       cout<<"var:"<<var<<endl;
   }

   cout<<"var2:"<<var<<endl;
   return 0;
}
