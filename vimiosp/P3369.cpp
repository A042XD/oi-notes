#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<cstdlib>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5;
int n,rt,ls[N],tot,rs[N],sz[N],rd[N],w[N];
void psup(int p){sz[p]=1+sz[ls[p]]+sz[rs[p]];}
int crt(int v){w[++tot]=v,sz[tot]=1,rd[tot]=rand();return tot;}
void spt(int p,int v,int&x,int&y){
  if(!p)return x=y=0,void();
  if(w[p]<=v)spt(rs[p],v,rs[x=p],y);
  else spt(ls[p],v,x,ls[y=p]);
  psup(p);
}
int mrg(int x,int y){
  if(!x||!y)return x+y;
  if(rd[x]<=rd[y])return rs[x]=mrg(rs[x],y),psup(x),x;
  return ls[y]=mrg(x,ls[y]),psup(y),y;
}
void ins(int v){
  int x,y;
  spt(rt,v,x,y);
  rt=mrg(mrg(x,crt(v)),y);
}
void del(int v){
  int x,y,z;
  spt(rt,v,x,z);
  spt(x,v-1,x,y);
  y=mrg(ls[y],rs[y]);
  rt=mrg(mrg(x,y),z);
}
int rnk(int v){
  int x,y;
  spt(rt,v-1,x,y);
  int ans=sz[x]+1;
  return rt=mrg(x,y),ans;
}
int kth(int p,int k){
  while(1)
    if(sz[ls[p]]+1==k)return p;
    else if(k<=sz[ls[p]])p=ls[p];
    else k-=sz[ls[p]]+1,p=rs[p];
}
int pre(int v){
  int x,y;
  spt(rt,v-1,x,y);
  int ans=w[kth(x,sz[x])];
  return rt=mrg(x,y),ans;
}
int suf(int v){
  int x,y;
  spt(rt,v,x,y);
  int ans=w[kth(y,1)];
  return rt=mrg(x,y),ans;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  srand(114514);
  n=read();
  while(n--){
    int op=read(),x=read();
    if(op==1)ins(x);
    if(op==2)del(x);
    if(op==3)printf("%d\n",rnk(x));
    if(op==4)printf("%d\n",w[kth(rt,x)]);
    if(op==5)printf("%d\n",pre(x));
    if(op==6)printf("%d\n",suf(x));
  }
  return 0;
}