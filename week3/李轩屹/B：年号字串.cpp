#include <bits/stdc++.h>
using namespace std;

char str[27] = {0,'A','B','C','D','E','F','G','H','I','J','K'
   			,'L','M','N','O','P','Q','R','S','T','U','V',
   			'W','X','Y','Z'};

int main() {
   int num;
   string ans = "";
   scanf("%d", &num);
   while(num) {
   	ans += str[num % 26];
   	num /= 26;
   }
   for (int i = ans.size() - 1; i >= 0; i--) {
   	cout << ans[i];
   }
   return 0;
}

