/**
  * // This is the interface that allows for creating nested lists.
  * // You should not implement it, or speculate about its implementation
  * class NestedInteger {
  *   public:
  *     // Constructor initializes an empty nested list.
  *     NestedInteger();
  *
  *     // Constructor initializes a single integer.
  *     NestedInteger(int value);
  *
  *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
  *     bool isInteger() const;
  *
  *     // Return the single integer that this NestedInteger holds, if it holds a single integer
  *     // The result is undefined if this NestedInteger holds a nested list
  *     int getInteger() const;
  *
  *     // Set this NestedInteger to hold a single integer.
  *     void setInteger(int value);
  *
  *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  *     void add(const NestedInteger &ni);
  *
  *     // Return the nested list that this NestedInteger holds, if it holds a nested list
  *     // The result is undefined if this NestedInteger holds a single integer
  *     const vector<NestedInteger> &getList() const;
  * };
  */
 class Solution {
 public:
     NestedInteger RecursiveFunc(vector<string> v,int& start,int end)
     {
         NestedInteger res;
         while(start<end)
         {
             if(v[start]=="[")
                 res.add(RecursiveFunc(v,++start,end));
             else if(v[start]=="]")
             {
                 start++;
                 return res;
             }
             else
                 res.add(NestedInteger(stoi(v[start++])));
         }
         return res;
     }
 
     NestedInteger deserialize(string s) {
         if(s[0]=='[')
         {
             vector<string> stack;
             int start=1,end=s.size()-1;
             while(start<end)
             {
                 char ch=s[start];
                 if(ch=='-' || (ch>='0' && ch<='9'))
                 {
                     string temp(1,s[start++]);
                     while(start<end && (s[start]>='0' && s[start]<='9'))
                         temp.append(1,s[start++]);
                     stack.push_back(temp);
                 }
                 else
                 {
                     if(ch=='[')
                         stack.push_back(string("["));
                     else if(ch==']')
                         stack.push_back(string("]"));
                     start++;
                 }
             }
             int s2=0;
             return RecursiveFunc(stack,s2,stack.size());
         }
         else
             return NestedInteger(stoi(s));
    
     }
 };