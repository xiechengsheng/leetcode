// Given an array of integers, every element appears twice except for one. Find that single one.
//
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 解法一：hash表，已经通过
        // unordered_map<int, int> sol_map;
        // for(int i = 0; i < nums.size(); i ++) {
        //     if(sol_map[nums[i]])
        //         sol_map[nums[i]] ++;
        //     else
        //         sol_map[nums[i]] = 1;
        // }
        
        // for(auto it = sol_map.begin(); it != sol_map.end(); it ++) {
        //     if(it->second == 1)
        //         return it->first;
        // }
        // return -1;
        
        // 解法二：拍案叫绝的异或操作
        int result = 0;
        for(int i = 0; i < nums.size(); i ++) {
            result = result ^ nums[i];
        }
        return result;
    }
};
