#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=50005,M=3e5+5,inf=2147483647/2;
const int dx[6]={0,0,0,1,-1};
const int dy[6]={0,1,-1,0,0};
int n,s,t,sum,cur[N],dep[N],ans,id[105][105];
struct{
  int to[M],nx[M],hd[N],t=1,f[M],c[M];
  void add(int u,int v,int cp,int fl){to[++t]=v,f[t]=fl,c[t]=cp,nx[t]=hd[u],hd[u]=t;}
  void addw(int u,int v,int cp){add(u,v,cp,0),add(v,u,0,0);}
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
  int y=read(),x=read();s=1,t=n=2;
  for(int i=1;i<=y;i++)
    for(int j=1;j<=x;j++)
      id[i][j]=++n;
  for(int i=1;i<=y;i++)
    for(int j=1;j<=x;j++){
      int x=read();sum+=x;
      g.addw(s,id[i][j],x);
    }
  for(int i=1;i<=y;i++)
    for(int j=1;j<=x;j++){
      int x=read();sum+=x;
      g.addw(id[i][j],t,x);
    }
  for(int i=1;i<=y;i++)
    for(int j=1;j<=x;j++){
      int v=read();n++;sum+=v;
      g.addw(s,n,v);
      g.addw(n,id[i][j],inf);
      for(int k=1;k<=4;k++){
        int nx=j+dx[k],ny=i+dy[k];
        if(nx>0&&ny>0&&nx<=x&&ny<=y)g.addw(n,id[ny][nx],inf);
      }
    }
  for(int i=1;i<=y;i++)
    for(int j=1;j<=x;j++){
      int v=read();n++;sum+=v;
      g.addw(n,t,v);
      g.addw(id[i][j],n,inf);
      for(int k=1;k<=4;k++){
        int nx=j+dx[k],ny=i+dy[k];
        if(nx>0&&ny>0&&nx<=x&&ny<=y)g.addw(id[ny][nx],n,inf);
      }
    }
  dinic();printf("%d",sum-ans);
  return 0;
}