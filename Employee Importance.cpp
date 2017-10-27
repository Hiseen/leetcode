/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    
    int dfs(unordered_map<int,pair<int,vector<int>*>>& m, int id)
    {
        int res=m[id].first;
        for(auto i:*m[id].second)
            res+=dfs(m,i);
        return res;
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>*>> m;
        for(auto i:employees)
            m[i->id]=make_pair(i->importance,&i->subordinates);
        return dfs(m,id);
        
    }
};