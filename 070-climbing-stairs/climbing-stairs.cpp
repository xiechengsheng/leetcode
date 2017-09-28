// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//
// Note: Given n will be a positive integer.
//


class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;
        int result = 0;
        if(n <= 1) 
        {
            return 1;
        }
        else {
            // 使用函数递归，超时
            // return (climbStairs(n-1) + climbStairs(n-2));
            
            // 人工实现斐波那契数列
            for(int i = 2; i <= n; i++) {
                result = prev1 + prev2;
                prev1 = prev2;
                prev2 = result;
            }
            return result;
        }
    }
};
