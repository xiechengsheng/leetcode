// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//把数组换成链表，重建搜索二叉树，重要的还是找到每个阶段的中点
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* start=head;
        //获取end，end就是NULL
        while(head&&head->next)
            head=head->next;
        ListNode* end = head;
        return helper(start, NULL);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        //结束条件,比数组多一个，start->next==end
        if(start==end)
            return NULL;
        if(start->next==end) {
            TreeNode* root=new TreeNode(start->val);
            return root;
        }

        ListNode *middle = start, *temp=start;
        while(temp!=end&&temp->next!=end&&temp->next->next!=end) {
            temp=temp->next->next;
            middle=middle->next;
        }
        TreeNode* root=new TreeNode(middle->val);
        root->left=helper(start,middle);
        root->right=helper(middle->next,end);
        return root;
    }
};

