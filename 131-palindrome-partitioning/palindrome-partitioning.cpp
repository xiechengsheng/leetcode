//
// Given a string s, partition s such that every substring of the partition is a palindrome.
//
//
// Return all possible palindrome partitioning of s.
//
//
// For example, given s = "aab",
//
// Return
//
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        backtracking(results, vector<string> {}, s, 0);
        return results;
    }
    
    //对于输入为"aab"的情况，首先考虑[0,0]"a"（剩下的[1,2]"ab"按照同样的方式进行处理，是一个递归的过程），其次是[0,1]"aa"，最后[0,2]"aab"
    void backtracking(vector<vector<string>> &results, vector<string> result, string s, int start) {
        if(start==s.size())
            results.push_back(result);
        else {
            for(int i=start;i<s.size();i++) {
                //只有满足回文条件的时候才会对整个字符串进行切割处理
                if(isPalindrome(s, start, i)) {
                    result.push_back(s.substr(start, i-start+1));
                    backtracking(results, result, s, i+1);
                    result.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string s, int low, int high) {
        while(low<high) {
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    }
};
