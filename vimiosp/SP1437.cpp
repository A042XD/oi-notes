#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int M=2e4+5,N=1e4+5;
int n,dep[N],mx,dp[N],d;
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void dfs(int x,int f){
  dep[x]=dep[f]+1;
  if(dep[x]>dep[mx])mx=x;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f)dfs(g.to[i],x);
}
void dfs1(int x,int f){
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f){
      dfs1(g.to[i],x);
      d=max(d,dp[x]+dp[g.to[i]]+1);
      dp[x]=max(dp[x],dp[g.to[i]]+1);
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
  for(int i=1,u,v;i<n;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  dfs1(1,0);
  printf("%d",d);
  return 0;
}