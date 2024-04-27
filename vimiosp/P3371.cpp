#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<deque>
#define pii pair<int,int>

using namespace std;
const int N=1e4+5,M=5e5+5;
int n,m,s,dis[N],cnt[N];
bool v[N];
struct{
  int to[M],nx[M],hd[N],t,w[M];
  void add(int u,int v,int k){to[++t]=v,w[t]=k,nx[t]=hd[u],hd[u]=t;}
}g;
bool spfa(){
  for(int i=1;i<=n;i++)dis[i]=2147483647;
  deque<int>q;q.push_front(s),dis[s]=0;
  while(q.size()){
    int u=q.front();q.pop_front(),v[u]=0;
    for(int i=g.hd[u];i;i=g.nx[i])
      if(dis[g.to[i]]>dis[u]+g.w[i]){
        dis[g.to[i]]=dis[u]+g.w[i];
        if((cnt[g.to[i]]=cnt[u]+1)>n)return 0;
        if(!v[g.to[i]]){
          if(q.size()&&dis[q.front()]>dis[g.to[i]])q.push_front(g.to[i]);
          else q.push_back(g.to[i]);
          v[g.to[i]]=1;
        }
      }
  }
  return 1;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),s=read();
  for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),g.add(u,v,w);
  spfa();
  for(int i=1;i<=n;i++)printf("%d ",dis[i]);
  return 0;
}