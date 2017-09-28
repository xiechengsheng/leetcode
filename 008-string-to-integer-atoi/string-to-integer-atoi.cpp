// Implement atoi to convert a string to an integer.
//
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//
// Notes: 
// It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
//
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//
// spoilers alert... click to show requirements for atoi.
//
// Requirements for atoi:
//
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//
//


class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        //消除空格
        int i=0;
        while(str[i]==' ') i++;
        
        //符号位
        int sign=1;
        if(str[i]=='-'||str[i]=='+') {
            if(str[i]=='-') sign=-1;
            i++;
        }
        
        //无效的输入判断，如果有无效的输入，马上终止循环
        int sum=0;
        for(int j=i;j<len&&str[j]>='0'&&str[j]<='9';j++) {
            //先进行溢出判断，定义的sum为int，进行计算后就算溢出也不能发现
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&(str[j]-'0')>INT_MAX%10)) {
                if(sign==1) return INT_MAX;
                if(sign==-1) {
                    //-2147483648的考虑，不需要考虑，-2147483648就是INT_MIN
                    return INT_MIN;
                }
            }
            sum=sum*10+(str[j]-'0');
        }
        return sign*sum;
    }
};
