#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
int a,p,phi=1,x,f;
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}

signed main(){
  scanf("%lld%lld",&a,&p);a%=p;
  int pp=p;
  for(int i=2;i*i<=pp;i++){
    if(pp%i)continue;
    phi*=i-1,pp/=i;
    while(pp%i==0)
      phi*=i,pp/=i;
  }
  if(pp>1)phi*=pp-1;
  char c=getchar();
  while(c<'0'||c>'9')c=getchar();
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();if(x>=phi)f=1,x%=phi;}
  if(x>=phi)f=1,x%=phi;
  if(f)x+=phi;
  printf("%lld",qpow(a,x));
  return 0;
}
