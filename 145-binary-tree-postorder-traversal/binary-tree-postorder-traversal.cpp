// Given a binary tree, return the postorder traversal of its nodes' values.
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
// return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* curr;
        while(!s.empty()) {
            curr=s.top();
            s.pop();
            res.insert(res.begin(), curr->val);
            if (curr->left)
                s.push(curr->left);
            if (curr->right)
                s.push(curr->right);
        }
        return res;        
    }
};
