/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-12 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b){
    return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0]; 
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        return people;
    }
};
int main(){
    
    return 0;
}