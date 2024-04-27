#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
double x1,y1,x2,y2,x3,y3;

signed main(){
  scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
  double k1=-((x2-x1)/(y2-y1)),k2=-((x3-x2)/(y3-y2));
  double b1=(y2+y1)/2-k1*((x2+x1)/2),b2=(y3+y2)/2-k2*((x3+x2)/2);
  double cx=(b2-b1)/(k1-k2),cy=k1*cx+b1,ang=__gcd();
  return 0;
}