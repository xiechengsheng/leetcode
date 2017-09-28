//
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
//          /  \      \
//         7    2      1
//
//
//
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        vector<bool> res;
        hasPathSumTool(res, root, sum);
        for(bool val:res){
            if(val)
                return true;
        }
        return false;
    }
    
    void hasPathSumTool(vector<bool> &res, TreeNode* root, int value) {
        if(!root->left&&!root->right) {
            bool ans = value==root->val?true:false;
            res.push_back(ans);
            // if(ans)
            //     return;
        }
        else{
            if(root->left)  hasPathSumTool(res, root->left, value-root->val);
            if(root->right)  hasPathSumTool(res, root->right, value-root->val);
        }        
    }
};
