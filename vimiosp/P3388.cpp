#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e4+5,M=2e5+5;
int n,m,rt,cnt,dfx,dfn[N],low[N];bool v[N];
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void trj(int x){
  int son=0;dfn[x]=low[x]=++dfx;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!dfn[g.to[i]]){
      trj(g.to[i]),son++,low[x]=min(low[x],low[g.to[i]]);
      if(rt!=x&&low[g.to[i]]>=dfn[x])cnt+=!v[x],v[x]=1;
    }
    else low[x]=min(low[x],dfn[g.to[i]]);
  if(rt==x&&son>=2)cnt+=!v[x],v[x]=1;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    g.add(u,v),g.add(v,u);
  }
  for(int i=1;i<=n;i++)if(!dfn[i])rt=i,trj(i);
  printf("%d\n",cnt);
  for(int i=1;i<=n;i++)if(v[i])printf("%d ",i);
  return 0;
}