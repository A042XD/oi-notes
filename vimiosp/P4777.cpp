#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long

using namespace std;
const int N=1e5+5;
int n,b1,b2,a1,a2;
int mul(int a,int b,int p){
  if(a<0&&b<0)a=-a,b=-b;
  else if(b<0)swap(a,b);
  int r=0;
  while(b){
    if(b&1)r=(r+a)%p;
    a=(a+a)%p,b/=2;
  }
  return r;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);} // gcd() & exgcd() & inv()
void exgcd(int a,int b,int&x,int&y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int inv(int a,int b,int x=0,int y=0){exgcd(a,b,x,y);return (x%b+b)%b;}
void mrg(){
  int c=b2-b1,d=gcd(a1,a2),x,y;exgcd(a1/d,a2/d,x,y);
  if(c%d)puts("-1"),exit(0);
  int p=a1/d*a2;
  x=mul(x,c/d,a2/d);if(x<0)x+=a2/d;
  b1=(b1+mul(a1,x,p))%p;if(b1<0)b1+=p;
  a1=p;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    a2=read(),b2=read();
    if(i>1)mrg();
    else a1=a2,b1=b2;
  }
  printf("%lld",b1%a1);
  return 0;
}