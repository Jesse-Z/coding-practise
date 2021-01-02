/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-29 
 
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

void printB(Base1 b){
    b.base1_fun1();
}

void printD(Derive1 d){
    d.base1_fun1();
}

void printPB(Base1* b){
    b->base1_fun1();
}
void printPD(Derive1* d){
    d->base1_fun1();
}

int main(){
    Base1 b1;
    Derive1 d1;
    Base1* pb1 = &b1;
    Base1* pd1 = &d1;

    printB(b1);
    printB(d1);
    printD(d1);
    
    printPB(pb1);
    printPD(dynamic_cast<Derive1*>(pd1));
    return 0;
}
