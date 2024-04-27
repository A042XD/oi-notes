#include<iostream>
#include<algorithm>
#define int long long

using namespace std;
const int p=1e9+7;
int t,dp[20],pr[20],s[20],k[15],c[20];
int gt(int x){
  int l=0,t=x,ans=0,lst=0;
  while(t)s[++l]=t%10,t/=10; s[l+1]=c[l+1]=0;
  for(int i=l;i>=1;i--)c[i]=c[i+1]+s[i];
  for(int i=l;i>=1;i--)
    if(s[i]!=-1)
      ans=(ans+k[s[i]-1]*pr[i-1]%p+(s[i]-1)*dp[i-1]%p)%p;
  ans+=c[1];
  for(int i=2;i<=l;i++)
    ans+=(c[i]*(s[i-1]-1)*pr[i-2]%p+(s[i-1]-1)*dp[i-2]%p+k[s[i-1]-1]*pr[i-2]%p)%p;
  return ans;
}

signed main(){
  scanf("%lld",&t);pr[0]=1;
  for(int i=1;i<=9;i++)k[i]=k[i-1]+i;
  for(int i=1;i<=18;i++)pr[i]=pr[i-1]*10%p;
  for(int i=1;i<=18;i++)
    dp[i]=(dp[i-1]*10%p+45*pr[i-1]%p)%p;
  while(t--){
    int l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",((gt(r)-gt(l))%p+p)%p);  
  }
  return 0;
}
