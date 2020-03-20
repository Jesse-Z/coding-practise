#include<bits/stdc++.h>
using namespace std;
long long n, l;

int main(){
    // cout<<"yes";
    // n = 18, l = 2;
    cin>>n>>l;
    int first=-1, last=-1;
    for(int i=l; i<=100; ++i){
        if(i&1 and n%i==0){
            int mid = n/i;
            first = mid - i/2;
            last  = mid + i/2;
            if(first >= 0)
                break;   // first 合法，找到答案
        }
        if(!(i&1) and ((double)n/i - n/i) == 0.5){
            int mid = n/i;
            first = mid - (i/2 -1);
            last  = mid + i/2;
            if(first >= 0)
                break;
        }
    }
    // cout<<first<<' '<<last<<endl;
    if (first>=0){
        for (int i=first; i<last; ++i)
            cout<<i<<' ';
        cout<<last<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}