//
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
//
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
//
// Example 1:
//
//     2
//    / \
//   1   3
//
// Binary tree [2,1,3], return true.
//
//
// Example 2:
//
//     1
//    / \
//   2   3
//
// Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
    
    //开始想的就是递归，但是只是想到这样的二叉搜索树的解决方案，错误
    //      3
    //  2        5
    //1             7
    //这么搞是有问题的，不能覆盖所有的二叉搜索树的情况
    
    //还是根据二叉搜索树的性质来解决问题，加入max和min节点，对于左子节点来讲，当前的root节点就是max，对于右子节点来讲，当前的节点就是min
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root)
            return true;
        if((min&&root->val<=min->val) || (max&&root->val>=max->val))
            return false;
        return helper(root->left,min,root)&&helper(root->right,root,max);
    }
    
};
