/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-23 
 
 brief: https://leetcode-cn.com/problems/first-unique-character-in-a-string/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        int n = s.length();
        for(int i=0; i<n; ++i){
            if(position.count(s[i])==0){
                position[s[i]] = i;
                q.emplace(s[i], i);
            }else{
                position[s[i]] = -1;
                while(!q.empty() and position[q.front().first] == -1)
                    q.pop();
            }
        }
        return q.empty() ? -1: q.front().second;
    }
};
int main(){
    
    return 0;
}