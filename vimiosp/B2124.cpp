#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

signed main(){
  char s[105];
  scanf("%s",s);
  bool f=0;
  int l=strlen(s);
  for(int i=0;s[i];i++)
    if(s[i]!=s[l-i-1])f=1;
  if(f)puts("no");
  else puts("yes"); 
  return 0;
}