#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int N=105;
int n;
double a[N][N];

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n+1;j++)scanf("%lf",&a[i][j]);
  for(int i=1,mx=1;i<=n;mx=++i){
    for(int j=i+1;j<=n;j++)if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
    swap(a[i],a[mx]);if(!a[i][i])puts("No Solution"),exit(0);
    for(int j=i+1;j<=n+1;j++)a[i][j]/=a[i][i];a[i][i]=1;
    for(int j=1;j<=n;j++)
      if(j!=i)for(int k=i+1;k<=n+1;k++)a[j][k]-=a[j][i]*a[i][k];
  }
  for(int i=1;i<=n;i++)printf("x%d=%.2lf\n",i,a[i][n+1]/a[i][i]);
  return 0;
}
