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
int n,m,dfn[N],low[N],dfx,s[N],tp,tot;
vector<int>ans[N];
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void trj(int x,int f){
  int son=0;dfn[x]=low[x]=++dfx,s[++tp]=x;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(!dfn[g.to[i]]){
      son++,trj(g.to[i],x),low[x]=min(low[x],low[g.to[i]]);
      if(low[g.to[i]]<dfn[x])continue;
      ans[++tot].push_back(x);
      do ans[tot].push_back(s[tp--]);while(s[tp+1]!=g.to[i]);
    }
    else if(x!=f)low[x]=min(low[x],dfn[g.to[i]]);
  if(x==f&&!son)ans[++tot].push_back(x);
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
  for(int i=1;i<=n;i++)if(!dfn[i])trj(i,i);
  printf("%d\n",tot);
  for(int i=1;i<=tot;i++,puts("")){
    printf("%d ",ans[i].size());
    for(int j:ans[i])printf("%d ",j);
  }
  return 0;
}