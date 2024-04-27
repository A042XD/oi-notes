#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int N=2e3+5,p=998244353;
int n,k,x[N],y[N],ans,s1,s2;
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int inv(int x){return qpow(x,p-2);}

signed main(){
  scanf("%lld%lld",&n,&k);
  for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
  for(int i=1;i<=n;i++){
    s1=y[i]%p,s2=1;
    for(int j=1;j<=n;j++)
      if(i!=j)s1=s1*(k-x[j])%p,s2=s2*((x[i]-x[j]%p)%p)%p;
    ans+=s1*inv(s2)%p,ans=(ans+p)%p;
  }
  printf("%lld\n",ans);
  return 0;
}
