#include<iostream>
#include<algorithm>

using namespace std;
const int N=15;
const double eps=1e-6;
int n;
double a[N],l,r;
double cal(double x){
  double tmp=1,ans=0;
  for(int i=n;i>=0;i--,tmp*=x)ans+=a[i]*tmp;
  return ans;
}
double find(double l,double r){
  double lm,rm;
  while(r-l>=eps){
    lm=l+(r-l)/3,rm=r-(r-l)/3;
    if(cal(lm)>cal(rm))r=rm;
    else l=lm;
  }
  return (lm+rm)/2;
}

int main (int argc, char *argv[]) {
  scanf("%d%lf%lf",&n,&l,&r);
  for(int i=0;i<=n;i++)scanf("%lf",&a[i]);
  printf("%.5lf\n",find(l,r));
  return 0;
}
