// Write a function to find the longest common prefix string amongst an array of strings.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(!strs.size())
            return result;
        //找出最小长度的字符串
        int minLen=INT_MAX,index=0;
        for(int i=0;i<strs.size();i++) {
            if(strs[i].size()<minLen) {
                minLen=strs[i].size();
                index=i;
            }
        }
        
        for(int i=0;i<minLen;i++) {
            char ch=strs[index][i];
            for(int j=0;j<strs.size();j++) {
                if(ch==strs[j][i])
                    continue;
                else
                    return result;
            }
            result+=ch;
        }
        return result;
    }
};
