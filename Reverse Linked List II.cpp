class Solution {
public:


    void Reverse(ListNode *pre,ListNode *f,ListNode *e,int num)
    {
        ListNode* now=f;
        ListNode* next=f->next;
        f->next=e->next;
        while(num)
        {
         ListNode* r=next->next;
         next->next=now;
         now=next;
         next=r;
         num--;
        }
        if(pre)
            pre->next=e;
            
        
    }




    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count=1;
        ListNode* temp=head;
        ListNode* f=nullptr;
        ListNode* pre=nullptr;
        while(temp)
        {
            if(count==m-1)
                pre=temp;
            if(count==m)
                f=temp;
            if(count==n)
            {
                if(m==n)
                    return head;
                else
                {
                    if(pre)
                    {
                        Reverse(pre,f,temp,n-m);
                        return head;
                    }
                    else
                    {
                        Reverse(nullptr,f,temp,n-m);
                        return temp;
                    }
                }
            }
            temp=temp->next;
            count+=1;
            
        }
    }
};