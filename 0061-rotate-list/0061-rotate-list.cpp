/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){return head;}
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0){ return head;}
        int split=len-k;
        ListNode* temp=head;
        int count=1;
        while(count<split){
          temp=temp->next;
          count++;
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newhead;
    }
};