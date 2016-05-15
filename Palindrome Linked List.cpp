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
     bool isPalindrome(ListNode* head) 
     {
         if(!head || !head->next)return true;
         int count=0;
         ListNode* slow=head,*fast=head;
         while(fast->next && fast->next->next)
         {
             slow=slow->next;
             fast=fast->next->next;
         }
         ListNode* temp=fast->next?fast->next:fast;
         GetNext(slow->next,temp);
         while(temp)
         {
             if(head->val !=temp->val)
                 return false;
             head=head->next;
             temp=temp->next;
         }
         return true;
     }
 };