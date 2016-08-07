bool isNumber(char* s) {
     int index=0;
     int size=strlen(s);
     bool find_dot=false;
     bool find_e=false;
     bool find_num=false;
     bool find_blank=false;
     bool find_symbol=false;
     while(s[index]==' ')
         ++index;
     if(index==size)
         return false;
     while(index<size)
     {
         char temp=s[index];
         if (find_blank && temp!=' ')
             return false;
         if(temp=='-' || temp=='+')
         {
             if(find_symbol)
                 return false;
             else if(find_num)
                 return false;
             else if(find_dot)
                 return false;
             else
                 find_symbol=true;
         }
         else if(temp=='.')
         {
             
             if(find_e)
                 return false;
             else if(find_dot)
                 return false;
             else
                 find_dot=true;
         }
         else if(temp=='e')
         {
             if(!find_num)
                 return false;
             else if(find_e)
                 return false;
             else
                 {
                     find_e=true;
                     find_num=false;
                     find_dot=false;
                     find_symbol=false;
                 }
         }
         else if(temp>='0' && temp<='9')
             find_num=true;
         else if(temp==' ')
             find_blank=true;
         else
             return false;
         ++index;
     }
     return find_num;
 }