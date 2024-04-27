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
const int N=205,M=1e4+5,inf=1e9;
int n,m,s,t,cur[N],dep[N],ans;
struct{
  int to[M],nx[M],hd[N],t=1,c[M],f[M];
  void add(int u,int v,int cp,int fl){to[++t]=v,nx[t]=hd[u],c[t]=cp,f[t]=fl,hd[u]=t;}
}g;
bool bfs(){
  for(int i=1;i<=n;i++)dep[i]=0;
  queue<int>q;q.push(s),dep[s]=1;
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=g.hd[u];i;i=g.nx[i])
      if(!dep[g.to[i]]&&g.c[i]>g.f[i])
        dep[g.to[i]]=dep[u]+1,q.push(g.to[i]);
  }
  return dep[t];
}
int dfs(int x,int fl){
  if(x==t||!fl)return fl;
  int rt=0,d;
  for(int&i=cur[x];i;i=g.nx[i])
    if(dep[g.to[i]]==dep[x]+1&&(d=dfs(g.to[i],min(fl-rt,g.c[i]-g.f[i])))){
      rt+=d,g.f[i]+=d,g.f[i^1]-=d;
      if(rt==fl)return rt;
    }
  return rt;
}
void dinic(){
  while(bfs()){
    for(int i=1;i<=n;i++)cur[i]=g.hd[i];
    ans+=dfs(s,inf);
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),s=read()+n,t=read();
  for(int i=1;i<=n;i++)g.add(i,i+n,1,0),g.add(i+n,i,0,0);
  for(int i=1,u,v,w;i<=m;i++){
    u=read(),v=read();
    g.add(u+n,v,inf,0);
    g.add(v,u+n,0,0);
    g.add(v+n,u,inf,0);
    g.add(u,v+n,0,0);
  }
  n=2*n;
  dinic();printf("%lld",ans);
  return 0;
}