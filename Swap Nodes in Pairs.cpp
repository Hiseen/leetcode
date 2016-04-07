class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre2=NULL,*pre=NULL,*now=head,*next=NULL,*result=head;
        while(now && now->next)
        {
            pre=now;
            now=now->next;
            next=now->next;
            now->next=pre;
            pre->next=next;
            if(pre2)pre2->next=now;
            if(result==head)result=now;
            now=next;
            pre2=pre;
        }
        return result;
        
    }
};