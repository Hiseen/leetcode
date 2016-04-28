class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* temp=head->next;
        while(odd||even)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
            if(!odd->next || !odd->next->next)break;
        }
        odd->next=temp;
        return head;
    }
};