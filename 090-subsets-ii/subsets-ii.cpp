//
// Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
// Note: The solution set must not contain duplicate subsets.
//
//
// For example,
// If nums = [1,2,2], a solution is:
//
//
//
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     //第一感觉是在Subset的基础上用set，但是是错的，因为对于多个相同的数字，不能解决
    //     //Input:[4,4,4,1,4]
    //     //Output:[[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
        
    //     //在Subset的基础将给定序列排序即可
    //     vector<vector<int>> combs;
    //     vector<int> comb;
    //     sort(nums.begin(),nums.end());
    //     for(int k=0;k<=nums.size();k++){
    //         backtracking(combs, comb, 0, k, nums);
    //     }
    //     return combs;
    // }
    
    // //相当于从nums个值中挑选出0-nums个值来
    // void backtracking(vector<vector<int>> &combs, vector<int> comb, int start, int k, vector<int> nums) {
    //     if(k==0)
    //     {
    //         combs.push_back(comb);
    //         return;
    //     }
    //     else {
    //         for(int i=start;i<nums.size();i++) {
    //             if(i==start || nums[i]!=nums[i-1]){
    //                 comb.push_back(nums[i]);
    //                 backtracking(combs, comb, i+1, k-1, nums);
    //                 comb.pop_back();
    //             }
    //         }
    //     }
    // }

        //第一感觉是在Subset的基础上用set，但是是错的，因为对于多个相同的数字，不能解决
        //Input:[4,4,4,1,4]
        //Output:[[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
        
        //在Subset的基础将给定序列排序即可
        set<vector<int>> combs;
        vector<int> comb;
        sort(nums.begin(),nums.end());
        for(int k=0;k<=nums.size();k++){
            backtracking(combs, comb, 0, k, nums);
        }
        vector<vector<int>> res;
        for(auto it=combs.begin();it!=combs.end();it++)
            res.push_back(*it);
        return res;
    }
    
    //相当于从nums个值中挑选出0-nums个值来
    void backtracking(set<vector<int>> &combs, vector<int> comb, int start, int k, vector<int> nums) {
        if(k==0)
        {
            combs.insert(comb);
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
