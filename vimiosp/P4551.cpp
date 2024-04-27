#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5,C=N*31,M=2*N;
int n,c[C][2],tot,k[C],ans,dis[N];
struct{
  int to[M],nx[M],hd[N],t,w[M];
  void add(int u,int v,int k){to[++t]=v,w[t]=k,nx[t]=hd[u],hd[u]=t;}
}g;
void ins(int x,int p=0){
  for(int i=31;~i;i--){
    int t=(x>>i)&1;
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  k[p]=x;
}
void qry(int x,int p=0){
  for(int i=31;~i;i--){
    int t=(x>>i)&1;
    if(c[p][!t])p=c[p][!t];
    else p=c[p][t];
  }
  ans=max(ans,x^k[p]);
}
void dfs(int x,int f){
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f){
      dis[g.to[i]]=dis[x]^g.w[i];
      qry(dis[g.to[i]]),ins(dis[g.to[i]]);
      dfs(g.to[i],x);
    }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1,u,v,w;i<n;i++){
    u=read(),v=read(),w=read();
    g.add(u,v,w),g.add(v,u,w);
  }
  ins(0);dfs(1,1);printf("%d",ans);
  return 0;
}