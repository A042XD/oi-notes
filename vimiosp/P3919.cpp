#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>
#define mid ((cl+cr)/2)

using namespace std;
const int N=1e6+5,D=25*N;
int n,q,a[N],t[D],ls[D],rs[D],tot,rt,c[N];
int cln(int u){return t[++tot]=t[u],ls[tot]=ls[u],rs[tot]=rs[u],tot;}
int bld(int cl,int cr){
  int u=++tot;
  if(cl>=cr)return t[u]=a[cl],u;
  ls[u]=bld(cl,mid),rs[u]=bld(mid+1,cr);
  return u;
}
int chg(int u,int cl,int cr,int x,int v){
  u=cln(u);
  if(cl>=cr)return t[u]=v,u;
  if(x<=mid)ls[u]=chg(ls[u],cl,mid,x,v);
  else rs[u]=chg(rs[u],mid+1,cr,x,v);
  return u;
}
int qry(int u,int cl,int cr,int x){
  if(cl>=cr)return t[u];
  if(x<=mid)return qry(ls[u],cl,mid,x);
  return qry(rs[u],mid+1,cr,x);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),q=read();
  for(int i=1;i<=n;i++)a[i]=read();
  c[0]=bld(1,n);
  for(int i=1;i<=q;i++){
    int t=read(),op=read(),x=read(),y;
    if(op==1){
      y=read();
      c[i]=chg(c[t],1,n,x,y);
    }
    else printf("%d\n",qry(c[t],1,n,x)),c[i]=c[t];
  }
  return 0;
}