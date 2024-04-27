#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>
#define mid ((cl+cr)/2) // Segtree defs
#define inr (l<=cl&&cr<=r)
#define outr (cr<l||r<cl)

using namespace std;
const int N=1e5+5,M=2e5+5;
int t[N*4],l[N*4],a[N],rk[N],fa[N],rt[N],hs[N],dep[N],dfx,dfn[N],sz[N],n,m,r,p;
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void dfs1(int x,int f){
  dep[x]=dep[f]+1,fa[x]=f,sz[x]=1;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f){
      dfs1(g.to[i],x);
      if(sz[g.to[i]]>sz[hs[x]])hs[x]=g.to[i];
      sz[x]+=sz[g.to[i]];
    }
}
void dfs2(int x,int r){
  dfn[x]=++dfx,rk[dfx]=x,rt[x]=r;
  if(!hs[x])return;
  dfs2(hs[x],r);
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=fa[x]&&g.to[i]!=hs[x])
      dfs2(g.to[i],g.to[i]);
}
void psup(int u){t[u]=(t[u*2]+t[u*2+1])%p;}
void mktg(int u,int ln,int x){t[u]+=ln*x,l[u]+=x;}
void bld(int u,int cl,int cr){
  if(cr<=cl)return t[u]=a[rk[cl]]%p,void();
  bld(u*2,cl,mid),bld(u*2+1,mid+1,cr);
  psup(u);
}
void psdn(int u,int cl,int cr){
  mktg(u*2,mid-cl+1,l[u]);
  mktg(u*2+1,cr-mid,l[u]);
  l[u]=0;
}
void chg(int u,int cl,int cr,int l,int r,int x){
  if inr return mktg(u,cr-cl+1,x),void();
  if outr return;
  psdn(u,cl,cr);
  chg(u*2,cl,mid,l,r,x);
  chg(u*2+1,mid+1,cr,l,r,x);
  psup(u);
}
int qry(int u,int cl,int cr,int l,int r){
  if inr return t[u];
  if outr return 0;
  psdn(u,cl,cr);
  return (qry(u*2,cl,mid,l,r)+qry(u*2+1,mid+1,cr,l,r))%p;
}
void updp(int x,int y,int v){
  while(rt[x]!=rt[y]){
    if(dep[rt[x]]<dep[rt[y]])swap(x,y);
    chg(1,1,n,dfn[rt[x]],dfn[x],v),x=fa[rt[x]];
  }
  if(dfn[x]>dfn[y])swap(x,y);
  chg(1,1,n,dfn[x],dfn[y],v);
}
int qryp(int x,int y,int ans=0){
  while(rt[x]!=rt[y]){
    if(dep[rt[x]]<dep[rt[y]])swap(x,y);
    ans=(ans+qry(1,1,n,dfn[rt[x]],dfn[x]))%p,x=fa[rt[x]];
  }
  if(dfn[x]>dfn[y])swap(x,y);
  return (ans+qry(1,1,n,dfn[x],dfn[y]))%p;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),r=read(),p=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1,u,v;i<n;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  dfs1(r,0),dfs2(r,0),bld(1,1,n);
  while(m--){
    int op=read(),x=read(),y,z;
    if(op==1)y=read(),z=read(),updp(x,y,z);
    if(op==2)y=read(),printf("%d\n",qryp(x,y));
    if(op==3)y=read(),chg(1,1,n,dfn[x],dfn[x]+sz[x]-1,y);
    if(op==4)printf("%d\n",qry(1,1,n,dfn[x],dfn[x]+sz[x]-1));
  }
  return 0;
}