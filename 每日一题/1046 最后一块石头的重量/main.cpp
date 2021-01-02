/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-30 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n = stones.size(), ans = 0;
        if(n==1)
            return stones[0];
        if(n==0)
            return 0;
        for(auto i: stones){
            q.emplace(i);
        }
        while(q.size()>1){
            int first = q.top(); q.pop();
            int second = q.top(); q.pop();
            if(first == second)
                continue;
            if(first < second or first > second)
                q.emplace(abs(first - second));
        }
        return q.empty() ? 0 : q.top();
    }
};
int main(){
    
    return 0;
}