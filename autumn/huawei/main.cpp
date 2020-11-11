/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-09-25 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Box
{
private:
    T x, y;
    T w, h;
public:
    Box<T>(T x_, T y_, T w_, T h_)
    {
        x = x_;
        y = y_;
        w = w_;
        h = h_;
    }
};

template<class T>
class smartPtr{
private:
    int *cnt;
    T *ptr;
public:
    smartPtr(T *p): ptr(p){
        cnt = new int(1);
    }

    ~smartPtr(){
        if(--(*cnt)==0){
            delete ptr;
            ptr = nullptr;
            delete cnt;
            cnt = nullptr;
        }
    }
    smartPtr(smartPtr<T> &ori){
        ptr = ori.ptr;
        cnt = ori.cnt;
        (*cnt)++;
    }
    smartPtr<T>& operator=(const smartPtr<T> &ref){
        cnt = ref.cnt;
        (*cnt)++;
        ptr = ref.ptr;
    } 
    int getCnt(){
        return *cnt;
    }
    T* getPtr(){
        return ptr;
    }
};
int main(){
    int *num = new int(32);
    smartPtr<int> a(num);
    smartPtr<int> b(a);
    printf("%d, %d\n", a.getCnt(), *a.getPtr());
    printf("%d, %d\n", b.getCnt(), *b.getPtr());


    return 0;
}

public int[] relativeSortArray2(int[] arr1, int[] arr2) {
    int[] count = new int[1001];
    // 遍历arr1中的元素并计数
    for (int num : arr1) {
        count[num]++;
    }
    int index = 0;
    // 处理arr2中的元素
    for (int num : arr2) {
        while (count[num] > 0) {
            arr1[index++] = num;
            count[num]--;
        }
    }
    // 处理剩余不是arr2中的元素
    for (int i=0; i<count.length; i++) {
        while (count[i] > 0) {
            arr1[index++] = i;
            count[i]--;
        }
    }
    return arr1;
}