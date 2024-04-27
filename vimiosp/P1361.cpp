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
const int N=3e3+5,M=3e5+5,inf=1e17;
int n,s,t,sum,cur[N],dep[N],ans,a[N],b[N];
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
  s=1,t=n=2;
  int x=read();
  for(int i=1;i<=x;i++)a[i]=read(),sum+=a[i];
  for(int i=1;i<=x;i++)b[i]=read(),sum+=b[i];
  for(int i=1;i<=x;i++)g.addw(1,++n,a[i]),g.addw(i+2,2,b[i]);
  int k=read();
  for(int i=1;i<=k;i++){
    int m=read(),r1=++n,r2=++n;
    for(int j=1;j<=m;j++)a[j]=read()+2;
    int t1=read(),t2=read();sum+=t1+t2;
    g.addw(s,r1,t1);
    for(int j=1;j<=m;j++)g.addw(r1,a[j],inf);
    g.addw(r2,t,t2);
    for(int j=1;j<=m;j++)g.addw(a[j],r2,inf);
  }
  dinic();printf("%lld",sum-ans);
  return 0;
}