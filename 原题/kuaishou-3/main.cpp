/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int aval, bval, x;
    Node(int _a, int _b, int _x):aval(_a), bval(_b), x(_x){}  
    bool operator < (const Node &b) const {
        return (bval - aval) > (b.bval-b.aval);
    }
};

class Solution {
public:
    /**
     * 根据顾客属性计算出顾客排队顺序
     * @param a int整型vector 顾客a属性
     * @param b int整型vector 顾客b属性
     * @return int整型vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        // write code here
        priority_queue<Node, vector<Node>, less<Node>> que;
        int n = a.size();
        for(int i=0; i<n; i++){
            que.emplace(Node(a[i], b[i], i+1));
        }
        vector<int> ans;
        while(!que.empty()){
            cout<<que.top().aval<<' '<<que.top().bval<<endl;
            ans.emplace_back(que.top().x);
            que.pop();
        }
        return ans;
    }
};
int main(){
    vector<int> a = {8, 9, 7};
    vector<int> b = {5, 8,3};
    Solution().WaitInLine(a,b);
    return 0;
}

// 第一次答案 40%
// struct Node{
//     int aval, bval, x;
//     Node(int _a, int _b, int _x):aval(_a), bval(_b), x(_x){}  
//     bool operator > (const Node &b) const {
//         return aval == b.aval? bval<b.bval : aval>b.aval;
//     }
// };

// class Solution {
// public:
//     /**
//      * 根据顾客属性计算出顾客排队顺序
//      * @param a int整型vector 顾客a属性
//      * @param b int整型vector 顾客b属性
//      * @return int整型vector
//      */
//     vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
//         // write code here
//         priority_queue<Node, vector<Node>, greater<Node>> que;
//         int n = a.size();
//         for(int i=0; i<n; i++){
//             que.emplace(Node(a[i], b[i], i+1));
//         }
//         vector<int> ans;
//         while(!que.empty()){
//             // cout<<que.top().aval<<' '<<que.top().bval<<endl;
//             ans.emplace_back(que.top().x);
//             que.pop();
//         }
//         return ans;
//     }
// };