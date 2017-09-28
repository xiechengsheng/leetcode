//
// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
//
// Given an encoded message containing digits, determine the total number of ways to decode it.
//
//
//
// For example,
// Given encoded message "12",
// it could be decoded as "AB" (1 2) or "L" (12).
//
//
//
// The number of ways decoding "12" is 2.
//


class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(!len||s[0]=='0')
            return 0;
        //其实可以只记忆当前值和上次的值,节约空间复杂度
        vector<int> res(len+1,0);
        
        //初始条件
        res[0]=1;
        res[1]=1;
        
        //循环条件
        for(int i=2;i<=len;i++){
            int first = s[i-1]-'0';
            int second = stoi(s.substr(i-2,2));
            if(first>=1&&first<=9)
                res[i]+=res[i-1];
            if(second>=10&&second<=26)
                res[i]+=res[i-2];                
        }
        return res[len];
    }
};
