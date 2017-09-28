// Implement int sqrt(int x).
//
// Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int x) {
        //牛顿法，秒解，先取的x0=x
        long root=x;
        while(root*root>x){
            root=(root+x/root)/2;
        }
        return root;
    }
};
