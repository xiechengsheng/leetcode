// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note: The solution set must not contain duplicate triplets.
//
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序，左右指针向中间夹逼
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        if(nums.size()<2)
            return results;
        for(int i=0;i<nums.size()-2;i++) {
            //需要将重复的数pass掉，在里面左右指针也需要pass掉重复的数
            if(i==0||nums[i]!=nums[i-1]) {
                vector<int> result(3);
                result[0]=nums[i];
                
                int j=i+1,k=nums.size()-1;
                while(j<k) {
                    if(nums[i]+nums[j]+nums[k]==0) {
                        result[1]=nums[j];result[2]=nums[k];
                        results.push_back(result);  
                        //pass掉重复的数
                        while(nums[j]==nums[j+1] && j<k) j++;
                        while(nums[k]==nums[k-1] && j<k) k--;
                        j++;k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]<0)
                        j++;
                    else
                        k--;
                }
            }  
        }
        return results;
    }
};
