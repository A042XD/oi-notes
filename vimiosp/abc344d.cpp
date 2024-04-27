#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=105;
int n,m,cnt[N],dp[N],ln[N][N];
char s[N],t[N][N][15];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  scanf("%s",s+1);m=strlen(s+1),n=read();
  for(int i=1;i<=n;i++){
    cnt[i]=read();
    for(int j=1;j<=cnt[i];j++){
      scanf("%s",t[i][j]+1);ln[i][j]=1;
      while(t[i][j][ln[i][j]])ln[i][j]++;ln[i][j]--;
    }
  }
  memset(dp,0x3f3f3f3f,sizeof(dp));
  dp[0]=0;
  for(int k=1;k<=n;k++)
    for(int i=m;i>=1;i--)
      for(int j=1;j<=cnt[k];j++){
        if(ln[k][j]>i)continue;
        bool f=1;
        for(int l=1;l<=ln[k][j];l++)
          if(s[i-ln[k][j]+l]!=t[k][j][l])f=0;
        if(!f)continue;
        dp[i]=min(dp[i],dp[i-ln[k][j]]+1);
      }
  if(dp[m]==0x3f3f3f3f)puts("-1");
  else printf("%d",dp[m]);
  return 0;
}