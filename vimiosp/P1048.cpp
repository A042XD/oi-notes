#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1005,M=105;
int n,m,dp[N],c[N],v[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  m=read(),n=read();
  for(int i=1;i<=n;i++)c[i]=read(),v[i]=read();  
  for(int i=1;i<=n;i++)
    for(int j=m;j>=c[i];j--)
      dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
  printf("%d",dp[m]);
  return 0;
}