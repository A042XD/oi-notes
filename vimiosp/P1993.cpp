#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<deque>

using namespace std;
const int N=5e3+5;
int n,m,dis[N],cnt[N];
bool vis[N];
struct{
  int t,to[N],nx[N],hd[N],w[N];
  void add(int u,int v,int k){to[++t]=v,nx[t]=hd[u],hd[u]=t,w[t]=k;}
}g;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
bool spfa(){
  deque<int>q;
  for(int i=1;i<=n;i++)q.push_back(i),vis[i]=1;
  while(q.size()){
    int u=q.front();q.pop_front();vis[u]=0;
    for(int i=g.hd[u];i;i=g.nx[i])
      if(dis[g.to[i]]>dis[u]+g.w[i]){
        dis[g.to[i]]=dis[u]+g.w[i];
        if((cnt[g.to[i]]=cnt[u]+1)>n)return 0;
        if(!vis[g.to[i]]){
          if(q.size()&&dis[g.to[i]]<dis[q.front()])q.push_front(g.to[i]);
          else q.push_back(g.to[i]);
          vis[g.to[i]]=1;
        }
      }
  }
  return 1;
}

signed main(){
  n=read(),m=read();
  for(int i=1,op,x,y,z;i<=m;i++){
    op=read(),x=read(),y=read();
    if(op!=3)z=read();
    if(op==1)g.add(x,y,-z);
    if(op==2)g.add(y,x,z);
    if(op==3)g.add(x,y,0),g.add(y,x,0);
  }
  if(spfa())puts("Yes");
  else puts("No");
  return 0;
}