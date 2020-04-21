/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-21 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(int x_, int y_):x(x_), y(y_){}
};
bool cross(point a, point b, point p){
    int temp = (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);
    return temp > 0;
}
class Solution{
public:
    bool inTriangle(point a, point b, point c, point p){
        // 三个同号，则在三角形内部
        bool ans = cross(a, b, p);
        if(ans!=cross(b, c, p))
            return false;
        if(ans!=cross(c, a, p))
            return false;
        return true;
    }
};

int main(){
    point* a = new point(1, 1);
    point* b = new point(6, 3);
    point* c = new point(4, 7);
    cout<<Solution().inTriangle(*a, *b, *c, point(4, 8))<<endl;
    cout<<cross(*b, *c, point(7, 6));
    delete a; delete b; delete c;
    return 0;
}