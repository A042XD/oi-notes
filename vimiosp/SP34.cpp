#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;
const int N=1005;
int t,nx,ny,n,x[N],y[N];
double dis,ansx,ansy;
double sq(double x){return x*x;}
double rnd(){return (double)rand()/RAND_MAX;}
double calc(double x1,double y1,double r=0){
  r=sqrt(sq(x1-x[1])+sq(y1-y[1]));
  for(int i=2;i<=n;i++)
    r=min(r,sqrt(sq(x1-x[i])+sq(y1-y[i])));
  if(r>dis)dis=r,ansx=x1,ansy=y1;
  return r;
}
void sa(){
  double t=1e4,x1=ansx,y1=ansy,lst=calc(x1,y1);
  while(t>0.0001){
    double x2=x1+t*(rnd()*2-1),y2=y1+t*(rnd()*2-1);
    if(x2>nx||y2>ny||x2<0||y2<0)continue;
    double c=calc(x2,y2);
    if(exp((c-lst)/t)>rnd())x1=x2,y1=y2,lst=c;
    t*=0.999;
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  srand((unsigned)time(NULL));
  t=read();
  while(t--){
    nx=read(),ny=read(),n=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    dis=0,ansx=x[1],ansy=y[1];sa();
    printf("The safest point is (%.1lf, %.1lf).\n",ansx,ansy);
  }  
  return 0;
}