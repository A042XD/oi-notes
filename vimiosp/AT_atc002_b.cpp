#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
int n,p,m;
int qpow(int a,int k){
  if(!k)return 1;
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
signed main(){
  scanf("%lld%lld%lld",&n,&p,&m);
  printf("%lld\n",qpow(n,m));
  return 0;
}
