class Solution {
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        if(head1->val <= head2->val){
            head1->next=merge(head1->next,head2);
            return head1;
        }
        else{
            head2->next=merge(head1,head2->next);
            return head2;
        }
        // return nullptr;
    }
    ListNode* get_middle(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* sp=head;
        ListNode* fp=head;
        ListNode* sp_prev=nullptr;
        while(fp && fp->next){
            sp_prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        sp_prev->next=nullptr;
        return sp;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || head->next==nullptr){
            return head;
        }
        ListNode* head1=head;
        ListNode* head2=get_middle(head);
        return merge(sortList(head1),sortList(head2));
    }
};