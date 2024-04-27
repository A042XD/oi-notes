#include<iostream>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long

using namespace std;
using namespace __gnu_pbds;
int a,b,p;
gp_hash_table<int,int>m;
int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
void write(int x){
  if(x<0)putchar('-'),x=-x;
  if(x<10)return putchar(x+48),void();
  write(x/10),putchar(x%10+48);
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void exgcd(int a,int b,int& x,int& y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int inv(int a,int b){
  int x,y;
  exgcd(a,b,x,y);
  return (x%b+b)%b;
}
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*1ll*a%p;
    a=a*1ll*a%p;k/=2;
  }
  return r;
}
int bsgs(int a,int b,int p){
  m.clear();int t=ceil(sqrt(p));b%=p;
  for(int i=1;i<=t;i++)b=b*1ll*a%p,m[b]=i;
  a=qpow(a,t),b=1;
  for(int i=1;i<=t;i++){
    b=b*1ll*a%p;int tmp=m[b];
    if(tmp)return (i*1ll*t-tmp+p)%p;
  }
  return -1;
}
int exbsgs(int a,int b,int p){
  if(b==1||p==1)return 0;
  int d=gcd(a,p),k=0,na=1;
  while (d>1){
    if(b%d!=0)return -1;
    k++;b/=d,p/=d;na=na*1ll*(a/d)%p;
    if(na==b)return k;
    d=gcd(a,p);
  }
  int r=bsgs(a,b*1ll*inv(na,p)%p,p);
  if(r==-1)return -1;
  return r+k;
}

int main(){
  a=read(),p=read(),b=read();
  while(a||b||p){
    a%=p,b%=p;
    int ans=exbsgs(a,b,p);
    if(ans==-1)puts("No Solution");
    else write(ans),putchar('\n');
    a=read(),p=read(),b=read();
  }
  return 0;
}
