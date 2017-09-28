//
// Given two binary trees, write a function to check if they are equal or not.
//
//
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 使用递归方式遍历一棵树
        TreeNode *p_ptr = p, *q_ptr = q;
        if(p_ptr == NULL && q_ptr == NULL)
            return true;
        else {
            if(p_ptr == NULL && q_ptr != NULL || p_ptr != NULL && q_ptr == NULL || p_ptr->val != q_ptr->val)
                return false;
            else
                return (isSameTree(p_ptr->left, q_ptr->left) && isSameTree(p_ptr->right, q_ptr->right));
        }
    }
};
