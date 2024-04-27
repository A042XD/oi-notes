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
const int N=1e5+5,D=40*N;
int n,q,t[D],ls[D],rs[D],tot,rt[N];
int cln(int u){return t[++tot]=t[u],ls[tot]=ls[u],rs[tot]=rs[u],tot;}
int chg(int u,int cl,int cr,int x,int v){
  t[u=cln(u)]+=v;
  if(cl>=cr)return u;
  if(x<=mid)ls[u]=chg(ls[u],cl,mid,x,v);
  else rs[u]=chg(rs[u],mid+1,cr,x,v);
  return u;
}
int tchg(int u,int x,int v){
  for(;u<=n;u+=u&-u)chg(rt[x],0,1e9,x,v);
}
int qry(int cl,int cr,int k){
  
}
int tqry(int cl,int cr,int k){
  
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  rt[0]=tot=1;
  return 0;
}