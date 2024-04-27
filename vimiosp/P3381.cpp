#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e3+5,M=1e5+5;
int n,m,s,t,lst[N],pre[N],fl[N],dis[N],ans,mnc;
bool v[N];
struct{
  int to[M],nx[M],hd[N],t=1,w[M],f[M];
  void add(int u,int v,int k,int fl){to[++t]=v,w[t]=k,f[t]=fl,nx[t]=hd[u],hd[u]=t;}
}g;
bool spfa(int s,int t){
  memset(dis,0x3f3f3f,sizeof(dis));
  memset(fl,0x3f3f3f,sizeof(fl));
  memset(v,0,sizeof(v));
  queue<int>q;q.push(s),dis[s]=0,pre[t]=0;
  while(q.size()){
    int u=q.front();q.pop(),v[u]=0;
    for(int i=g.hd[u];i;i=g.nx[i])
      if(g.f[i]>0&&dis[g.to[i]]>dis[u]+g.w[i]){
        dis[g.to[i]]=dis[u]+g.w[i],lst[g.to[i]]=i;
        pre[g.to[i]]=u,fl[g.to[i]]=min(fl[u],g.f[i]);
        if(!v[g.to[i]])v[g.to[i]]=1,q.push(g.to[i]);
      }
  }
  return pre[t];
}
void mcmf(){
  while(spfa(s,t)){
    int u=t;ans+=fl[t],mnc+=fl[t]*dis[t];
    while(u!=s){
      g.f[lst[u]]-=fl[t];
      g.f[lst[u]^1]+=fl[t];
      u=pre[u];
    }
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),s=read(),t=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read(),f=read(),w=read();
    g.add(u,v,w,f),g.add(v,u,-w,0);
  }
  mcmf();printf("%d %d",ans,mnc);
  return 0;
}