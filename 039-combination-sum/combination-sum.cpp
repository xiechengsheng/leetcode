//
// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
//
//
// The same repeated number may be chosen from C unlimited number of times.
//
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
//
//
//
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
//
// [
//   [7],
//   [2, 2, 3]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> results;
        //请注意vector<int> {}这种用法，直接当成参数使用
        backtraching(results, vector<int> {}, 0, candidates, target);
        return results;
    }
    
    void backtraching(vector<vector<int>> &results, vector<int> result, int start, vector<int> candidates, int remain) {
        //一般回溯函数里面只会存在两种判断条件，相等或者不等，现在是相等或者小于或者大于，因此是三种判断条件
        if(remain==0) {
            results.push_back(result);
        }
        else if(remain<0)
            return;
        else {
            for(int i=start;i<candidates.size();i++) {
                result.push_back(candidates[i]);
                //这里不能将i+1放到backtracking函数中，这样的话就不能包含可以重复选取一个数字了
                backtraching(results, result, i, candidates, remain-candidates[i]);
                result.pop_back();
            }
        }
    }
};
