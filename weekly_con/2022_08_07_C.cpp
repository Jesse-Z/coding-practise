/*
 * Jesse@FDU-VTS-MIA
 * created @date: 2022-08-07
 * brief: https://leetcode.cn/contest/weekly-contest-305/problems/check-if-there-is-a-valid-partition-for-the-array/
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // recursion, TLE
    bool validPartition(vector<int> &nums)
    {
        return help(nums, 0);
        // return dp_help(nums);
    }

    bool help(vector<int> &nums, int start)
    {
        if (start == nums.size())
            return true;
        if (start >= nums.size() - 1)
            return false;
        // 三种选择递归
        bool con1 = nums[start] == nums[start + 1] && help(nums, start + 2);
        bool con2 = false;
        bool con3 = false;
        if (start + 2 <= nums.size() - 1)
        {
            con2 = nums[start] == nums[start + 1] && nums[start] == nums[start + 2] && help(nums, start + 3);
            con3 = nums[start] == (nums[start + 1] - 1) && nums[start] == (nums[start + 2] - 2) && help(nums, start + 3);
        }
        return con1 || con2 || con3;
    }

};

int main()
{
    Solution solve;
    vector<int> nums = {993335,993336,993337,993338,993339,993340,993341};
    cout << solve.validPartition(nums);
}