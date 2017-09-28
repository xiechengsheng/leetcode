// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //广度优先搜索
        vector<vector<int>> results;
        if(!root)
            return results;
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        while(!q.empty()) {
            vector<int> result;
            int size=q.size();
            for(int i=0;i<size;i++) {
                TreeNode* front=q.front();
                result.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                q.pop();
            }
            if((++count)%2==0)
                reverse(result.begin(),result.end());
            results.push_back(result);
        }
        return results;        
    }
};
