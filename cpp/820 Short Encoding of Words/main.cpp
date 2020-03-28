/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-28 
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    A *next[26];
    int count;
    A(){
        for(int i=0; i<26; ++i)
            next[i] = nullptr;
        count = 0;
    }
    A* get(char c){
        if(next[c-'a']==nullptr){
            next[c-'a'] = &A();
            count++;
        }
        return next[c-'a'];
    }
};

class TrieNode{
    TrieNode *next[26];
    public:
        int count;
        TrieNode(){
            for(int i=0; i<26; ++i)
                next[i] = nullptr;
            count = 0;
        }
        ~TrieNode(){
            for(int i=0; i<26; ++i)
                if(next[i]!=nullptr){
                    cout<<"delete "<<(char)('a'+i)<<endl;
                    delete next[i];
                }
        }
        TrieNode* get(char c){
            if(next[c-'a']==nullptr){
                next[c-'a'] = new TrieNode();
                count++;
            }
            return next[c-'a'];
        }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode();
        // 保存每个单词的尾巴（倒叙中，就是头）
        unordered_map<TrieNode*, int> nodes;
        for(int k=0;k<words.size();++k){
            TrieNode *cur = root;
            for(int i=words[k].size() - 1; i>=0; --i){
                cur = cur->get(words[k][i]);
            }
            nodes[cur] = k;
        }
        int ans = 0;
        auto iter = nodes.begin();
        while(iter!=nodes.end()){
            if(iter->first->count==0)
                ans+=words[iter->second].length()+1;
            iter++;
        }
        delete root;
        return ans;
    }
};
int main(){
    vector<string> a = {"time", "me", "bound"};
    Solution().minimumLengthEncoding(a);
    return 0;
}