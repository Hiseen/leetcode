class Solution {
public:
    ListNode* GetNext(ListNode* node,ListNode* &last)
    {
        if(node->next)
        {
            ListNode* temp=GetNext(node->next,last);
            node->next=NULL;
            temp->next=node;
        }
        else
        {
            last=node;
        }
        return node;
    }


    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* last=NULL;
        GetNext(head,last);
        return last;
    }
};