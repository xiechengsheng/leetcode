//
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
//
// click to show follow up.
//
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with an one-pass algorithm using only constant space?
//
//


class Solution {
public:
    void sortColors(vector<int>& nums) {
        //将所有的0放在数组左边，将所有的2放在数组右边，剩下的1自然在中间
        int end=nums.size()-1,start=0;
        for(int i=0;i<nums.size();i++) {
            while(nums[i]==2&&i<end) 
                swap(nums[i],nums[end--]);
            while(nums[i]==0&&i>start)
                swap(nums[i],nums[start++]);
        }
    }
};
