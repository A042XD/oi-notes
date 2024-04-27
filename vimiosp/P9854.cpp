#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

signed main(){
  double a,b;
  scanf("%lf%lf",&a,&b);
  double c=a/(b*b);
  if(c>25)puts("Overweight");
  else if(c<18.5)puts("Underweight");
  else puts("Normal weight");
  return 0;
}