#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define int long long // Data type

using namespace std;
const int N=35;
int t,n,a[N],ans,a1,a2;
bool v[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int calc(){
  a1=0,a2=0;
  for(int i=1;i<=n;i++)
    if(v[i])a2+=a[i];
    else a1+=a[i];
  return abs(a1-a2);
}
void sa(){
  double t=10000;
  int lst=calc();ans=lst;
  while(t>0.001){
    int p1=rand()%n+1,p2=rand()%n+1;
    if(p1==p2||v[p1]==v[p2])continue;
    if(v[p1])swap(p1,p2);
    int c=abs(a1-a2-2*a[p1]+2*a[p2]);
    ans=min(ans,c);
    //printf("  %d %d %d %d\n",p1,p2,lst,c);
    if(exp(-(c-lst)/t)>(double)rand()/RAND_MAX)
      swap(v[p1],v[p2]),lst=c,a1=a1-a[p1]+a[p2],a2=a2-a[p2]+a[p1];
    t*=0.999;if(ans==0)break;
  }
}

signed main(){
  srand((unsigned)time(NULL));
  t=read();
  while(t--){
    n=read();
    if(n==1){printf("%d\n",read());continue;}
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n/2;i++)v[i]=0;
    for(int i=n/2+1;i<=n;i++)v[i]=1;
    sa();
    printf("%lld\n",ans);
  }  
  return 0;
}