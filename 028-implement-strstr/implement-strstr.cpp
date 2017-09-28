//
// Implement strStr().
//
//
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//


class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1=haystack.size(), length2=needle.size();
        if(length2>length1)
            return -1;
        for(int i=0;i<=length1-length2;i++) {
            int j=0;
            for(;j<length2;j++) {
                if(needle[j]!=haystack[i+j]) {
                    break;
                }
            }
            if(j==length2)
                return i;
        }
        return -1;
    }
};
