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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(!l1 && !l2)return nullptr;
         if(!l1)return l2;
         if(!l2)return l1;
         ListNode* start=l1->val>l2->val?l2:l1;
         ListNode* res=start;
         ListNode* big=l1==start?l2:l1;
         while(start)
         {
             if(start->next)
             {
                 if(start->next->val>=big->val)
                 {
                     ListNode* temp1=start->next;
                     ListNode* temp2=nullptr;
                     if(big->next)
                         temp2=big->next;
                     start->next=big;
                     big->next=temp1;
                     big=temp2;
                 }
                 else
                 {
                     start=start->next;
                 }
                 if(!big)
                     return res;
             }
             else
             {
                 start->next=big;
                 return res;
             }
             
         }
         return res;
     }
 };