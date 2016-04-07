class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* next=head;
        while(cur)
        {
            next=cur->next;
            if(next==head)return true;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return false;
    }
};