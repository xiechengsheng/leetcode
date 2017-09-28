//
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        //又是可能会改变头结点的题目，所以需要造一个假结点
        ListNode *dummy = new ListNode(-1);
        ListNode *prev=dummy;
        prev->next=head;
        ListNode *curr=head;
        while(curr&&curr->next){
            while(curr&&curr->next&&curr->val==curr->next->val){
                curr=curr->next;
            }
            if(prev->next==curr){
                prev=prev->next;
            }
            //这个else里面其实是在不断地替换prev的next，直到遇到不重复的数为止
            else{
                prev->next=curr->next;
            }
            curr=curr->next;
        }
        //返回的其实是一大串prev构成的链表
        return dummy->next;
    }
};
