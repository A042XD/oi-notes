#include<iostream>
#include<cmath>
#include<map>
#define int long long

using namespace std;
int k,p;
int mul(int a,int b){
  int l=a*(b>>25)%p*(1<<25)%p;
  int r=a*(b&((1ll<<25)-1))%p;
  return (l+r)%p;
}
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=mul(r,a);
    a=mul(a,a),k/=2;
  }
  return r;
}
int bsgs(int a,int b,int p){
  map<int,int>m;m.clear();int t=ceil(sqrt(p));b%=p;
  for(int i=1;i<=t;i++)b=mul(b,a),m[b]=i;
  a=qpow(a,t);b=1;
  for(int i=1;i<=t;i++){
    b=mul(b,a);int tmp=m[b];
    if(tmp)return ((i*t-tmp)%p+p)%p;
  }
  return -1;
}

signed main(){
  scanf("%lld%lld",&k,&p);
  printf("%lld",bsgs(10,9*k+1,p));
  return 0;
}
