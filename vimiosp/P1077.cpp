#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=105,M=105,p=1e6+7;
int n,m,a[N],dp[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=0;i<=a[1];i++)dp[i]=1; 
  for(int i=2;i<=n;i++)
    for(int j=m;j>=1;j--)
      for(int k=j-1;k>=j-a[i]&&~k;k--)
        dp[j]+=dp[k],dp[j]%=p;
  printf("%lld",dp[m]%p);
  return 0;
}