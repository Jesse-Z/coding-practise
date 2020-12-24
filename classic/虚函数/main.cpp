/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-23 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Base1
{
public:
    int base1_1;
    int base1_2;

    virtual void base1_fun1() {cout<<"base1.func1"<<endl;}
    virtual void base1_fun2() {cout<<"base1.func2"<<endl;}
};

class Derive1 : public Base1
{
public:
    int derive1_1;
    int derive1_2;

    // 覆盖基类函数
    virtual void base1_fun1() {cout<<"derive1.func1"<<endl;}
};
int main(){
    Derive1 d1;
    // 不管用父类还是子类的指针去调用，都发生动态绑定
    Derive1* pd1 = &d1;
    pd1->base1_fun1();
    Base1* pd2 = &d1;
    pd2->base1_fun1();

    Base1 b1;
    Base1* pb1 = &b1;
    pb1->base1_fun1();
    return 0;
}