//
// Given a set of distinct integers, nums, return all possible subsets.
//
// Note: The solution set must not contain duplicate subsets.
//
//
// For example,
// If nums = [1,2,3], a solution is:
//
//
//
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combs;
        vector<int> comb;
        for(int k=0;k<=nums.size();k++){
            backtracking(combs, comb, 0, k, nums);
        }
        return combs;
    }
    
    //相当于从nums个值中挑选出0-nums个值来
    void backtracking(vector<vector<int>> &combs, vector<int> comb, int start, int k, vector<int> nums) {
        if(k==0)
        {
            combs.push_back(comb);
            return;
        }
        else {
            for(int i=start;i<nums.size();i++) {
                comb.push_back(nums[i]);
                backtracking(combs, comb, i+1, k-1, nums);
                comb.pop_back();
            }
        }
    }
};
