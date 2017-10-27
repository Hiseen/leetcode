class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        l=len(candies)//2
        l2=len(set(candies))
        return l2 if l2<l else l