// Given an index k, return the kth row of the Pascal's triangle.
//
//
// For example, given k = 3,
// Return [1,3,3,1].
//
//
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
//


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //1.找规律Cn(m)与Cn(m+1)之间的递推关系
        //2.防止溢出
        vector<int> res(rowIndex+1,1);
        int curr=1,next=1;
        for(int i=0;i<=rowIndex/2;i++) {
            res[i]=curr;
            res[rowIndex-i]=curr;
            next=((long)curr*(rowIndex-i))/(i+1);
            curr=next;
        }
        return res;
    }
};
