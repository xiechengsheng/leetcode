// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)
            return head;
        //由于可能头结点会被替换，因此需要造一个假结点
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=dummy;
        prev->next=head;
        
        ListNode *dummy2=new ListNode(-1);
        ListNode *prev2=dummy2;
        
        //两个链表，最后拼接起来
        ListNode *node=head;
        while(node) {
            if(node->val<x) {
                prev->next=node;
                prev=node;
            }
            else {
                prev2->next=node;
                prev2=node;
            }
            node=node->next;
        }
        prev2->next=NULL;
        prev->next=dummy2->next;
        return dummy->next;
    }
};
