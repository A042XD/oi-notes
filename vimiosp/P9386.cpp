#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int t,n,a[N];
struct{
  int t,nx[N],to[N],hd[N];
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

int z[N],cnt[N];
bool q[N],flag;
void dfs(int x,int f){
  z[x]=-1;
  for(int i=g.hd[x];i;i=g.nx[i])
    dfs(g.to[i],x);
  
  if(z[x]==-1)z[x]=0,q[x]=1;
  else if(cnt[x]>1)z[x]++;
  
  if(a[x]!=-1){
    if(q[x]&&z[x]>a[x])flag=1;
    if(!q[x]&&z[x]!=a[x])flag=1;
  }

  if(a[x]!=-1)z[x]=a[x],q[x]=0;
  q[f]|=q[x];
  if(z[f]==-1)z[f]=z[x],cnt[f]=1;
  else if(z[f]==z[x])cnt[f]++;
  else if(z[x]>z[f])cnt[f]=1,z[f]=z[x];
  //printf("  %d %d %d %d\n",x,z[x],q[x],flag);
}

signed main(){
  t=read();
  while(t--){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),g.add(u,v);
    dfs(1,0);
    if(flag)puts("Unreasonable");
    else puts("Reasonable");
    flag=g.t=0;
    for(int i=1;i<=n;i++)z[i]=cnt[i]=q[i]=g.hd[i]=0;
  }
  return 0;
}