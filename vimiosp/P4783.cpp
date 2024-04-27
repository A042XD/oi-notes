#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;
const int N=405,p=1e9+7;
int n;ll a[N][N*2];
ll qp(ll x,ll k){
  ll a=1;
  while(k){
    if(k&1)a=a*x%p;
    x=x*x%p,k/=2;
  }return a%p;
}

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)a[i][i+n]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      scanf("%lld",&a[i][j]);
  for(int i=1,mx=1;i<=n;mx=++i){
    for(int j=i+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
    if(mx!=i)swap(a[i],a[mx]);
    if(!a[i][i])puts("No Solution"),exit(0);
    int c=qp(a[i][i],p-2); 
    for(int j=1;j<=n;j++){
      if(j==i)continue;
      int y=a[j][i]*c%p;
      for(int k=i;k<=n*2;k++)
        a[j][k]=((a[j][k]-y*a[i][k])%p+p)%p;
    }
    for(int j=1;j<=n*2;j++)a[i][j]=a[i][j]*c%p;
  }
  for(int i=1;i<=n;i++){
    for(int j=n+1;j<n*2;j++)printf("%lld ", a[i][j]);
    printf("%lld\n",a[i][n*2]);
  }
  return 0;
}
