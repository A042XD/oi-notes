#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e5+5,M=1e6+5;
int n,m,s,dep[N],st[N][25],dfn[N],dfx;
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
int gt(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs(int x,int f){
  st[dfn[x]=++dfx][0]=f,dep[x]=dep[f]+1;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f)dfs(g.to[i],x);
}
int lca(int u,int v){
  if(u==v)return u;
  if((u=dfn[u])>(v=dfn[v]))swap(u,v);
  int d=__lg(v-++u);
  return gt(st[u][d],st[v-(1<<d)+1][d]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),s=read();
  for(int i=1,u,v;i<n;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  dfs(s,s);
  for(int p=1;p<=__lg(n);p++)
    for(int i=1;i<=n-(1<<p)+1;i++)
      st[i][p]=gt(st[i][p-1],st[i+(1<<(p-1))][p-1]);
  while(m--){
    int u=read(),v=read();
    printf("%d\n",lca(u,v));
  }
  return 0;
}