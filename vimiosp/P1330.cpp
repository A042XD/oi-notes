#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e4+5,M=2e5+5;
int n,m,cnt[2],ans;
bool v[N],col[N];
struct{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
bool dfs(int x,bool c){
  v[x]=1,col[x]=c,cnt[c]++;
  for(int i=g.hd[x];i;i=g.nx[i]){
    if(v[g.to[i]]&&col[g.to[i]]==c)return 1;
    if(!v[g.to[i]]&&dfs(g.to[i],!c))return 1;
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
  n=read(),m=read();
  for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g.add(u,v),g.add(v,u);
  for(int i=1;i<=n;i++)
    if(!v[i]){
      cnt[0]=cnt[1]=0;
      if(dfs(i,0))puts("Impossible"),exit(0);
      ans+=min(cnt[0],cnt[1]);
    }
  printf("%d",ans);
  return 0;
}