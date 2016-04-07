class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
            return NULL;
        ListNode* a=head;
        ListNode* b=head;
        for(int i=0;i<n;i++)
            a=a->next;
        if(a==NULL)
            return head->next;
        while(true)
        {
            a=a->next;
            if(a==NULL)
            break;
            b=b->next;
        }
        b->next=b->next->next;
        return head;
        
    }
};
