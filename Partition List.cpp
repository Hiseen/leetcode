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
     ListNode* partition(ListNode* head, int x) {
         if(!head || !head->next)return head;
         ListNode* t=head;
         ListNode* start=NULL;
         bool flag=false;
         if(t->val>=x)
             flag=true;
         else
         {
             while(t)
             if(t->val>=x)
                 break;
             else
             {
                 start=t;
                 t=t->next;
             }
         }
         if(!t)return head;
         ListNode* pre=t;
         ListNode* now=t->next;
         while(now)
         {
             if(now && now->val<x)
             {
                 if(flag)
                 {
                     start=now;
                     ListNode* temp=now->next;
                     now->next=head;
                     pre->next=temp;
                     now=temp;
                     head=start;
                     flag=false;
                 }
                 else
                 {
                     ListNode* temp=now->next;
                     ListNode* temp2=start->next;
                     start->next=now;
                     now->next=temp2;
                     pre->next=temp;
                     now=temp;
                     start=start->next;
                 }
             }
             else
             {
                 pre=now;
                 now=now->next;
             }
         }
         return head;
     }
 };