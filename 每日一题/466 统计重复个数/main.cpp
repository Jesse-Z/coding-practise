/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-19 
 
 brief: 由 n 个连接的字符串 s 组成字符串 S，记作 S = [s,n]。例如，["abc",3]=“abcabcabc”
 假设有S1=[s1,n1]，S2=[s2,n2].
 从S1中，删除字符来获得新字符串
 请你找出一个可以满足使[S2,M] 从S1获得的最大整数 M。
*/
#include<bits/stdc++.h>
using namespace std;

// 以s2的索引为关键字。假设我们遍历了 s1cnt 个 s1，此时匹配到了第 s2cnt 个 s2 中的第 index 个字符
// 如果我们之前遍历了 s1cnt' 个 s1 时，匹配到的是第 s2cnt' 个 s2 中同样的第 index 个字符，那么就有循环节了
// 我们用 (s1cnt', s2cnt', index) 和 (s1cnt, s2cnt, index) 表示两次包含相同 index 的匹配结果
// 那么哈希映射中的键就是 index，值就是 (s1cnt', s2cnt') 这个二元组
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1==0)
            return 0;
        unordered_map<int, pair<int, int>> memo;
        int s1cnt=0, index=0, s2cnt=0;
        pair<int, int> prev_loop, loop;
        while(1){
            ++s1cnt;
            // 遍历s1来找循环节
            for(int s1i=0; s1i<s1.size(); s1i++){
                if(s1[s1i]==s2[index]){
                    index++;
                    if(index==s2.size()){
                        s2cnt++;
                        index=0;
                    }
                }
            }
            // cout<<s1cnt<<' '<<s2cnt<<endl;
            // 没找到循环节，s1遍历完
            if(s1cnt==n1)
                return (s2cnt/n2);
            // 出现了之前的index
            if(memo.find(index)!=memo.end()){
                int s1cntprev = memo[index].first;
                int s2cntprev = memo[index].second;
                // 前s1cntprev个s1,包含了s2cntprev个s2
                prev_loop = {s1cntprev, s2cntprev};
                // 后面每(s1cnt-s1cntprev)个s1包含(s2cnt-s2cntprev)个s2
                loop = {s1cnt-s1cntprev, s2cnt-s2cntprev};
                break;
            }
            else{
                memo[index] = {s1cnt, s2cnt};
            }
        }
        int ans = prev_loop.second + (n1-prev_loop.first)/loop.first * loop.second;
        // cout<<prev_loop.first<<' '<<prev_loop.second<<endl;
        // cout<<loop.first<<' '<<loop.second<<endl;
        // cout<<ans<<endl;
        // 末尾还剩下一些
        int rest = (n1-prev_loop.first)%loop.first;
        for(int i=0; i<rest; ++i){
            for(int s1i=0; s1i<s1.size(); s1i++){
                if(s1[s1i]==s2[index]){
                    index++;
                    if(index==s2.size()){
                        ans++;
                        index=0;
                    }
                }
            }
        }
        return ans/n2;
    }
};
int main(){
    string s1 = "aaa";
    string s2 = "aaaaa";
    cout<<Solution().getMaxRepetitions(s1, 20, s2, 1);
    return 0;
}