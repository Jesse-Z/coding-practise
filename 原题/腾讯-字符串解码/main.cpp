/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-22 
 
 brief: 对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，
 例如字符串ABCABCABC将会被压缩为[3|ABC]，
 现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？ 
*/
#include<bits/stdc++.h>
using namespace std;

string repeat(string s,  int count) {  
    string r="";  
    for (int i = 0; i < count; i++) {  
        r += s;  
    }  
    return r;  
}

int main(){
    string s, curr="";
    cin>>s;
    vector<pair<int, string>> stack;
    int m=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]>='0' and s[i]<='9'){
            m = m*10 + s[i]-'0';
        }
        else if(s[i]>='A' and s[i]<='Z'){
            curr += s[i];
        }
        else if(s[i]=='|'){
            stack.emplace_back(make_pair(m, curr));
            m = 0;
            curr = "";
        }
        else if(s[i]==']'){
            curr = stack.back().second + repeat(curr, stack.back().first);
            stack.pop_back();
        }
    }
    cout<<curr<<endl;
    return 0;
}