#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long

using namespace std;
const int N=1e5+5;
int t,n,m,p,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int qpow(int a,int k,int p){ // Fast pow
  int r=1;
  while (k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int c(int n,int m){
  if(m>n)return 0;
  return a[n]*qpow(a[m],p-2,p)%p*qpow(a[n-m],p-2,p)%p;
}
int lucas(int n,int m){
  if(!m)return 1;
  return c(n%p,m%p)*lucas(n/p,m/p)%p;
}

signed main(){
  t=read(),a[0]=1;
  while(t--){
    n=read(),m=read(),p=read();
    for(int i=1;i<=p;i++)a[i]=(a[i-1]*i)%p;
    printf("%lld\n",lucas(n+m,n));
  }
  return 0;
}