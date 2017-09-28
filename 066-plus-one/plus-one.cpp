// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 进位
        int carry = 1;
        
        for(int i = digits.size()-1; i>=0; i--) {
            if(digits[i] + carry == 10) {
                digits[i] = 0;
                carry =1;
            }
            else {
                digits[i] += carry;
                carry = 0;
            }
        }
        // 这种情况一定是类似于这种：99999999+1
        if(carry) {
            digits.push_back(carry);
            reverse(digits.begin(),digits.end());
        }
            return digits;
    }
};
