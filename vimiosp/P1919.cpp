#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=2e6+5;const double pi=acos(-1.0);
int limit=1,n,m,l,r[N],p[N],t[N];
char c[N],d[N];
struct cpx{
  double x,y;
  cpx(double xx=0,double yy=0){x=xx,y=yy;}
}a[N];
cpx operator+(cpx a,cpx b){return cpx(a.x+b.x,a.y+b.y);}
cpx operator-(cpx a,cpx b){return cpx(a.x-b.x,a.y-b.y);}
cpx operator*(cpx a,cpx b){return cpx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
void fft(cpx *a,int tp){
  for(int i=0;i<limit;i++)if(i<p[i])swap(a[i],a[p[i]]);
  for(int mid=1;mid<limit;mid*=2){
    cpx wn(cos(pi/mid),tp*sin(pi/mid));
    for(int rr=mid*2,j=0;j<limit;j+=rr){
      cpx w(1,0);
      for(int k=0;k<mid;k++,w=w*wn){
        cpx x=a[j+k],y=w*a[j+mid+k];
        a[j+k]=x+y;
        a[j+mid+k]=x-y;
      }
    }
  }
}

int main(){
  scanf("%s%s",c,d);n=-1,m=-1;
  for(int i=0;c[i];i++)a[++n].x=c[i]-'0';
  for(int i=0;d[i];i++)a[++m].y=d[i]-'0';
  if(n<m)swap(n,m);
  while(limit<=n+m)limit*=2,l++;
  for(int i=0;i<limit;i++)p[i]=(p[i/2]/2)|((i&1)<<(l-1));
  fft(a,1);
  for(int i=0;i<=limit;i++)a[i]=a[i]*a[i];
  fft(a,-1);
  for(int i=0;i<=n+m;i++) t[i]=int(a[i].y/2/limit+0.5);
  for(int i=n+m;i>=1;i--)t[i-1]+=t[i]/10,t[i]%=10;
  for(int i=0;i<=n+m;i++)printf("%lld",t[i]);
  return 0;
}
