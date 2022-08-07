/*
 * Jesse@FDU-VTS-MIA
 * created @date: 2022-08-07
 * brief:
 */

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                if (nums[i] + diff == nums[j])
                {
                    for (int k = j + 1; k < n; ++k)
                    {
                        if (nums[j] + diff == nums[k])
                        {
                            ans++;
                            break;
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }
};

int main()
{
}
