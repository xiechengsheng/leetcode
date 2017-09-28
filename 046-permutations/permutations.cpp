//
// Given a collection of distinct numbers, return all possible permutations.
//
//
//
// For example,
// [1,2,3] have the following permutations:
//
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> results;
        backtracking(results, vector<int> {}, nums, len);
        return results;
    }
    
    void backtracking(vector<vector<int>> &results, vector<int> result, vector<int> nums, int len) {
        if(result.size()==len){
            results.push_back(result);
        }
        else{
            for(int i=0;i<len;i++){
                //考虑数组为[1,2]的情况，首先加入1，其次是2，将[1,2]加入结果集中，加入之后继续原来的函数断点执行，执行pop，2弹出，此时i=2，因此第二层的backtracking函数也退出，回溯到第一层的backtracking，继续第一层的backtracking之后执行，pop，1也随之弹出，数组为空，此时i=0,i++,i=1，之后向数组中加入nums[1]，恰好加入2！
                auto it=find(result.begin(),result.end(),nums[i]);
                if(it!=result.end()) 
                    continue;
                result.push_back(nums[i]);
                backtracking(results,result,nums,len);
                result.pop_back();
            }
        }
    }
    
};
