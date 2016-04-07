class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(!headA || !headB)
        return NULL;
        ListNode *curA=headA;
        ListNode *curB=headB;
        while(curA && curB)
        {
            if(curA==curB)
                return curA;
            curA=curA->next;
            curB=curB->next;
            if(curA==curB)
                return curA;
            if(curA==NULL)
                curA=headB;
            if(curB==NULL)
                curB=headA;
        }
        return curA;
    }
};