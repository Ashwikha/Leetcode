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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* next;
        ListNode* temp=head;
        ListNode*slow=head;
        int len=0;
        
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n){
            return head->next;
        }
        int d=len-n;
        int count=1;
        
        while(count<d){
            count++;
            slow=slow->next;
        }
       
        slow->next=slow->next->next;
        
        return head;
    }
};