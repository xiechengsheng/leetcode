// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //把中间元素挑选出来成为根节点
        //中间节点在左边的是左子树，右边的是右子树
        //这种想法是错的，题目的意思是需要构建完全的平衡的搜索二叉树
        
        //采用递归方式
        return helper(nums,0,nums.size());
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start>=end)
            return NULL;
        int middle = start+(end-start)/2;
        TreeNode *root=new TreeNode(nums[middle]);
        root->left=helper(nums,start,middle);
        root->right=helper(nums,middle+1,end);
        return root;
    }
    
};
