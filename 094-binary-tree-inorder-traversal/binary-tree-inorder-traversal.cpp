// Given a binary tree, return the inorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree [1,null,2,3],
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [1,3,2].
//
//
// Note: Recursive solution is trivial, could you do it iteratively?


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr!=NULL||!s.empty()) {
            while(curr!=NULL) {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        return res;
    }
};
