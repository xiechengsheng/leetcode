//
// Given a linked list, swap every two adjacent nodes and return its head.
//
//
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//
//
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        //这里的头结点是改变了位置的，所以最后返回链表头结点的时候是错的，需要新建一个指向原来头结点的结点，
        //然后再在新结点之后两两交换结点
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *curr=head;
        while(curr&&curr->next){
            ListNode *next=curr->next;
            
            curr->next=next->next;
            next->next=curr;

            prev->next=next;
            prev=curr;
            
            curr=curr->next;
            //next=curr->next;
        }
        return dummy->next;
    }
};
