/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-18 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 矩阵不重叠有四种情况，上下，左右
        return !(rec1[2]<=rec2[0] or rec1[1] >=rec2[3] or rec1[0]>=rec2[2] or rec1[3]<=rec2[1]);
    }
};
int main(){
    
    return 0;
}