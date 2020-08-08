/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-08 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

string insertsharp(string s){
    string converted = "#";
    for(int i=0; i<s.length(); ++i){
        converted.append({s[i], '#'});
    }
    return converted;
}

int findcenter(string s){
    int center = s.length()/2, radis = s.length()-center;
    int c;
    bool flag = true;
    for(c=center; c<s.length(); ++c){
        flag = true;
        radis = s.length()-c;
        // cout<<s[c]<<endl;
        for(int i=1; i< radis; ++i){
            if(s[c+i]!=s[c-i]){
                flag = false;
                break;
            }
        }
        if(flag)
            break;
    }
    return c;
}

int main(){
    string s;
    cin>>s;

    string converted = insertsharp(s);
    int center = findcenter(converted);
    // cout<<center<<endl;
    int radis = center%2?converted.length()-(center):converted.length()-center;
    radis/=2;
    int rest = center%2? s.length()-2*radis+1:s.length() - 2*radis;
    // cout<<radis<<' '<<rest<<endl;
    for(int i=rest-1; i>=0; --i){
        s.append({s[i]});
    }
    cout<<s;
    return 0;
}