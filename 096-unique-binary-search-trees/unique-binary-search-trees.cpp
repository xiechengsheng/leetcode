// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


class Solution {
public:
    int numTrees(int n) {
        //https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i/2
        //G(n) = F(1, n) + F(2, n) + ... + F(n, n). 
        //G(0)=1, G(1)=1.
        //F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 
        //G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 
        vector<int> res(n+1,0);
        res[0]=res[1]=1;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=i;j++)
                res[i]+=res[j-1]*res[i-j];
        }
        return res[n];
    }
};
