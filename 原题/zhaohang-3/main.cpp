/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-03 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c;
    char temp[3];
    string rev_string;
    map<char, string> ten2binary = {{'1',"0001"}, {'2',"0010"}, {'3',"0011"}, {'4',"0100"}, {'5',"0101"},
                                {'6',"0110"}, {'7',"0111"}, {'8', "1000"}, {'9',"1001"}, {'0',"0000"}};
    cin>>n;
    vector<string> tens;
    vector<string> binarys;
    for(int i=0; i<n; ++i){
        cin>>c;
        sprintf(temp, "%03d", c);
        tens.emplace_back(temp);
    }    
    for(int i=0; i<n; ++i){
        rev_string = ten2binary[tens[i][0]] + ten2binary[tens[i][1]] + ten2binary[tens[i][2]];
        
        reverse(rev_string.begin(), rev_string.end());
        // cout<<rev_string<<endl;
        // 去除前导0
        int j = 0;
        while(j<rev_string.size() and rev_string[j]=='0') ++j;
        if(j!=rev_string.size()){
            for(;j<rev_string.size(); ++j)
                cout<<rev_string[j];
        }else{
            cout<<'0';
        }

        cout<<endl;
    }
    return 0;
}