#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;
const int N=1e4+5,M=105,K=1e7+5,inf=2e9;
int n,m,rt,sum,cnt,ds[N],qs[N],sz[N],w[N],dis[N];
bool v[N],tf[K],ret[M];
queue<int>q;
struct{
  int to[N*2],nx[N*2],w[N*2],hd[N],t;
  void add(int u,int v,int k){to[++t]=v,nx[t]=hd[u],hd[u]=t,w[t]=k;}
}g;
void ctd(int x,int f){
  sz[x]=1,w[x]=0;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f&&!v[g.to[i]]){
      ctd(g.to[i],x);
      w[x]=max(w[x],sz[g.to[i]]),sz[x]+=sz[g.to[i]];
    }
  w[x]=max(w[x],sum-sz[x]);
  if(w[x]<w[rt])rt=x;
}
void gd(int x,int f){
  ds[++cnt]=dis[x];
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!v[g.to[i]]&&g.to[i]!=f)
      dis[g.to[i]]=dis[x]+g.w[i],gd(g.to[i],x);
}
void dfz(int x,int f){
  q.push(0),tf[0]=v[x]=1;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!v[g.to[i]]&&g.to[i]!=f){
      dis[g.to[i]]=g.w[i],gd(g.to[i],x);
      for(int j=1;j<=cnt;j++)
        for(int k=1;k<=m;k++)if(ds[j]<=qs[k])ret[k]|=tf[qs[k]-ds[j]];
      for(int j=1;j<=cnt;j++)if(ds[j]<=K-5)q.push(ds[j]),tf[ds[j]]=1;
      cnt=0;
    }
  while(q.size())tf[q.front()]=0,q.pop();
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!v[g.to[i]]&&g.to[i]!=f)
      sum=sz[g.to[i]],w[rt=0]=inf,ctd(g.to[i],x),dfz(rt,x);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),g.add(u,v,w),g.add(v,u,w);
  for(int i=1;i<=m;i++)qs[i]=read();
  sum=n,w[rt=0]=inf,ctd(1,-1),dfz(rt,-1);
  for(int i=1;i<=m;i++)puts(ret[i]?"AYE":"NAY");
  return 0;
}