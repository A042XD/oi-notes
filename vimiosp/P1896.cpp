#include<iostream>
#include<algorithm>

using namespace std;
const int N=2005;
int st[N],sm[N],tot,n,y;
long long f[15][N][100];

void dfs(int s,int t,int x){
  if(x>=n){st[++tot]=s,sm[tot]=t;return;}
  dfs(s,t,x+1);dfs(s+(1<<x),t+1,x+2);
}

int main(){
  scanf("%d%d",&n,&y);
  dfs(0,0,0);
  for(int i=1;i<=tot;i++)f[1][i][sm[i]]=1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=tot;j++)
      for(int k=1;k<=tot;k++){
        if(st[j]&st[k])continue;
        if((st[j]<<1)&st[k])continue;
        if(st[j]&(st[k]<<1))continue;
        for(int s=y;s>=sm[j];s--)f[i][j][s]+=f[i-1][k][s-sm[j]];
      }
  long long ans=0;
  for(int i=1;i<=tot;i++)ans+=f[n][i][y];
  printf("%lld",ans);
  return 0;
}
