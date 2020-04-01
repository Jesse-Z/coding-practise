/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-01 
*/
#include<bits/stdc++.h>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
struct Node{
    int start, end;
    Node(int s, int e):start(s), end(e){}
};
int calcMinStaff() {
    int n;
    cin>>n;
    deque<Node> calls;
    for(int i=0; i<n; ++i){
        int a, b;
        scanf("%d,%d", &a, &b);
        calls.emplace_back(Node(a, b));
    }
    int available = 0, total = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<n; ++i){
        Node a = calls.front(); calls.pop_front();
        int now = a.start;
        // 首先循环判断之前的有没有可以结束了的
        while(!que.empty() and que.top()<=now and available<=total){
            que.pop();
            available++;
        }
        // 有人可用
        if(available){
            available--;
            que.emplace(a.end);
            continue;
        }
        // 如果当前没有available，则加人
        if(!available){
            total++;
            que.emplace(a.end);
            continue;
        }
    }
    return total;
}
/******************************结束写代码******************************/


int main() {
    int res;

    
    res = calcMinStaff();
    cout << res << endl;
    
    return 0;

}
