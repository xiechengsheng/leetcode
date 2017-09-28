// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note: The solution set must not contain duplicate quadruplets.
//
//
//
// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //在3sum的基础上面，最外面再加一层循环
        vector<vector<int>> results;
        int len=nums.size();
        if(len<4)
            return results;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++) {
            if(i==0||nums[i]!=nums[i-1]) {
                for(int j=i+1;j<len-2;j++) {
                    if(j==i+1||nums[j]!=nums[j-1]) {
                        int left=j+1,right=len-1;
                        while(left<right) {
                            int number=nums[i]+nums[j]+nums[left]+nums[right];
                            if(number==target) {
                                results.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                                while(nums[left]==nums[left+1] && left<right) left++;
                                while(nums[right]==nums[right-1] && left<right) right--;
                                left++;
                                right--;
                            }
                            else if(number<target)
                                left++;
                            else
                                right--;
                        }
                    }
                }
            }
        }
        return results;
    }
};
