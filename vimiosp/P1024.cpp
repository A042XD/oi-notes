#include<iostream>
#include<algorithm>
#define eps 0.005

using namespace std;
double a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}

int main(){
  cin>>a>>b>>c>>d;
  for(int i=-100;i<100;i++){
    double l=i,r=i+1;
    if(!f(l))printf("%.2lf ",l);
    else if(f(l)*f(r)<0){
      while(r-l>=0.001){
        double m=(l+r)/2;
        if(f(r)*f(m)<=0)l=m;
        else r=m;
      }
      printf("%.2lf ",r);
    }
  }
  return 0;
}
