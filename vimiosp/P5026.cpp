#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e6+6;
int n,m,p=5e4,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,v,x;i<=n;i++){
    v=read(),x=read();
    a[p+x-3*v]++,a[p+x-2*v]-=2;
    a[p+x]+=2;
    a[p+x+2*v]-=2,a[p+x+3*v]++;
  }
  for(int i=1;i<m+p;i++)a[i]+=a[i-1];
  for(int i=1;i<m+p;i++)a[i]+=a[i-1];
  for(int i=p;i<m+p;i++)printf("%d ",a[i]);
  return 0;
}