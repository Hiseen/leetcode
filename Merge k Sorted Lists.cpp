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
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0)
             return NULL;
         int index=0;
         int size=lists.size();
         while(lists[index]==NULL)
             {
                 index++;
                 if(index==size)
                     return NULL;
             }
         ListNode* result=lists[index];
         ListNode* temp=result;
         index++;
         while(index<size)
         {
             ListNode* temp2=lists[index];
             ListNode* pre=NULL;
             bool isFirst=true;
             while(temp && temp2)
             {
                 if(temp2->val<temp->val)
                 {
                     ListNode* t=temp;
                     temp=temp2;
                     if(pre)pre->next=temp;
                     temp2=temp2->next;
                     temp->next=t;
                     pre=temp;
                     temp=t;
                     if(isFirst)result=pre;
                 }
                 else
                 {
                     pre=temp;
                     temp=temp->next;
                 }
                 isFirst=false;
             }
             if(temp2)
                 pre->next=temp2;
             temp=result;
             index++;
         }
         return result;
     }
 };