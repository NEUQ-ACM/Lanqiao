#include <bits/stdc++.h>
using namespace std;
char s[105];
int pos = 0, len;
int f() 
{
    int Now_sum = 0, Max_sum = 0;
     while(pos < len) 
	 {
         if(s[pos] == '(') 
		 {  
             pos++;
             Now_sum += f();
         } 
         else if(s[pos] == 'x') 
		 {
             Now_sum ++;
         }
         else if(s[pos] == ')') 
		 { 
             pos ++;
             break;
         }
         else if(s[pos] == '|') 
		 {   
             pos++;
             Max_sum = max(Max_sum, Now_sum);  
             Now_sum = 0;  
         }
     }
     Max_sum = max(Max_sum, Now_sum);
     return Max_sum;
} 
int main() 
{
     scanf("%s", s);
     len = strlen(s);
     int Ans = f();
     printf("%d\n", Ans);
     return 0;
}
