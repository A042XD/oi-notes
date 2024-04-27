#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=1e4+5;
int n;
double ans;
struct{int x,y;}p[N];
double sq(double x){return x*x;}
double dis(int x,int y){return sqrt(sq(p[x].x-p[y].x)+sq(p[x].y-p[y].y));}

int main (int argc, char *argv[]) {
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
  ans=dis(1,2);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(i!=j)
        ans=min(ans,dis(i,j));
  printf("%.4lf",ans);
  return 0;
}
