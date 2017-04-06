digits16='1234567890ABCDEFabcdef'
 class Solution(object):
     def validIPAddress(self, IP):
         """
         :type IP: str
         :rtype: str
         """
         if '.' in IP:
             temp=IP.split('.')
             if len(temp)==4:
                 ok=True
                 for i in temp:
                     if len(i)==0 or len(i)>3 or (len(i)>1 and i[0]=='0') or not i.isdigit() or int(i)>=256:
                         ok=False
                         break
                 if ok:
                     return 'IPv4'
         if ':' in IP:
             temp=IP.split(':')
             if len(temp)==8:
                 for i in temp:
                     ok=True
                     if len(i)>4 or len(i)==0 or any(not j in digits16 for j in i):
                         ok=False
                         break
                 if ok:
                     return 'IPv6'
         return 'Neither'