//
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//
// Each number in C may only be used once in the combination.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
//
//
//
// For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
// A solution set is: 
//
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> results;
        backtracking(results, vector<int> {}, candidates, 0, target);
        return results;
    }
    
    void backtracking(vector<vector<int>> &results, vector<int> result, vector<int> candidates, int start, int remain) {
        if(remain==0)
            results.push_back(result);
        else if(remain<0)
            return;
        else {
            for(int i=start;i<candidates.size();i++) {
                if(i>start&&candidates[i]==candidates[i-1])
                    continue;
                result.push_back(candidates[i]);
                backtracking(results, result, candidates, i+1, remain-candidates[i]);
                result.pop_back();
            }
        }
    }
};
