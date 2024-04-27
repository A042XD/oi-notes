#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

signed main(){
  double a,b,c,d,e,x,y;
  scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&x,&y);
  double ca=a*x+b*y,cb=c*y,cc=d*y+e;
  if(ca>cb&&ca>cc)printf("1 %.2lf",ca);
  else{
    if(cb>cc)printf("2 %.2lf",cb);
    else printf("3 %.2lf",cc);
  }
  return 0;
}