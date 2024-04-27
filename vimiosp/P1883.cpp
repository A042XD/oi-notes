#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e4+5;
const double eps=1e-9;
int t,n,a[N],b[N],c[N];
double f(double x,int i){return a[i]*x*x+b[i]*x+c[i];}
double calc(double x){
  double ans=f(x,1);
  for(int i=2;i<=n;i++)
    ans=max(ans,f(x,i));
  return ans;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),c[i]=read();
    double l=0,r=1000;
    while(r-l>eps){
      double lm=l+(r-l)/3,rm=r-(r-l)/3;
      if(calc(lm)>calc(rm))l=lm;
      else r=rm;
    }
    printf("%.4lf\n",calc(l));
  }
  return 0;
}