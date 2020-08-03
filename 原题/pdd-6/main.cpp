/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-02 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

// void turn_left(vector<int> &a){
//     swap(a[2], a[4]);
//     swap(a[3], a[5]);
//     swap(a[4], a[5]);
// }

// void turn_down(vector<int> &a){
//     swap(a[0], a[4]);
//     swap(a[1], a[5]);
//     swap(a[0], a[1]);
// }

int main(){
    int n, k;
    cin >> n;
    vector<vector<int>> q(n, vector<int>(6, 0));
    vector<int> ans;
    set<int> found;
    for(int i=0; i<n; ++i){
        for(int j=0; j<6; ++j){
            cin>>k;
            q[i][j] = k;
        }
    }

    // 如果相同，相对面应该相同，和相同
    for(int i=0; i<n; ++i){
        // 查过了 跳过
        if(found.find(i)!=found.end()) 
            continue;
        found.insert(i);
        int same = 1;

        vector<pair<int,int>> three_sum = {{q[i][0],q[i][1]}, {q[i][2],q[i][3]}, {q[i][4],q[i][5]}};
        for(int j=i+1; j<n; ++j){
            int diff = 0;
            if(found.find(j)!=found.end()) 
                continue;

            vector<pair<int,int>> curr_sum = {{q[j][0],q[j][1]}, {q[j][2],q[j][3]}, {q[j][4],q[j][5]}};
            for(auto i : three_sum){
                int sub_diff = 0;
                for(auto j:curr_sum){
                    if(i != j)
                        sub_diff++;
                }
                if(sub_diff==3)
                    diff++;
            }
            if(diff<2){
                same++;
                found.insert(j);
            }
        }
        ans.emplace_back(same);
    }
    sort(ans.rbegin(), ans.rend());
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); ++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}