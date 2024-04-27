#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>
#define int long long // Data type

using namespace std;
const int N=1e6+5;
int n,dp[N],p=1e9;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),dp[0]=1;
  for(int i=0;i<=21;i++)
    for(int j=(1<<i);j<=n;j++)
      dp[j]=(dp[j]+dp[j-(1<<i)])%p;
  printf("%lld",dp[n]);
  return 0;
}