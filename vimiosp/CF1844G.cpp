#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=1e5+5;
int n,d[N],dfx,dfn[N],dep[N],st[N][20],r[N],x[N],ct[N*2],ans[N];
struct{
  int to[N*2],nx[N*2],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
int gt(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs(int x,int f){
  st[dfn[x]=++dfx][0]=f,dep[x]=dep[f]+1;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f)dfs(g.to[i],x),ct[g.to[i]]=(i+1)/2;
}
int lca(int u,int v){
  if(u==v)return u;
  if((u=dfn[u])>(v=dfn[v]))swap(u,v);
  int d=__lg(v-u++);
  return gt(st[u][d],st[v-(1<<d)+1][d]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1,u,v;i<n;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  for(int i=1;i<n;i++)d[i]=read();  
  dfs(1,0);
  for(int p=1;p<=__lg(n);p++)
    for(int i=1;i<=n-(1<<p)+1;i++)
      st[i][p]=gt(st[i][p-1],st[i+(1<<p-1)][p-1]);
  for(int i=1;i<n;i++)r[i]=lca(i,i+1);
  for(int k=0;k<60;k++){
    int m=(1ll<<k)-1;
    for(int i=1;i<n;i++){
      int tmp=(d[i]&m)+(x[r[i]]<<1);
      x[i+1]=(tmp+m+1-x[i])&m;
    }
  }
  for(int i=2;i<=n;i++){
    int f=st[dfn[i]][0];
    if(x[i]<=x[f])puts("-1"),exit(0);
    ans[ct[i]]=x[i]-x[f];
  }
  for(int i=1;i<n;i++)
    if(x[i]+x[i+1]-2*x[r[i]]!=d[i])
      puts("-1"),exit(0);
  for(int i=1;i<n;i++)
    cout<<ans[i]<<"\n";
  return 0;
}