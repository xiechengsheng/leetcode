// Implement pow(x, n).
//


class Solution {
public:
    double myPow(double x, int n) {
        //还好n是int型，不可能是小数
        //就是考察递归，注意终止条件
        if(n==0)    
            return 1;
        if(n<0) {
            //专门考虑x是0的情况
            if(x)
                x=1/x;
            else
                return 0;
            
            //专门考虑INT_MIN取反会出现溢出问题，n是INT_MIN变成INT_MAX，减小了1，需要多乘一个x
            if(n==INT_MIN) {
                n=INT_MAX;
                return (n%2)?x*x*myPow(x*x,n/2):x*myPow(x*x,n/2);
            }
            else{
                n=-n;
            }
        }
        return (n%2)?x*myPow(x*x,n/2):myPow(x*x,n/2);
    }
};
