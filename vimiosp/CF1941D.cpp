#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1005;
int dp[N][N],n,t,m,x;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read(),x=read();
    dp[0][x]=1;
    for(int i=1;i<=m;i++){
      char op;int x;
      cin>>x>>op;
      for(int j=1;j<=n;j++){
        if(op=='0'||op=='?')dp[i][(j+x-1)%n+1]|=dp[i-1][j];
        if(op=='1'||op=='?')dp[i][(j-x-1+n)%n+1]|=dp[i-1][j];
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=dp[m][i];
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)if(dp[m][i])printf("%d ",i);
    puts("");
    for(int i=0;i<=m;i++)
      for(int j=1;j<=n;j++)
        dp[i][j]=0;
  }
  return 0;
}