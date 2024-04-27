#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1005;
int t,n,q,l2[N],dep[N],fa[N][30];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
struct{
  int t,to[N*2],nx[N*2],hd[N];
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void dfs(int x,int f){
  dep[x]=dep[f]+1,fa[x][0]=f;
  for(int k=1;k<=l2[dep[x]]+1;k++)
    fa[x][k]=fa[fa[x][k-1]][k-1];
  for(int i=g.hd[x];i;i=g.nx[i])
    if(f!=g.to[i])dfs(g.to[i],x);
}
int lca(int x,int y){
  if(dep[x]<dep[y])swap(x,y);
  while(dep[x]>dep[y])x=fa[x][l2[dep[x]-dep[y]]];
  if(x==y)return x;
  for(int k=l2[dep[x]]+1;k>=0;k--)
    if(fa[x][k]!=fa[y][k])x=fa[x][k],y=fa[y][k];
  return fa[x][0];
}

signed main(){
  t=read();int cnt=1;
  for(int i=2;i<=1000;i++)l2[i]=l2[i/2]+1;
  while(t--){
    n=read();
    for(int i=1,m;i<=n;i++){
      m=read();
      for(int v;m--;)g.add(i,v=read()),g.add(v,i);
    }
    dfs(1,0);
    q=read();printf("Case %d:\n",cnt++);
    for(int x,y;q--;)
      x=read(),y=read(),printf("%d\n",lca(x,y));

    // Clear
    g.t=0;
    for(int i=1;i<=n;i++)g.hd[i]=dep[i]=0;
    for(int i=1;i<=n;i++)
      for(int k=0;k<=14;k++)fa[i][k]=0;
  }
  return 0;
}