#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=55,K=405;
int n,ch,ct,dp[K][K];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  ch=read(),ct=read(),n=read();
  for(int i=1,h,t,v;i<=n;i++){
    h=read(),t=read(),v=read();
    for(int j=ch;j>=h;j--)
      for(int k=ct;k>=t;k--)
        dp[j][k]=max(dp[j][k],dp[j-h][k-t]+v);
  }  
  printf("%d",dp[ch][ct]);
  return 0;
}