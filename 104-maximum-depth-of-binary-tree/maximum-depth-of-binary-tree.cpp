// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        vector<int> res;
        maxDepthTool(res, root, depth);
        int maxDepth = 0;
        for(int n:res) {
            if(n>maxDepth) maxDepth = n;
        }
        return maxDepth;
    }
    
    void maxDepthTool(vector<int> &res, TreeNode* root, int depth) {
        if(!root->left&&!root->right) {
            res.push_back(depth+1);
            return;
        }
        else {
            if(root->left) maxDepthTool(res, root->left, depth+1);
            if(root->right) maxDepthTool(res, root->right, depth+1);
        }
    }    
};
