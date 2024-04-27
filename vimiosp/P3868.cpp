#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int N=20;
int p=1,n,ans,a[N],b[N];
int mul(int a,int b,int p){
  int r=0;
  while(b){
    if(b&1)r=(r+a)%p;
    a=(a+a)%p,b/=2;
  }
  return r;
}
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
  scanf("%lld",&n);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=1;i<=n;i++)scanf("%lld",&b[i]),p*=b[i];
  for(int i=1;i<=n;i++)a[i]=(a[i]%b[i]+b[i])%b[i];
  for(int i=1;i<=n;i++)ans=(ans+mul(a[i],mul(p/b[i],inv(p/b[i],b[i]),p),p))%p;
  printf("%lld",(ans)%p);
  return 0;
}
