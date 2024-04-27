#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e5+5;
const double pi=acos(-1.0);
int t,p[N],limit=1,l,ans[N];
char s1[N],s2[N],c[6]={'0','A','T','C','G'};
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
  t=read();
  while(t--){
    scanf("%s%s",s1,s2);
    int n=strlen(s1),m=strlen(s2);
    while(limit<=n+m)limit*=2,l++;
    for(int i=0;i<limit;i++)
      p[i]=(p[i/2]/2)|((i&1)<<(l-1));
    for(int i=1;i<=4;i++){
      for(int j=0;s1[j];j++)a[j].x=double(s1[j]==c[i]);
      for(int j=0;s2[j];j++)a[m-1-j].y=double(s2[j]==c[i]);
      fft(a,1);
      for(int j=0;j<limit;j++)a[j]=a[j]*a[j];
      fft(a,-1);
      for(int j=0;j<n-m+1;j++)ans[j]+=int(a[m+j-1].y/limit/2+0.1);
      for(int j=0;j<limit;j++)a[j].x=a[j].y=0;
    }
    int cnt=0;
    for(int i=0;i<n;i++)if(ans[i]+3>=m)cnt++;
    printf("%d\n",cnt);
    for(int i=0;i<limit;i++)p[i]=0;
    for(int i=0;i<n;i++)ans[i]=0;
    limit=1,l=0;
  }
  return 0;
}