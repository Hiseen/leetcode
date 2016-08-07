
 class RandomizedSet(object):
 
     def __init__(self):
         """
         Initialize your data structure here.
         """
         self.count=0
         self.count_now=0
         self.data=set()
         
 
     def insert(self, val):
         """
         Inserts a value to the set. Returns true if the set did not already contain the specified element.
         :type val: int
         :rtype: bool
         """
         if val in self.data:
             return False
         else:
             self.data.add(val)
             self.count+=1
             return True
         
 
     def remove(self, val):
         """
         Removes a value from the set. Returns true if the set contained the specified element.
         :type val: int
         :rtype: bool
         """
         if val in self.data:
             self.data.remove(val)
             self.count-=1
             return True
         else:
             return False
             
 
     def getRandom(self):
         """
         Get a random element from the set.
         :rtype: int
         """
         index=self.count_now if self.count_now<self.count else 0
         self.count_now+=1
         return list(self.data)[index]
 
 
 # Your RandomizedSet object will be instantiated and called as such:
 # obj = RandomizedSet()
 # param_1 = obj.insert(val)
 # param_2 = obj.remove(val)
 # param_3 = obj.getRandom()