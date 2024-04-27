#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e6+5;
const double pi=acos(-1.0);
int n,m,limit=1,l,p[N];
struct cpx{
  double x,y;
  cpx(double xx=0,double yy=0){x=xx,y=yy;}
}a[N];
cpx operator+(cpx a,cpx b){return cpx(a.x+b.x,a.y+b.y);}
cpx operator-(cpx a,cpx b){return cpx(a.x-b.x,a.y-b.y);}
cpx operator*(cpx a,cpx b){return cpx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
void fft(cpx*a,int tp){
  for(int i=0;i<limit;i++)if(i<p[i])swap(a[i],a[p[i]]);
  for(int mid=1;mid<limit;mid*=2){
    cpx wn(cos(pi/mid),tp*sin(pi/mid));
    for(int j=0;j<limit;j+=mid*2){
      cpx w(1,0);
      for(int k=0;k<mid;k++,w=w*wn){
        cpx x=a[j+k],y=w*a[j+mid+k];
        a[j+k]=x+y;
        a[j+mid+k]=x-y;
      }
    }
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=0;i<=n;i++)a[i].x=read();
  for(int i=0;i<=m;i++)a[i].y=read();
  while(limit<=n+m)limit*=2,l++;
  for(int i=0;i<limit;i++)p[i]=(p[i/2]/2)|((i&1)<<(l-1));
  
  fft(a,1);
  for(int i=0;i<limit;i++)a[i]=a[i]*a[i];
  fft(a,-1);

  for(int i=0;i<=n+m;i++)printf("%d ",int(a[i].y/limit/2+0.1));
  return 0;
}