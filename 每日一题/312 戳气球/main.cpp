/**
 * Jesse@FDU-VTS-MIA
 * created @date: 2020-07-19 
 *
 * brief: 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 *
 * 现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
 * 这里的 left 和 right 代表和 i 相邻的两个气球的序号。
 * 注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/burst-balloons
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include<bits/stdc++.h>
using namespace std;

// 一个个拿气球，会破坏后续状态，所以需要倒着来，一个个放进去
// 用dfs(left, right)代表插入气球后能够获得的最多硬币数，开区间
// 当left >= right - 1 时，开区间内放不下气球
// 当left < right - 1 时，遍历每个位置mid，其结果就是
// max(val[left]*val[mid]*val[right]+dfs(left, mid)+dfs(mid, right))
class Solution {
public:
    vector<vector<int>> rec;
    vector<int> val;
    int dfs(int left, int right){
        if(left>=right-1){
            return 0;
        }
        if(rec[left][right]!=-1){
            return rec[left][right];
        }
        for(int i=left+1; i<right; ++i){
            int sum = val[left] * val[i] * val[right];
            sum+= dfs(left,i) + dfs(i, right);
            rec[left][right] = max(sum, rec[left][right]);
        }
        return rec[left][right];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n+2);
        val[0] = val[n+1] = 1;
        for(int i=0; i<n; ++i){
            val[i+1] = nums[i];
        }
        rec.resize(n+2, vector<int>(n+2, -1));
        return dfs(0, n+1);
    }
};
int main(){
    
    return 0;
}