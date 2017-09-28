// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //使用滑动窗口，两个指针，右指针遍历整个数组，左指针用于定位上次出现相同字符的地方
        //hashtable[character]=value
        unordered_map<char, int> hashtable;
        int maxSubLen=0;
        int left=-1;
        for(int i=0;i<s.size();i++) {
            if(hashtable.find(s[i])!=hashtable.end()) {
                left=max(left,hashtable[s[i]]);
            }
                
            hashtable[s[i]]=i;
            maxSubLen=max(maxSubLen,i-left);
        }
        return maxSubLen;
    }
};
