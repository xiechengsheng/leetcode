//
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//
//
// Some examples:
//
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
//


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string str:tokens) {
            if(str!="+"&&str!="-"&&str!="*"&&str!="/")
                nums.push(atoi(str.c_str()));
            else {
                int num2=nums.top();nums.pop();
                int num1=nums.top();nums.pop();
                if(str=="+") nums.push(num1+num2);
                else if(str=="-") nums.push(num1-num2);
                else if(str=="*") nums.push(num1*num2);
                else if(str=="/") nums.push(num1/num2);
            }
        }
        return nums.top();
    }
};
