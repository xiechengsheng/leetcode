// Given a digit string, return all possible letter combinations that the number could represent.
//
//
//
// A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
//
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int len=digits.size();
        if(len==0)
            return result;
        vector<string> characters{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtracking(result, "", 0, digits, characters);
        return result;
    }
    
    void backtracking(vector<string> &result, string s, int start, string digits, vector<string> characters) {
        if(s.size()==digits.size())
            result.push_back(s);
        else {
            //这里回溯的时候，判断的循环条件是每个按键对应的多个字母的长度
            string letters=characters[digits[start]-'0'];
            for(int i=0;i<letters.size();i++) {
                s.push_back(letters[i]);
                backtracking(result, s, start+1, digits, characters);
                s.pop_back();
            }
        }
    }
};
