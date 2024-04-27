#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e5+5,M=4e6+5;
int n,m,low[N],dfn[N],dfx,s[N],tp,tot;
vector<int>ans[N];
struct{
  int to[M],nx[M],hd[N],t=1;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void trj(int x,int k){
  low[x]=dfn[x]=++dfx,s[++tp]=x;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!dfn[g.to[i]])trj(g.to[i],i),low[x]=min(low[x],low[g.to[i]]);
    else if(i!=(k^1))low[x]=min(low[x],dfn[g.to[i]]);
  if(low[x]!=dfn[x])return;
  ++tot;
  do x=s[tp--],ans[tot].push_back(x);while(low[x]!=dfn[x]);
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
  printf("%d\n",tot);
  for(int i=1;i<=tot;i++,puts("")){
    printf("%d ",ans[i].size());
    for(int j:ans[i])printf("%d ",j);
  }
  return 0;
}