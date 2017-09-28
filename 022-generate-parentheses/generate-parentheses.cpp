//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n<=0)
            return result;
        backtracking(result, "", 0, 0, n);
        return result;
    }
    
    void backtracking(vector<string> &result, string s, int left, int right, int n) {
        if(s.size()==2*n)
            result.push_back(s);
        else {
            if(left<n) {
                backtracking(result, s+"(", left+1, right, n);
            }
            if(right<left) {
                backtracking(result, s+")", left, right+1, n);
            }
        }
    }
};
