#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
const int N=15;
int n,ans=2147483647,f[N][5],p[N];
int calc(){
  int r=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
      r+=abs(p[i]-p[f[i][j]]);
  return r/2;
}
void sa(){
  double t=6000,k=0.997;
  while(t>1e-7){
    int x=rand()%n+1,y=rand()%n+1;
    swap(p[x],p[y]);
    int c=calc();
    if(c<ans)ans=c;
    else if(exp((ans-c)/t)>(double)rand()/RAND_MAX)swap(p[x],p[y]);
    t*=k;
  }
}

int main(){
  srand(time(0));
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
      scanf("%d",&f[i][j]),p[i]=i;
  while((double)clock()/CLOCKS_PER_SEC<0.92)sa();
  printf("%d",ans);
  return 0;
}
