#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int p=998244353;
int n;
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  printf("%lld\n",26*qpow(25,n-1)%p);
  return 0;
}