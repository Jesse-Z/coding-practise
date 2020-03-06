#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
        while (candies!=0)
        {
            ans[i%num_people] += min(candies, i+1);
            candies -= min(candies, i+1);
            ++i;
        }
        return ans;
    }
};

int main(){
    printf("hello");
    Solution solve;
    vector<int> ans = solve.distributeCandies(7, 4);
    for (auto item:ans)
    {
        cout<<item<<endl;
    }
    
    return 0;
}
