/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-06 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for(int i=2; i<= (int)sqrt(x); ++i){
        if(x%i)
            return false;
    }
    return true;
}

bool isParadim(string x){
    string s = "#";
    for(int i=0; i<x.length(); ++i){
        s.append({x[i], '#'});
    }
    // cout<<s<<endl;
    int center = s.length()/2, radis = s.length()/2;
    // cout<<center<<' '<<radis<<endl;
    for(int i=1; i<=radis; ++i){
        if(s[center+i]!=s[center-i]){
            // cout<<s[center+i]<<' '<<s[center-i]<<endl;
            return false;
        }
    }
    return true;
}

int main(){
    int n, m, cnt;
    cin>>n>>m;
    set<string> memo;

    for(int i=n; i<=m; ++i){
        string curr = to_string(i);
        for(int j=0; j<curr.length(); ++j){
            string minusone = curr;
            minusone.erase(j);
            if(memo.find(minusone)!=memo.end()){
                cnt += (int)pow(10, curr.length()-j);
            }
            else if(isParadim(minusone)){
                if(isPrime(atoi(minusone.c_str()))){
                    memo.insert(minusone);
                    cnt += (int)pow(10, curr.length()-j);
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}