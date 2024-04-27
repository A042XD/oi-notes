#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N=155;
int n,t,ans,a[N],c[N][N];

signed main(){
  scanf("%lld",&n);ans=1;
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]),t+=a[i];
  if(n==1&&a[1]==0)puts("1"),exit(0);
  if(t-n!=n-2)puts("0"),exit(0);
  c[0][0]=1;
  for(int i=1;i<=n;i++){
    c[i][0]=1;
    for(int j=1;j<=i;j++)
      c[i][j]=c[i-1][j]+c[i-1][j-1];
  }for(int i=1,k=0;i<=n;i++)
    ans=ans*c[n-2-k][a[i]-1],k+=a[i]-1;
  printf("%lld",ans);
  return 0;
}
