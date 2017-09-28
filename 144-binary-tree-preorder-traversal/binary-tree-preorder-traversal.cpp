// Given a binary tree, return the preorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr!=NULL||!s.empty()) {
            if(curr) {
                res.push_back(curr->val);
                s.push(curr);
                curr=curr->left;
            }
            else {
                curr=s.top();
                s.pop();
                curr=curr->right;
            } 
        }
        return res;
    }
};
