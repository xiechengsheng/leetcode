//
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//
// For example:
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
//
//
//
// return
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> num;
        pathSumTool(res, root, sum, num);
        return res;
    }
    
    void pathSumTool(vector<vector<int>> &nums, TreeNode* root, int value, vector<int> num) {
        if(!root->left&&!root->right) {
            if(value==root->val){
                num.push_back(root->val);
                nums.push_back(num);
            }
            num.clear();
            return;
        }
        else{
            num.push_back(root->val);
            if(root->left)  pathSumTool(nums, root->left, value-root->val, num);
            if(root->right) pathSumTool(nums, root->right, value-root->val, num);
        }
    }    
};
