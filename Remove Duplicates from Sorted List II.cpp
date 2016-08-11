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
     ListNode* deleteDuplicates(ListNode* head) {
         if(!head)return head;
         ListNode* pre=head;
         ListNode* next=head->next;
         bool changehead=true;
         while(next)
         {
             if(pre->val==next->val)
             {
                 int val=next->val;
                 while(next)
                 {
                     next=next->next;
                     if(!next || next->val!=val)
                         break;
                 }
                 if(changehead)
                     head=next;
                 if(!next)return head;
                 else
                 {
                     pre=next;
                     next=next->next;
                 }
             }
             else if(next->next && next->next->val==next->val)
             {
                 int val=next->val;
                 while(next)
                 {
                     next=next->next;
                     if(!next || next->val!=val)
                         break;
                 }
                 pre->next=next;
                 changehead=false;
             }
             else
             {
                 pre=next;
                 next=next->next;
                 changehead=false;
             }
             
         }
         return head;
     }
 };