class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        vector<pair<RandomListNode*,RandomListNode*>> records;
        if(!head)return NULL;
        RandomListNode* temp=new RandomListNode(head->label);
        RandomListNode* result=temp;
        while(head)
        {
            if(head->random)
            {
                int size=records.size();
                RandomListNode* flag=NULL;
                for(int i=0;i<size;++i)
                {
                    if(records[i].first==head->random)
                    {
                        flag=records[i].second;
                        break;
                    }
                }
                if(!flag)
                {
                    temp->random=new RandomListNode(head->random->label);
                    records.push_back(pair<RandomListNode*,RandomListNode*>(head->random,temp->random));
                }
                else
                {
                    temp->random=flag;
                }
            }
            if(head->next)
            {
                int size=records.size();
                RandomListNode* flag=NULL;
                for(int i=0;i<size;++i)
                {
                    if(records[i].first==head->next)
                    {
                        flag=records[i].second;
                        break;
                    }
                }
                if(!flag)
                {
                    temp->next=new RandomListNode(head->next->label);
                    records.push_back(pair<RandomListNode*,RandomListNode*>(head->next,temp->next));
                }
                else
                    temp->next=flag;
            }
            head=head->next;
            temp=temp->next;
        }
        return result;
        
    }
};