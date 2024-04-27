#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e5+5;
int m,s,t,dp[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  m=read(),s=read(),t=read();int k=m;
  for(int i=1;i<=t;i++)
    if(k>=10)dp[i]=dp[i-1]+60,k-=10;
    else dp[i]=dp[i-1],k+=4;
  for(int i=1;i<=t;i++)dp[i]=max(dp[i],dp[i-1]+17);
  if(dp[t]>s){
    for(int i=1;i<=t;i++)if(dp[i]>=s)printf("Yes\n%d",i),exit(0);
  }
  else printf("No\n%d",dp[t]);
  return 0;
}