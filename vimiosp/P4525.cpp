#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
double a,b,c,d,l,r;
double f(double x){return (c*x+d)/(a*x+b);}
double simpson(double l,double r){return(f(l)+4*f((l+r)/2)+f(r))*(r-l)/6;}
double asr(double l,double r,double eps,double ans){
  double m=(l+r)/2,l_=simpson(l,m),r_=simpson(m,r);
  if(fabs(l_+r_-ans)<=15*eps)return l_+r_+(l_+r_-ans)/15;
  return asr(l,m,eps/2,l_)+asr(m,r,eps/2,r_);
}

int main(){
  scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r);
  printf("%.6lf",asr(l,r,1e-6,simpson(l,r)));
  return 0;
}
