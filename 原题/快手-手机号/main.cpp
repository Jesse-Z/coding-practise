/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;

// 分割出手机号
vector<string> splitNumber(string s){
    int start = 0;
    vector<string> nums;
    while(s[start]!='\0'){
        if(s[start]==',')
            start++;
        string temp;
        nums.emplace_back(s.substr(start, 11));
        start+=11;
    }
    return nums;
}

// 求豹子子串长
int isBaozi(string s){
    int i = 3, ans = 1;  // 从第四位开始，长度从1开始
    char pre = s[i++];
    for (; i < 11; i++){
        if(s[i]==pre)
            ans++;
        else
            pre = s[i];
    }
    return ans>=3 ? ans : -1;
}

// 求顺子长
int isShun(string s){
    int i = 3, ans=1; 
    for(; i<10; ){
        while(s[i]==s[i+1]-1){
            ans++;
            i++;
        }
        if(ans<3){
            ans = 1;
            i++;
        }
        else
            break;
    }
    return ans>=3 ? ans: -1;
}

// 
int main(){
    string s;
    cin>>s;
    vector<string> a;
    a = splitNumber(s);
    map<string, string, greater<string>> ans;
    for(auto c:a){
        int baozi = isBaozi(c);
        int shunzi = isShun(c);
        if(baozi != -1 or shunzi != -1){
            string temp = baozi>=shunzi? to_string(baozi)+ '1' + c: to_string(shunzi)+ '0' + c;
            ans[temp] = c;
        }
    }
    if(ans.empty())
        cout<<"null"<<endl;
    auto iter = ans.begin();
    while(iter!=ans.end()){
        cout<<iter->second<<endl;
        iter++;
    }
    return 0;
}