#include <iostream>
#include <algorithm>

using namespace std;
const int N=4e6+5,M=2e7+5;
int n,m,k,dfx,tp,tot,a[N],b[N],s[N],dfn[N],low[N],r[N][2];
bool v[N];
struct gph{
  int to[M],nx[M],hd[N],t;
  void add(int u,int v){to[++t]=v,nx[t]=hd[u],hd[u]=t;}
}g;
void trjn(int u){
  dfn[u]=low[u]=++dfx;s[++tp]=u;v[u]=1;
  for(int i=g.hd[u];i;i=g.nx[i])
    if(!dfn[g.to[i]])trjn(g.to[i]),low[u]=min(low[u],low[g.to[i]]);
    else if(v[g.to[i]])low[u]=min(low[u],dfn[g.to[i]]);
  if(low[u]!=dfn[u])return;tot++;
  do v[u]=0,b[u]=tot,u=s[tp--];while(low[u]!=dfn[u]);
}

int main(){
  scanf("%d%d%d",&n,&m,&k);int cnt=2*n;
  for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g.add(x+n,y),g.add(y+n,x);
  for(int i=1,t;i<=k;i++){
    scanf("%d",&t);
    for(int j=1,x;j<=t;j++){
      scanf("%d",&a[j]);r[a[j]][0]=++cnt;r[a[j]][1]=++cnt;
      g.add(a[j],r[a[j]][0]);g.add(r[a[j]][1],a[j]+n);
    }
    for(int j=2;j<=t;j++){
      g.add(r[a[j-1]][0],r[a[j]][0]);
      g.add(r[a[j]][1],r[a[j-1]][1]);
      g.add(r[a[j-1]][0],a[j]+n);
      g.add(a[j],r[a[j-1]][1]);
    }
  }
  for(int i=1;i<=cnt;i++)if(!dfn[i])trjn(i);
  for(int i=1;i<=n;i++)if(b[i]==b[i+n])puts("NIE"),exit(0);
  puts("TAK");
  return 0;
}
