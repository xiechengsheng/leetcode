// Given numRows, generate the first numRows of Pascal's triangle.
//
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int i = 0; i < numRows; i++) {
            if(i == 0) result[i].push_back(1);
            else if(i == 1) 
            {
                result[i].push_back(1);
                result[i].push_back(1);
            }
            else {
                result[i].push_back(1);
                // 上面一行的两个数加起来就是
                for (int j = 1; j < i; j++) {
                    result[i].push_back(result[i-1][j-1]+result[i-1][j]);
                }
                result[i].push_back(1);                
            }
        }   
        
        return result;
    }
};
