//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
//
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
//
//
//
// Return true because "leetcode" can be segmented as "leet code".
//
//
//
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
//


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=s.size();
        vector<bool> res(len+1,false);
        
        //初始条件
        res[0]=true;
        for(int i=1;i<=len;i++){
            for(int j=i-1;j>=0;j--){
                if(res[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()) {
                    res[i]=true;
                    break;
                }
            }
        }
        return res[len];
    }
};
