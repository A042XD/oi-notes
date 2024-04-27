#include<iostream>
#include<cmath>
#include<map>
#define int long long

using namespace std;
int t,k,y,z,p;
map<int,int>m;
int qpow(int a,int k,int p){
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void exgcd(int a,int b,int &x,int &y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int wk2(int y,int z,int p){
  int d=gcd(y,p),x,x2;
  if(z<d||z%d)return -1;
  exgcd(y,p,x,x2);
  return (x*z/d%p+p)%p;
}
int bsgs(int a,int b,int p){
  if(a%p==0&&b%p==0)return 1;
  if(a%p==0&&b%p)return -1;
  m.clear();b%=p;int t=ceil(sqrt(p));
  for(int i=1;i<=t;i++)b=b*a%p,m[b]=i;
  a=qpow(a,t,p),b=1;
  for(int i=1;i<=t;i++){
    b=b*a%p;int tmp=m[b];
    if(tmp)return ((i*t-tmp)%p+p)%p;
  }
  return -1;
}

signed main(){
  scanf("%lld%lld",&t,&k);
  while(t--){
    scanf("%lld%lld%lld",&y,&z,&p);
    if(k==1)printf("%lld\n",qpow(y,z,p));
    else{
      int ans;
      if(k==2)ans=wk2(y,z,p);
      else ans=bsgs(y,z,p);
      if(ans==-1)puts("Orz, I cannot find x!");
      else printf("%lld\n",ans);
    }
  }
  return 0;
}
