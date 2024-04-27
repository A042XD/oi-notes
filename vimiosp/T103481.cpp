#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e4+5,M=6e5+5;
int n,m,low[N],dfn[N],dfx;
bool b[M];
struct{
  int to[M],nx[M],hd[N],t=1;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void trj(int x,int k){
  low[x]=dfn[x]=++dfx;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!dfn[g.to[i]]){
      trj(g.to[i],i),low[x]=min(low[x],low[g.to[i]]);
      if(low[g.to[i]]>dfn[x])b[i]=b[i^1]=1;
    }
    else if(i!=(k^1))low[x]=min(low[x],dfn[g.to[i]]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  for(int i=1;i<=n;i++)if(!dfn[i])trj(i,0);
  int ans=0;
  for(int i=1;i<=g.t;i+=2)ans+=b[i];
  printf("%d",ans);
  return 0;
}