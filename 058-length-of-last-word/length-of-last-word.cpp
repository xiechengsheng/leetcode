// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
//
// For example, 
// Given s = "Hello World",
// return 5.
//


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        
        // 1：length等于0会造成字符串索引溢出
        if(length == 0)
            return 0;
            
        // 2.思路是构建一个新的字符串接收非空格的字符
        string temp = "";
        for(int i = length - 1; i >= 0; --i) 
        {
            if(s[i] != ' ')
                temp += s[i];
            else if(s[i] == ' ' && temp.length() != 0)
                break;
            else if(s[i] == ' ' && temp.length() == 0)  
                continue;
            else
            {
                
            }
        }
        
        int result = temp.length();
        return result;
    }
};
