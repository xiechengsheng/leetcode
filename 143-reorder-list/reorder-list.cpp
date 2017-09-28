//
// Given a singly linked list L: L0?L1?…?Ln-1?Ln,
// reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…
//
//
// You must do this in-place without altering the nodes' values.
//
//
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        /*
        if(!head||!head->next)
            return;
        //1.找到链表中点
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next&&fast->next->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *middle=slow->next;
        cout << "middle->val = " << middle->val << endl;

        //2.翻转链表中点后面的部分
        ListNode *boundary=middle;
        ListNode *prev=NULL;

        while(boundary){
            ListNode *temp=boundary->next;
            boundary->next=prev;
            prev=boundary;
            boundary=temp;
        }
        cout << "prev->val = " << prev->val << endl;
        */
        if(!head||!head->next)
            return;
        //1.找到链表中点
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *middle=slow;

        //2.翻转中点后面的半个链表部分，以middle为分界线
        ListNode *boundary=middle;
        ListNode *prev=NULL;

        while(boundary){
            ListNode *temp=boundary->next;
            boundary->next=prev;
            prev=boundary;
            boundary=temp;
        }


        //3.前半个链表和后半个链表依次配对
        ListNode *begin=head;
        while(begin!=middle){

            ListNode *temp1=begin->next, *temp2=prev->next;
            begin->next=prev;
            //这里的情况是如果链表长度为偶数，prev->next将指向temp1，但此时temp1就是prev自身
            //实际的情况是如果链表长度是偶数，进行到这里已经到达链表尾部，因此直接写成prev->next=NULL;

            prev->next=temp1;
            begin=temp1;
            prev=temp2;
        }
        begin->next=NULL;

        return;
    }
};
