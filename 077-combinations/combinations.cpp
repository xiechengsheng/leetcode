//
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//
// For example,
// If n = 4 and k = 2, a solution is:
//
//
//
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combs;
        backtracking(combs, vector<int> {}, 1, n, k);
        return combs;
    }
    
    void backtracking(vector<vector<int>> &combs, vector<int> comb, int start, int n, int k) {
        if(0 == k) {
            combs.push_back(comb);
            return;
        }
        else {
            for(int i=start;i<=n;i++) {
                comb.push_back(i);
                backtracking(combs,comb,i+1,n,k-1);
                comb.pop_back();
            }
        }
    }
};
