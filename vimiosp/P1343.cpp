#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=205,M=4e3+5,inf=1e18;
int n,m,x,dep[N],cur[N],ans;
struct{
  int c[M],f[M],to[M],nx[M],hd[N],t=1;
  void add(int u,int v,int cp,int fl){to[++t]=v,c[t]=cp,f[t]=fl,nx[t]=hd[u],hd[u]=t;}
}g;
bool bfs(){
  for(int i=1;i<=n;i++)dep[i]=0;
  queue<int>q;q.push(1),dep[1]=1;
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=g.hd[u];i;i=g.nx[i])
      if(!dep[g.to[i]]&&g.c[i]>g.f[i])
        dep[g.to[i]]=dep[u]+1,q.push(g.to[i]);
  }
  return dep[n];
}
int dfs(int u,int fl){
  if(u==n||!fl)return fl;
  int rt=0,d;
  for(int&i=cur[u];i;i=g.nx[i])
    if(dep[g.to[i]]==dep[u]+1&&(d=dfs(g.to[i],min(fl-rt,g.c[i]-g.f[i])))){
      rt+=d,g.f[i]+=d,g.f[i^1]-=d;
      if(rt==fl)return rt;
    }
  return rt;
}
void dinic(){
  while(bfs()){
    for(int i=1;i<=n;i++)cur[i]=g.hd[i];
    ans+=dfs(1,inf);
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),x=read();
  for(int i=1,u,v,w;i<=m;i++){
    u=read(),v=read(),w=read();
    g.add(u,v,w,0),g.add(v,u,0,0);
  }
  if(!bfs())puts("Orz Ni Jinan Saint Cow!"),exit(0);
  dinic();printf("%lld %lld",ans,x/ans+(x%ans>0));
  return 0;
}