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
     ListNode* Reverse(ListNode* head)
     {
         ListNode* now=head;
         ListNode* next=head->next;
         while(next)
         {
             ListNode* temp=next->next;
             next->next=now;
             head->next=temp;
             now=next;
             next=temp;
         }
         return now;
     }
     void reorderList(ListNode* head) {
         if(!head)return;
         if(head && head->next && !head->next->next)return;
         int count=0;
         ListNode* temp=head;
         while(temp)
         {
             temp=temp->next;
             count++;
         }
         int copy=count;
         temp=head;
         count/=2;
         ListNode* pre=NULL;
         while(count)
         {
             pre=temp;
             temp=temp->next;
             count--;
         }
         if(!(copy%2))
             pre->next=NULL;
         temp=Reverse(temp);
         
         while(temp)
         {
             ListNode* temp2=head->next;
             ListNode* temp3=temp->next;
             head->next=temp;
             temp->next=temp2;
             head=temp2;
             temp=temp3;
         }
     }
 };