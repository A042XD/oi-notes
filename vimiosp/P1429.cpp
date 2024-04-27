#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;
const int N=2e5+65;
int n;
struct _p{double x1,y1,x2,y2;}p[N];
bool cmp(_p a,_p b){return a.x2<b.x2;}
double sq(double x){return x*x;}
double dis(int i,int j){return sqrt(sq(p[i].x2-p[j].x2)+sq(p[i].y2-p[j].y2));}

int main (int argc, char *argv[]) {
  srand(time(0));
  scanf("%d",&n);
  double z,w,t=rand()%3;
  z=sin(1),w=cos(1);
  for(int i=1;i<=n;i++){
    double x,y;
    scanf("%lf%lf",&x,&y);
    p[i].x1=x,p[i].y1=y;
    p[i].x2=x*w-y*z;
    p[i].y2=x*z+y*w;
  }
  sort(p+1,p+n+1,cmp);
  for(int i=n+1;i<=n+55;i++)p[i].x2=p[i].y2=-N-0.01;
  double ans=2e9+0.01;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=50;j++){
      double d=dis(i,i+j);
      if(ans>d)ans=d;
    }
  printf("%.4lf\n",ans);
  return 0;
}

