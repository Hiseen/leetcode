class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode(0);
        ListNode* res=result;
        int remainer=0;
        do
        {
            int num=0;
            if(l1 && l2)
            {
                num=l1->val+l2->val+remainer;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                num=l1->val+remainer;
                l1=l1->next;
            }
            else
            {
                num=l2->val+remainer;
                l2=l2->next;
            }
            result->val=num%10;
            remainer=num/10;
            if(l1||l2)
            {
                result->next=new ListNode(0);
                result=result->next;
            }
            else
                break;
        }
        while(1);
        if(remainer)
            result->next=new ListNode(remainer);
        return res;
    }
};