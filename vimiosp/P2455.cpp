#include<iostream>
#include<algorithm>
#include<cmath>
#define eps 1e-6

using namespace std;
const int N=105;
int n,p;double a[N][N];

int main(){
  scanf("%d",&n);p=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n+1;j++)scanf("%lf",&a[i][j]);
  for(int i=1,mx;i<=n;i++){
    mx=p;
    for(int j=p+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
    if(fabs(a[mx][i])<eps)continue;swap(a[mx],a[p]);
    for(int j=i+1;j<=n+1;j++)a[p][j]/=a[p][i];a[p][i]=1;
    for(int j=1;j<=n;j++)
      if(j!=p)for(int k=i+1;k<=n+1;k++)a[j][k]-=a[j][i]*a[p][k];
    p++;
  }
  p--;
  if(p<n){
    while(p<n)
      if(fabs(a[++p][n+1])>eps)puts("-1"),exit(0);
    puts("0");exit(0);
  }
  for(int i=1;i<=n;i++)printf("x%d=%.2lf\n",i,a[i][n+1]/a[i][i]);
  return 0;
}
