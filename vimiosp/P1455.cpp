#include <iostream>
#include <algorithm>

using namespace std;const int N=1e4+5;
int n,m,w,t,dp[N],fa[N],c[N],d[N],mv[N],mc[N];bool v[N];
int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))fa[x]=y,c[y]+=c[x],d[y]+=d[x];}

int main(){
  scanf("%d%d%d",&n,&m,&w);
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&d[i]);
  for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),mrg(u,v);
  for(int i=1;i<=n;i++)if(!v[fd(i)])mv[++t]=d[fd(i)],mc[t]=c[fd(i)],v[fd(i)]=1; 
  for(int i=1;i<=t;i++)for(int j=w;j>=mc[i];j--)dp[j]=max(dp[j],dp[j-mc[i]]+mv[i]);
  printf("%d",dp[w]);
  return 0;
}
