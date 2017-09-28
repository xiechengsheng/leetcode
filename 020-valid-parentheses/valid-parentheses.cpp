// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//


class Solution {
public:
    bool isValid(string s) {
        if (s == "")
            return false;
            
        stack<char> temp;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push(s[i]);  
            }
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(temp.empty())
                    return false;
                else {
                    if(temp.top() == '(' && s[i] == ')' || temp.top() == '[' && s[i] == ']' || temp.top() == '{' && s[i] == '}') {
                        temp.pop();
                    }
                    else
                        return false;
                }
            }
        }
        if(temp.empty())
            return true;
        else
            return false;
        
    }
};
