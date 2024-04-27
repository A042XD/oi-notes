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
const int N=105,M=2e5+5,inf=1e18;
int r,n,m,k,d,a[M],c[N],dp[M],q[M],h=1,t=0;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  r=read();
  while(r--){
    n=read(),m=read(),k=read(),d=read();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        a[j]=read()+1,dp[j]=inf;
      dp[1]=1,h=1,t=0;
      for(int j=2;j<=m;j++){
        while(h<=t&&dp[q[t]]>dp[j-1])
          t--;
        while(h<=t&&q[h]<j-d-1)
          h++;
        q[++t]=j-1;
        dp[j]=dp[q[h]]+a[j];
      }
      c[i]=dp[m];
    }
    int ans=inf;
    for(int i=1;i<=n-k+1;i++){
      int sum=0;
      for(int j=0;j<k;j++){
        sum+=c[i+j];
      }
      ans=min(ans,sum);
    }
    printf("%lld\n",ans);
  }
  return 0;
}