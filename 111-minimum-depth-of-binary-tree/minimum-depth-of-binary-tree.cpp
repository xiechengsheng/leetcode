// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int minimum=INT_MAX;
        int depth=1;
        helper(root,minimum,depth);
        return minimum;
    }
    
    void helper(TreeNode* root, int &minimum, int depth) {
        if(!root->left&&!root->right){
            minimum=min(depth,minimum);
            return;
        }
        else{
            if(root->left) helper(root->left, minimum, depth+1);
            if(root->right) helper(root->right, minimum, depth+1);
        }
    }
};
