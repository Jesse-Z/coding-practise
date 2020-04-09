/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-08 
 
 brief: 镜像回文字符串
 1 - 1,  2 - 5, 3 - 8, 4 - 7, 6 - 9
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<char, char> dict={{'1', '1'}, {'2', '5'}, {'3', '8'}, {'4', '7'}, {'5', '2'},
                                {'6', '9'}, {'7', '4'}, {'8', '3'}, {'9', '6'}};

bool isParadim(string s){
    long len = s.size();
    for(long i=0; i<len; ++i)
        if(dict[s[i]] != s[len-1-i])
            return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<string> ans;
    string temp;
    for(int i=0; i<n; ++i){
        temp.clear();
        cin>>temp;
        cout<<(isParadim(temp)?"YES":"NO")<<endl;
    }
    // for(int i=0; i<n; ++i)
    //     cout<<ans[i]<<endl;
    return 0;
}