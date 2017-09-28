// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.


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
    ListNode* rotateRight(ListNode* head, int k) {
        //如果k的值比链表的长度大的话怎么处理
        if(!head||!head->next)
            return head;
        int len=getLength(head);
        k=k%len;
        if(k==0)
            return head;
        
        ListNode* newTail=head;
        for(int i=1;i<len-k;i++){
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        ListNode* node=newHead;
        while(node&&node->next){
            node=node->next;
        }
        node->next=head;
        node=head->next;
        while(node!=newTail){
            node=node->next;
        }
        node->next=NULL;
        return newHead;
    }
    
    int getLength(ListNode* head) {
        ListNode *node=head;
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        return count;
    }
};
