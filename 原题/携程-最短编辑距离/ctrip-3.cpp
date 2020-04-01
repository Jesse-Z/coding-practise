#include<bits/stdc++.h>
using namespace std;
vector<string> dict = {"surprise", "happy", "ctrip", "travel", "wellcome","student","system","program","editor"};
string ans = "null";

string insertC(string s, char c, int index){
    string left = s.substr(0, index);
    string right = s.substr(index);
    return left + c + right;
}

string replaceC(string s, char c, int index){
    if(index){
        string left = s.substr(0, index);
        string right = s.substr(index); 
        return left + c + right;
    }
    else{
        string right = s.substr(1);
        return c+right;
    }
}

string deleteC(string s, int index){
    if(index){
        string left = s.substr(0, index);
        string right = s.substr(index);
        return left+right;
    }
    else
    {
        return s.substr(1);
    }
    
}

void dfs(string s, string target,int cnt, int index){
    if(s == target and cnt<2){
        ans = s;
        return;
    }
    if(cnt>=2)
        return;
    for(int i=index; i<target.size(); ++i){
        if(s[i]!=target[i]){
            if(i<s.size()){
                dfs(replaceC(s, target[i], i), target, cnt+1, i+1);
                dfs(deleteC(s, i), target, cnt+1, i);
            }
            if(i<=s.size())
                dfs(insertC(s, target[i], i), target, cnt+1, i+1);
        }
    }
}

string solve(string s){
    vector<string> probs;

    // 先剔除长度上不可能的
    for(auto c:dict){
        if(abs((int)(s.size() - c.size())) <= 2)
            dfs(s, c, 0, 0);
    }

    return ans;
}

int main(){
    string s;
    while(cin>>s){
        ans = "null";
        cout<<solve(s)<<endl;
    }
    return 0;
}