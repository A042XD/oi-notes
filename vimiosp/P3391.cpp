#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int N=1e5+5;
int n,m,tot,l[N],r[N],rd[N],sz[N],w[N],rt;
bool f[N];
void psup(int u){sz[u]=1+sz[l[u]]+sz[r[u]];}
int crt(int v){return rd[++tot]=rand(),sz[tot]=1,w[tot]=v,tot;}
void psdn(int u){
  if(!f[u])return;
  swap(l[u],r[u]);
  f[l[u]]^=1,f[r[u]]^=1,f[u]=0;
}
void spt(int p,int v,int&x,int&y){
  if(!p)return x=y=0,void();
  if(f[p])psdn(p);
  if(sz[l[p]]+1<v)spt(r[p],v-sz[l[p]]-1,r[x=p],y);
  else spt(l[p],v,x,l[y=p]);
  psup(p);
}
int mrg(int x,int y){
  if(!x||!y)return x+y;
  if(rd[x]<=rd[y])return psdn(x),r[x]=mrg(r[x],y),psup(x),x;
  return psdn(y),l[y]=mrg(x,l[y]),psup(y),y;
}
void ins(int v,int x=0,int y=0){spt(rt,v,x,y),rt=mrg(mrg(x,crt(v)),y);}
void prt(int u){
  if(!u)return;
  if(f[u])psdn(u);
  prt(l[u]);
  printf("%d ",w[u]);
  prt(r[u]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)ins(i);
  for(int i=1;i<=m;i++){
    int l=read(),r=read(),x,y,z;
    spt(rt,l,x,z);
    spt(z,r-l+2,z,y);
    f[z]^=1;
    rt=mrg(mrg(x,z),y);
  }
  prt(rt);
  return 0;
}