//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//
//
// For example,
// [1,1,2] have the following unique permutations:
//
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        int len=nums.size();
        vector<bool> used(len);
        backtracking(results, vector<int> {}, nums, used, len);
        return results;
    }
    
    void backtracking(vector<vector<int>> &results, vector<int> result, vector<int> nums, vector<bool> used, int len) {
        if(result.size()==len)
            results.push_back(result);
        else {
            for(int i=0;i<len;i++) {
                if(used[i]||i>0&&nums[i]==nums[i-1]&&!used[i - 1])
                    continue;
                result.push_back(nums[i]);
                used[i]=true;
                backtracking(results, result, nums, used, len);
                result.pop_back();
                used[i]=false;
            }
        }
    }
};
