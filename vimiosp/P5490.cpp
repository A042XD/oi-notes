#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define mid ((cl+cr)/2) // Segtree defs
#define inr (l<=cl&&cr<=r)
#define outr (cr<l||r<cl)
#define pii pair<int,int>

using namespace std;
const int N=1e5+5,D=1e7+5;
int n,tot,t,f[D],ls[D],rs[D],ans;bool v[D];
struct _l{int l,r,y,m;}ln[N*2];
int lt(int x){return ls[x]?ls[x]:ls[x]=++tot;}
int rt(int x){return rs[x]?rs[x]:rs[x]=++tot;}
void chg(int u,int cl,int cr,int l,int r,int x){
  if(l<=cl&&cr<=r){f[u]+=x,v[u]=f[u]||v[ls[u]]||v[rs[u]];return;}
  if(l<=mid)chg(lt(u),cl,mid,l,r,x);
  if(mid<r)chg(rt(u),mid+1,cr,l,r,x);
  v[u]=f[u]||v[ls[u]]||v[rs[u]];
}
int qry(int u,int cl,int cr){
  if(f[u])return cr-cl+1;
  if(!v[u])return 0;int ans=0;
  if(ls[u])ans+=qry(ls[u],cl,mid);
  if(rs[u])ans+=qry(rs[u],mid+1,cr);
  return ans;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  tot=1,n=read();
  for(int i=1,x1,y1,x2,y2;i<=n;i++){
    x1=read(),y1=read(),x2=read(),y2=read();
    ln[++t]={x1,x2,y1,1},ln[++t]={x1,x2,y2,-1};
  }
  sort(ln+1,ln+t+1,[](_l a,_l b){return a.y<b.y;});
  for(int i=1;i<t;i++){
    chg(1,1,1e9,ln[i].l+1,ln[i].r,ln[i].m);
    ans+=qry(1,1,1e9)*(ln[i+1].y-ln[i].y);
  }
  printf("%lld\n",ans);
  return 0;
}