//
// Given two binary strings, return their sum (also a binary string).
//
//
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//


class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size(), len_b= b.size();
        int carry = 0;
        string res;
        for(int i =0;i<len_a||i<len_b;i++) {
            int val_a = i<len_a?a[len_a-i-1]-'0':0, val_b=i<len_b?b[len_b-i-1]-'0':0;
            int sum = val_a + val_b + carry;
            res=char(sum%2+'0')+res;
            carry=sum/2;
        }
        if(carry)
            res=char(carry+'0')+res;
        return res;
    }
};
