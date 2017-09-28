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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rec_tree(struct TreeNode* p, int value_sum, int sum)
{
	int tmp_sum = 0, tmp = 0;
	tmp_sum = value_sum + p->val;
	
	if (p->left == NULL && p->right == NULL) {
// 		if (tmp_sum == sum) {
// 			return 1;
// 		} else {
// 			return 0;
// 		}
        return tmp_sum==sum?1:0;
	}
	
	if (p->left != NULL) {
		tmp += rec_tree(p->left, tmp_sum, sum);
	}
	if (tmp > 0) {
	    return 1;
	}
	
	if (p->right != NULL) {
		tmp += rec_tree(p->right, tmp_sum, sum);
	}
	return tmp;
} 
 
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL) {
       return false;
    }
	int value_sum = 0, rec = 0;
	rec = rec_tree(root, value_sum, sum);
	if (rec > 0) {
		return true;
	}
	return false;
}
