#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=505,M=3005,inf=1e9;
int n,m,s,t,cur[N],dep[N],ans,p[N],dis[N];
struct{
  int to[M],nx[M],hd[N],t=1,c[M],f[M];
  void add(int u,int v,int cp,int fl){to[++t]=v,c[t]=cp,f[t]=fl,nx[t]=hd[u],hd[u]=t;}
}g;
struct{
  int to[M],nx[M],hd[N],w[M],t=1;
  void add(int u,int v,int k){to[++t]=v,w[t]=k,nx[t]=hd[u],hd[u]=t;}
}tr;
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
  for(int i=1;i<=g.t;i++)g.f[i]=0;ans=0;
  while(bfs()){
    for(int i=1;i<=n;i++)cur[i]=g.hd[i];
    ans+=dfs(s,inf);
  }
}
void bld(int cl,int cr){
  if(cl>=cr)return;
  s=p[cl],t=p[cl+1],dinic();
  tr.add(s,t,ans),tr.add(t,s,ans);
  vector<int>x,y;
  for(int i=cl;i<=cr;i++)
    if(dep[p[i]])x.push_back(p[i]);
    else y.push_back(p[i]);
  for(int i=0;i<x.size();i++)p[cl+i]=x[i];
  for(int i=0;i<y.size();i++)p[cl+x.size()+i]=y[i];
  bld(cl,cl+x.size()-1),bld(cl+x.size(),cr);
}
int qry(int s,int t){
  for(int i=1;i<=n;i++)dis[i]=inf;
  queue<int>q;q.push(s);
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=tr.hd[u];i;i=tr.nx[i])
      if(dis[tr.to[i]]==inf){
        dis[tr.to[i]]=min(dis[u],tr.w[i]);
        if(tr.to[i]==t)return dis[tr.to[i]];
        q.push(tr.to[i]);
      }
  }
  return -1;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read()+1,m=read();
  for(int i=1,u,v,w;i<=m;i++)
    u=read()+1,v=read()+1,w=read(),g.add(u,v,w,0),g.add(v,u,w,0);
  for(int i=1;i<=n;i++)p[i]=i;
  bld(1,n);
  int q=read();
  while(q--){
    int u=1+read(),v=1+read();
    printf("%d\n",qry(u,v));
  }
  return 0;
}