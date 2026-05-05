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
    int length_LL(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* rotate_n(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            return head;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        ListNode* temp=slow->next;
        slow->next=nullptr;
        return temp;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        k=k%length_LL(head);
        return rotate_n(head,k);
    }
};