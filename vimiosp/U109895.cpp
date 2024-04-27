#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=5e5+5;
int n,q,c[N*35][2],k[N*35],tot;
void ins(int x,int p=0){
  for(int i=32;~i;i--){
    int t=((x>>i)&1);
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  k[p]=x;
}
int qry(int x,int p=0){
  for(int i=32;~i;i--){
    int t=!((x>>i)&1);
    if(c[p][t])p=c[p][t];
    else p=c[p][!t];
  }
  return p;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),q=read();int x=0;
  for(int i=1;i<=n;i++)x=read(),ins(x);
  while(q--)x=read(),printf("%lld\n",k[qry(x)]);
  return 0;
}