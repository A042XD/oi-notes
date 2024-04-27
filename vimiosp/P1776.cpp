#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e6+5;
int n,m,ans,tot,f[N],w[N],v[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++){
    int x=read(),y=read(),z=read();
    for(int j=1;j<=z;j*=2)
      v[++tot]=j*x,w[tot]=j*y,z-=j;
    if(z)v[++tot]=x*z,w[tot]=y*z;
  }  
  for(int i=1;i<=tot;i++)
    for(int j=m;j>=w[i];j--)
      f[j]=max(f[j],f[j-w[i]]+v[i]);
  printf("%d\n",f[m]);
  return 0;
}