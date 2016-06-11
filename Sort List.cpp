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
 
     ListNode* merge(ListNode* first,ListNode* second)
     {
         if(!first)return second;
         if(!second)return first;
         bool flag=true;
         ListNode* result=first->val>second->val?second:first;
         if(result==first)
             first=first->next;
         else
             second=second->next;
         ListNode* pre=result;
         while(first && second)
         {
             if(first->val<second->val)
             {
                 pre->next=first;
                 first=first->next;
             }
             else
             {
                 pre->next=second;
                 second=second->next;
             }
             pre=pre->next;
         }
         if(!first)
             pre->next=second;
         else
             pre->next=first;
         return result;
     }
 
     ListNode* sortList(ListNode* head) 
     {
         if(!head || !head->next)return head;
         ListNode* fast=head;
         ListNode* slow=head;
         while(fast->next && fast->next->next)
         {
             fast=fast->next->next;
             slow=slow->next;
         }
         fast=slow;
         slow=slow->next;
         fast->next=NULL;
         slow=sortList(slow);
         head=sortList(head);
         return merge(head,slow);
     }
 };