//
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//
// return 1->4->3->2->5->NULL.
//
//
// Note:
// Given m, n satisfy the following condition:
// 1 &le; m &le; n &le; length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||!head->next)
            return head;
        int count=1;
        ListNode *node=head, *prev;
        while(count<m){
            //记录交换位置区间之前的结点
            prev=node;
            node=node->next;
            count++;
        }
        //交换的区间恰好是从头结点开始，那么之前的结点为NULL
        if(m==1)
            prev=NULL;
        
        ListNode *newTail=node;
        while(count<n){
            node=node->next;
            count++;
        }
        ListNode *newHead=node;
        
        //记录交换位置区间之后的结点
        ListNode *next=newHead->next;
        
        //波浪式向前推进交换结点
        while(newTail!=newHead){
            ListNode *temp=newTail->next;
            newTail->next=next;
            next=newTail;
            newTail=temp;
        }
        //交换区的最后一个结点指向前一个结点，完成交换区所有结点的交换
        newHead->next=next;

        if(prev)
            prev->next=newHead;
        else
            head=newHead;
        return head;
    }
};
