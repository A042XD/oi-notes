#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e5+5;
int t,n,dp[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int gt(int x){
  int ans=0;
  while(x)ans+=x%10,x/=10;
  return ans;
}

signed main(){
  t=read();
  for(int i=1;i<=2e5+2;i++)dp[i]=dp[i-1]+gt(i);
  while(t--){
    n=read();
    printf("%lld\n",dp[n]);
  }
  return 0;
}