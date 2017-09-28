// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
//
//
//
// Above is a 3 x 7 grid. How many possible unique paths are there?
//
//
// Note: m and n will be at most 100.


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m,vector<int>(n, 1));
        //从坐标为(1,1)的点一直计算到坐标为(m-1,n-1)的点，(m-1,n-1)就是答案
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                res[i][j]=res[i-1][j]+res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
