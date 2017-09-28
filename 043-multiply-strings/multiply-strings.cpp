// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vec1, vec2;
        int len1=num1.size(), len2=num2.size();
        
        //两个数相乘最大值的位数不会超过两个数的位数和
        vector<int> res(len1+len2, 0);
        
        for(int i=len1-1;i>=0;i--) {
            vec1.push_back(num1[i]-'0');
        }
        for(int j=len2-1;j>=0;j--) {
            vec2.push_back(num2[j]-'0');
        }
        
        // 不同的权位相乘，这里处理很重要，不能直接push_back，需要先把数组初始化成0，然后再把相应的权位来赋值
        for(int m=0;m<len1;m++) {
            for(int n=0;n<len2;n++) {
                res[m+n] += vec1[m]*vec2[n];
            }
        }
        
        //处理进位和数组中多出来赋值的0
        int carry=0;
        for(int p=0;p<len1+len2;p++) {
            int sum = res[p]+carry;
            carry=sum/10;
            res[p]=sum%10;
        }
        
        //处理0
        for(int q=len1+len2-1;q>=0;q--) {
            //如果能够执行到q=0了，那么证明数组的第一个数到最后一个数全是0，结果就是0，不能再把res[0]再弹出了
            if(res[q] || q==0)
                break;
            else
                res.pop_back();
        }
        
        //翻转
        reverse(res.begin(), res.end());
        string s;
        for(int number:res)
            s+=char(number+'0');
        return s;
    }
};
