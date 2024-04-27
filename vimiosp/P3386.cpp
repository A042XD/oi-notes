#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=505,M=5e4+5;
int n,m,e,mch[N],v[N],ans;
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
bool dfs(int x,int dfx){
  for(int i=g.hd[x];i;i=g.nx[i])
    if(v[g.to[i]]!=dfx){
      v[g.to[i]]=dfx;
      if(!mch[g.to[i]]||dfs(mch[g.to[i]],dfx))return mch[g.to[i]]=x,1;
    }
  return 0;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),e=read();
  for(int i=1,u,v;i<=e;i++)u=read(),v=read(),g.add(u,v);
  for(int i=1;i<=n;i++)ans+=dfs(i,i);
  printf("%d",ans);
  return 0;
}