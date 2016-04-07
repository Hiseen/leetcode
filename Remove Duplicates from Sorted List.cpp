class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head)
     {
         int num=head->val;
         ListNode *p=head;
         while(p->next)
         {
             int val=p->next->val;
             if(num==val)
                p->next=p->next->next;
                else
            {
                num=val;
                p=p->next;
            }
         }
     }
     return head;
     
     
        
    }
};