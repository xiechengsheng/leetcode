// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //和机器人走路那题是一样的
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> res(m, vector<int>(n,grid[0][0]));
        
        for(int i=1;i<m;i++) {
            res[i][0]=res[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++) {
            res[0][j]=res[0][j-1]+grid[0][j];
        }        
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                res[i][j]=min(res[i-1][j],res[i][j-1])+grid[i][j];
            }
        }
        return res[m-1][n-1];
    }
};
