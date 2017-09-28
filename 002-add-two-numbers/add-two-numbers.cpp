// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1=l1,*head2=l2;
        ListNode preHead(-1), *ptr = &preHead;
        //进位
        int carry = 0;
        while(head1||head2) {
            int val1=head1?head1->val:0, val2=head2?head2->val:0;
            int sum = val1 + val2 + carry;
            ptr->next = new ListNode(sum%10);
            ptr = ptr->next;
            carry = sum/10;
            head1=head1&&head1->next?head1->next:NULL;
            head2=head2&&head2->next?head2->next:NULL;
        }
        if(carry) {
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }
        return preHead.next;
            
    }
};
