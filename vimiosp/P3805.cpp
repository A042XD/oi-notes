#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2.2e7+5;
int p[N],m,ans;
char s[N],t[N];

signed main(){
  scanf("%s",s+1);
  t[0]='@',t[m=1]='#';
  for(int i=1;s[i];i++)t[++m]=s[i],t[++m]='#';t[++m]='!';
  for(int i=1,r=0,d=0;t[i];i++){
    if(i>r)p[i]=1;
    else p[i]=min(p[2*d-i],r-i+1);
    while(t[i+p[i]]==t[i-p[i]])p[i]++;
    if(i+p[i]-1>r)r=i+p[i]-1,d=i;
    ans=max(ans,p[i]-1);
  }
  printf("%d",ans);
  return 0;
}