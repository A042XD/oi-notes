#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=1e5+5;
int n,m,du[N],ans;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,u,v;i<=m;i++)u=read(),v=read(),du[u]++,du[v]++;
  for(int i=1;i<=n;i++)ans+=du[i]*(n-1-du[i]);
  printf("%lld",n*(n-1)*(n-2)/6-ans/2);  
  return 0;
}