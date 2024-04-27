#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int M=1e7+5,N=1e4+5;
int t,m,dp[M];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read(),m=read();
  for(int i=1;i<=m;i++){
    int c=read(),v=read();
    for(int j=c;j<=t;j++)dp[j]=max(dp[j],dp[j-c]+v);
  }  
  printf("%lld",dp[t]);
  return 0;
}