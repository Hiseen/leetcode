class Solution {
public:

    int GetSth(ListNode* node,ListNode* &mid, ListNode* &last,int tarlevel,int startlevel,bool &quit)
    {
        if(node->next)
        {
            int num=GetSth(node->next,mid,last,tarlevel,startlevel+1,quit);
            if(!quit && !mid && num-startlevel==tarlevel%num)
                mid=node;
            return num;
        }
        else
        {
            last=node;
            if(tarlevel%startlevel==0)
                quit=true;
            return startlevel;
        }
    }




    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next || k==0)
            return head;
        ListNode* mid=NULL;
        ListNode* tar=NULL;
        bool q=false;
        GetSth(head,mid,tar,k,1,q);
        if(q)
            return head;
        tar->next=head;
        ListNode* newhead=mid->next;
        mid->next=NULL;
        return newhead;
    }
};