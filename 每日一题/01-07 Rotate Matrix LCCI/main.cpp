/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-07 
* 
* brief: 旋转矩阵，in place地完成
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flipud(matrix);
    }
    void transpose(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-i; ++j){
                int ni = n-1-i;
                int nj = n-1-j;
                swap(matrix[i][j], matrix[nj][ni]);
            }
        }
    }
    void flipud(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0; i<n/2; ++i){
            int ni = n-1-i;
            swap(matrix[i], matrix[ni]);
        }
    }
};
int main(){
    
    return 0;
}