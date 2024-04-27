#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define mid ((cl+cr)/2)
#define inr (l<=cl&&cr<=r)
#define outr (cr<l||r<cl)
#define pii pair<int,int>

using namespace std;
const int N=1e5+5,D=4e5+5;
int n,m,a[N],t[D],lz[D];
void psup(int u){t[u]=t[u*2]+t[u*2+1];}
void mktg(int u,int ln,int x){t[u]+=ln*x,lz[u]+=x;}
void bld(int u,int cl,int cr){
  if(cl>=cr)return t[u]=a[cl],void();
  bld(u*2,cl,mid),bld(u*2+1,mid+1,cr);
  psup(u);
}
void psdn(int u,int cl,int cr){
  mktg(u*2,mid-cl+1,lz[u]);
  mktg(u*2+1,cr-mid,lz[u]);
  lz[u]=0;
}
void chg(int u,int cl,int cr,int l,int r,int x){
  if inr return mktg(u,cr-cl+1,x);
  if outr return;
  psdn(u,cl,cr);
  chg(u*2,cl,mid,l,r,x);
  chg(u*2+1,mid+1,cr,l,r,x);
  psup(u);
}
int qry(int u,int cl,int cr,int l,int r){
  if inr return t[u];
  if outr return 0;
  psdn(u,cl,cr);
  return qry(u*2,cl,mid,l,r)+qry(u*2+1,mid+1,cr,l,r);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read();
  bld(1,1,n);
  while(m--){
    int op=read(),x=read(),y=read(),z;
    if(op==1)z=read(),chg(1,1,n,x,y,z);
    else printf("%lld\n",qry(1,1,n,x,y));
  }
  return 0;
}