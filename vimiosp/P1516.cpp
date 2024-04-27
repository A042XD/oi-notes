#include<iostream>
#include<algorithm>
#define int long long 

using namespace std;
int x,y,n,m,L;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void exgcd(int a,int b,int &x,int &y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int inv(int a,int b){
  int x,y;
  exgcd(a,b,x,y);
  return (x%b+b)%b;
}

signed main(){
  scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
  int t=gcd(L,abs(n-m));
  if((x-y)%t)puts("Impossible"),exit(0);
  if(n-m==0&&x-y!=0)puts("Impossible"),exit(0);
  int a=x-y,b=n-m;
  if(a<0)a=(a%L+L)%L;
  if(b<0)b=(b%L+L)%L;
  a/=t;b/=t;L=L/t;
  printf("%lld",(a*inv(b,L)%L+L)%L);
  return 0;
}
