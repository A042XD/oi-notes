#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define mid ((1ll*cl+cr)/2)
#define pii pair<int,int>

using namespace std;
const int N=2e5+5,D=40*N,w=1e9+2,lm=2e9+30;
int n,m,ls[D],rs[D],tot,t[D],rt[N];
int cln(int u){return t[++tot]=t[u],ls[tot]=ls[u],rs[tot]=rs[u],tot;}
int chg(int u,int cl,int cr,int x,int v){
  t[u=cln(u)]+=v;
  if(cl>=cr)return u;
  if(x<=mid)ls[u]=chg(ls[u],cl,mid,x,v);
  else rs[u]=chg(rs[u],mid+1,cr,x,v);
  return u;
}
int qry(int u,int v,int cl,int cr,int k){
  if(cl>=cr)return cl;
  if(k<=t[ls[v]]-t[ls[u]])return qry(ls[u],ls[v],cl,mid,k);
  return qry(rs[u],rs[v],mid+1,cr,k-t[ls[v]]+t[ls[u]]);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),rt[0]=tot=1;
  for(int i=1,x;i<=n;i++)x=read(),rt[i]=chg(rt[i-1],1,lm,x+w,1);
  while(m--){
    int l=read(),r=read(),k=read();
    printf("%d\n",qry(rt[l-1],rt[r],1,lm,k)-w);
  }
  return 0;
}