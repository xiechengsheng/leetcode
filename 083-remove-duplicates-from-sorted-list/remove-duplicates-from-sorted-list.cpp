//
// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.
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
        ListNode* head_p = head;
        while(head_p && head_p->next) {
            if(head_p->val == head_p->next->val)
                head_p->next = head_p->next->next;
            else
                head_p = head_p->next;
        }
        return head;
    }
};
