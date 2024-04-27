#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
char s[105];

signed main(){
  scanf("%s",s+1);
  int k=1;
  while(s[k]!='|')printf("%c",s[k]),k++;k++;
  while(s[k]!='|')k++;k++;
  while(s[k])printf("%c",s[k]),k++;
  return 0;
}