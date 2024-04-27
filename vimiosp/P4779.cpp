#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m,s,dis[N];
struct{
  int to[M],nx[M],hd[N],w[M],t;
  void add(int u,int v,int k){to[++t]=v,w[t]=k,nx[t]=hd[u],hd[u]=t;}
}g;
void dijkstra(int s){
  for(int i=1;i<=n;i++)dis[i]=2147483647;
  priority_queue<pii,vector<pii>,greater<pii>>q;
  q.push(make_pair(dis[s]=0,s));
  while(q.size()){
    int d=q.top().first,u=q.top().second;
    q.pop();if(d!=dis[u])continue;
    for(int i=g.hd[u];i;i=g.nx[i])
      if(dis[g.to[i]]>d+g.w[i])
        q.push(make_pair(dis[g.to[i]]=d+g.w[i],g.to[i]));
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),s=read();
  for(int i=1,u,v,w;i<=m;i++)
    u=read(),v=read(),w=read(),g.add(u,v,w);
  dijkstra(s);
  for(int i=1;i<=n;i++)printf("%d ",dis[i]);
  return 0;
}