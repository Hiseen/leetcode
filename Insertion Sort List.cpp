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
     ListNode* insertionSortList(ListNode* head) {
         if(!head || !head->next)return head;
         ListNode* first=head;
         ListNode* result=head;
         ListNode* remain=head->next;
         while(remain)
         {
             if(remain->val>first->val)
             {
                 first->next=remain;
                 first=first->next;
                 remain=remain->next;
             }
             else if(remain->val<result->val)
             {
                 first->next=NULL;
                 ListNode* temp=remain;
                 remain=remain->next;
                 temp->next=result;
                 result=temp;
             }
             else if(remain->val==first->val)
             {
                 first->next=remain;
                 remain=remain->next;
                 first=first->next;
             }
             else
             {
                 first->next=NULL;
                 ListNode* tail=first;
                 first=result;
                 while(first->next && remain->val>first->next->val)
                     first=first->next;
                 ListNode* temp=first->next;
                 first->next=remain;
                 remain=remain->next;
                 first->next->next=temp;
                 first=tail;
             }
         }
         return result;
     }
 };