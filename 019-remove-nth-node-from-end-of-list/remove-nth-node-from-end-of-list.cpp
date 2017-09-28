// Given a linked list, remove the nth node from the end of list and return its head.
//
//
// For example,
//
//
//    Given linked list: 1->2->3->4->5, and n = 2.
//
//    After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
//
// Note:
// Given n will always be valid.
// Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        // 计数，遍历到列表的位置
        int count = 0;
        
        while(p1) {
            p1 = p1->next;
            //p2 = p2->next;
            ++count;
            if (count == n)
                break;
        }
        if (p1==NULL)
            return head->next;
        
        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode *p = p2->next;
        p2->next = p2->next->next;
        free(p);
        
        return head;
        
    }
};
