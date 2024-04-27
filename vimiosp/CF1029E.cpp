#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e5+5;
int n,m,dep[N],fa[N];
bool v[N];
priority_queue<pii>q;
struct{
  int to[N*2],nx[N*2],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void dfs(int x,int f){
  q.push(make_pair(dep[x]=dep[f]+1,x)),fa[x]=f;
  for(int i=g.hd[x];i;i=g.nx[i])
    if(g.to[i]!=f)dfs(g.to[i],x);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1,u,v;i<n;i++){
    u=read(),v=read();
    g.add(u,v),g.add(v,u);
  }  
  dfs(1,1);int ans=0;
  while(q.size()){
    int u=q.top().second;q.pop();
    if(v[u]||dep[u]<=3||v[fa[u]])continue;
    bool f=0;
    for(int i=g.hd[u];i;i=g.nx[i])f|=v[g.to[i]];
    if(f)continue;
    v[fa[u]]=1,ans++;
  }
  printf("%d",ans);
  return 0;
}