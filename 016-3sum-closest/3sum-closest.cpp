// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//
//     For example, given array S = {-1 2 1 -4}, and target = 1.
//
//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            if(i==0||nums[i]!=nums[i-1]) {
                int j=i+1,k=nums.size()-1;
                while(j<k) {
                    int number=nums[i]+nums[j]+nums[k];
                    if(abs(number-target)<abs(closest-target)) {
                        closest=number;
                    }
                    if(number<target)
                        j++;
                    if(number>target)
                        k--;
                    if(number==target)
                        return number;
                }
            }
        }
        return closest;
    }
};
