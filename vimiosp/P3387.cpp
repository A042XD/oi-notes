#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e4+5,M=1e5+5;
int n,m,a[N],s[N],tp,dp[N],w[N],tot,low[N],in[N],dfn[N],dfx,be[N];
bool v[N];
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g,ga;
void trj(int x){
  low[x]=dfn[x]=++dfx;s[++tp]=x,v[x]=1;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!dfn[g.to[i]])trj(g.to[i]),low[x]=min(low[x],low[g.to[i]]);
    else if(v[g.to[i]])low[x]=min(low[x],dfn[g.to[i]]);
  if(low[x]!=dfn[x])return;
  tot++;
  do x=s[tp--],v[x]=0,w[tot]+=a[x],be[x]=tot; while(low[x]!=dfn[x]);
}
void topo(){
  queue<int>q;
  for(int i=1;i<=tot;i++){
    if(!in[i])q.push(i);
    dp[i]=w[i];
  }
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=ga.hd[u];i;i=ga.nx[i]){
      dp[ga.to[i]]=max(dp[ga.to[i]],dp[u]+w[ga.to[i]]);
      if(!--in[ga.to[i]])q.push(ga.to[i]);
    }
  }
  int ans=0;
  for(int i=1;i<=tot;i++)ans=max(ans,dp[i]);
  printf("%d",ans);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g.add(u,v);
  for(int i=1;i<=n;i++)if(!dfn[i])trj(i);
  for(int i=1;i<=n;i++)
    for(int j=g.hd[i];j;j=g.nx[j])
      if(be[i]!=be[g.to[j]])ga.add(be[i],be[g.to[j]]),in[be[g.to[j]]]++;
  topo();
  return 0;
}