/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-28 
 
 brief: Origin游戏平台想要提供玩家搜索功能，能够搜索指定昵称的玩家。

请你来设计一个算法，实现这样的搜索功能，给出输入的n个关键字，和所有的m个玩家的昵称，能够返回所有以这些关键字开头的所有玩家个数。

昵称和关键字均由小写字母组成。

1<=n<=100

1<=m<1000000
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    unordered_map<int, TrieNode*> next;
    public:
        int count[26];
        TrieNode(){
            // for(int i=0; i<26; ++i)
                // next[i] = nullptr;
            memset(count, 0, sizeof count);
        }
        // ~TrieNode(){
            // for(int i=0; i<26; ++i)
            //     if(next[i]!=nullptr){
            //         // cout<<"delete "<<(char)('a'+i)<<endl;
            //         delete next[i];
            //     }
        // }
        TrieNode* add(char c){
            if(next.find(c-'a')==next.end()){
                next[c-'a'] = new TrieNode();
            }
            next[c-'a']->count[c-'a']++;
            return next[c-'a'];
        }
        TrieNode* get(char c){
            return next[c-'a'];
        }
};
int main(){
    int n,m, ans=0;
    vector<string> query;
    string temp;
    cin>>n;
    for(int ni=0; ni<n; ni++){
        cin>>temp;
        query.emplace_back(temp);
    }
    cin>>m;
    TrieNode *head = new TrieNode(), *curr=nullptr;
    for(int mi=0; mi<m; mi++){
        cin>>temp;
        curr = head;
        for(int ti=0; ti<temp.size(); ++ti){
            curr = curr->add(temp[ti]); 
        }
    }
    for(int ni=0; ni<n; ni++){
        // ans = 0;
        curr = head;
        temp = query[ni];
        for(int ti=0; ti<temp.size(); ti++){
            curr = curr->get(temp[ti]);
            if(curr==nullptr)
                break;
        }
        if(curr)
            cout<<curr->count[*(query[ni].end()-1)-'a']<<endl;
        else{
            cout<<0<<endl;
        }
    }
    // delete head;
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// class TrieNode{
//     TrieNode *next[26];
//     public:
//         int count[26];
//         TrieNode(){
//             for(int i=0; i<26; ++i)
//                 next[i] = nullptr;
//             memset(count, 0, sizeof count);
//         }
//         ~TrieNode(){
//             for(int i=0; i<26; ++i)
//                 if(next[i]!=nullptr){
//                     // cout<<"delete "<<(char)('a'+i)<<endl;
//                     delete next[i];
//                 }
//         }
//         TrieNode* add(char c){
//             if(next[c-'a']==nullptr){
//                 next[c-'a'] = new TrieNode();
//             }
//             next[c-'a']->count[c-'a']++;
//             return next[c-'a'];
//         }
//         TrieNode* get(char c){
//             return next[c-'a'];
//         }
// };
// int main(){
//     int n,m, ans=0;
//     vector<string> query;
//     string temp;
//     cin>>n;
//     for(int ni=0; ni<n; ni++){
//         cin>>temp;
//         query.emplace_back(temp);
//     }
//     cin>>m;
//     TrieNode *head = new TrieNode(), *curr=nullptr;
//     for(int mi=0; mi<m; mi++){
//         cin>>temp;
//         curr = head;
//         for(int ti=0; ti<temp.size(); ++ti){
//             curr = curr->add(temp[ti]); 
//         }
//     }
//     for(int ni=0; ni<n; ni++){
//         // ans = 0;
//         curr = head;
//         temp = query[ni];
//         for(int ti=0; ti<temp.size(); ti++){
//             curr = curr->get(temp[ti]);
//             if(curr==nullptr)
//                 break;
//         }
//         if(curr)
//             cout<<curr->count[*(query[ni].end()-1)-'a']<<endl;
//         else{
//             cout<<0<<endl;
//         }
//     }
//     delete head;
//     return 0;
// }