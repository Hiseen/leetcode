/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 class Solution {
 public:
     ListNode* reverseKGroup(ListNode* head, int k) {
         if(k<2)return head;
         int count=0;
         ListNode* res=NULL;
         ListNode* temp=head;
         while(temp)
         {
             count++;
             if(count==k)res=temp;
             temp=temp->next;
         }
         if(count<k)return head;
         count=count/k;
         k--;
         temp=head;
         ListNode* tail=NULL;
         ListNode* rec=NULL;
         for(int i=0;i<count;i++)
         {
             ListNode* now=temp;
             ListNode* next=temp->next;
             for(int i=0;i<k;++i)
             {
                 ListNode* temp2=next->next;
                 next->next=now;
                 temp->next=temp2;
                 now=next;
                 next=temp2;
             }
             tail=now;
             if(rec)rec->next=tail;
             rec=temp;
             temp=temp->next;
         }
         return res;
     }
 };