#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#define MAX_TIME 0.87
#define double long double
#define pii pair<int,int>

using namespace std;
const int N=1e3+5;
int n,x[N],y[N],w[N];
double ansx,ansy,dis;
double sq(double x){return x*x;}
double rnd(){return (double)rand()/RAND_MAX;}
double calc(double x1,double y1,double r=0){
  for(int i=1;i<=n;i++)
    r+=sqrt(sq(x1-x[i])+sq(y1-y[i]))*w[i];
  if(r<dis)dis=r,ansx=x1,ansy=y1;
  return r;
}
void sa(){
  double t=10000,x1=ansx,y1=ansy,lst=calc(x1,y1);
  while(t>0.001){
    double nx=x1+t*(rnd()*2-1),ny=y1+t*(rnd()*2-1),c=calc(nx,ny);
    if(exp(-(c-lst)/t)>rnd())x1=nx,y1=ny,lst=c;
    t*=0.998;
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
  n=read();
  for(int i=1;i<=n;i++){
    x[i]=read(),y[i]=read(),w[i]=read();
    ansx+=x[i],ansy+=y[i];
  }
  ansx/=n,ansy/=n,dis=calc(ansx,ansy);
  while((double)clock()/CLOCKS_PER_SEC<MAX_TIME)sa();
  printf("%.3Lf %.3Lf",ansx,ansy);
  return 0;
}