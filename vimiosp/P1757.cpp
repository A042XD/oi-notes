#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1005,K=105;
int n,m,w[N],v[N],cnt[K],t[K][N],dp[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  m=read(),n=read();
  for(int i=1,x;i<=n;i++)
    w[i]=read(),v[i]=read(),x=read(),t[x][++cnt[x]]=i;
  for(int i=1;i<=100;i++)
    for(int j=m;j>=1;j--)
      for(int k=1;k<=cnt[i];k++)
        if(w[t[i][k]]<=j)
          dp[j]=max(dp[j],dp[j-w[t[i][k]]]+v[t[i][k]]);
  printf("%d",dp[m]);  
  return 0;
}