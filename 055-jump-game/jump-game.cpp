//
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//
// Each element in the array represents your maximum jump length at that position. 
//
//
// Determine if you are able to reach the last index.
//
//
//
// For example:
// A = [2,3,1,1,4], return true.
//
//
// A = [3,2,1,0,4], return false.
//


class Solution {
public:
    bool canJump(vector<int>& nums) {
        //直接计算出自己能够到达的最远的点,最后看最远的点能不能到达终点
        int reach=0,i=0;
        for(;i<nums.size()&&i<=reach;i++)
            reach=max(reach,i+nums[i]);
        return i==nums.size();
    }
};
