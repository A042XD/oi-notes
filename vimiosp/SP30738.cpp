#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e4+5,M=1e5+10;
int n,m,a[N],dp[M];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),dp[0]=1;
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)
    for(int j=1e5+5;j>=a[i];j--)
      dp[j]|=dp[j-a[i]];
  for(int i=1;i<=1e5+5;i++)dp[i]+=dp[i-1];
  while(m--){
    int x=read(),y=read();
    printf("%d\n",dp[y]-dp[x-1]);
  }
  return 0;
}