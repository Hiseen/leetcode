char* convertToBase7(int num) {
     char* result=(char*)malloc(32);
     if(!num)
     {
         result[0]='0';
         return result;
     }
     int t=abs(num);
     int i=0;
     while(t)
     {
         result[i++]='0'+t%7;
         t/=7;
     }
     if(num<0)
         result[i++]='-';
     int size=i/2;
     i--;
     for(int j=0;j<size;j++)
     {
         char temp=result[j];
         result[j]=result[i-j];
         result[i-j]=temp;
     }
     return result;
     
 }