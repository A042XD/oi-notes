#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e6+5;
int n,cnt,tot,ct,ans[N],f[N],p[N],fc[N];bool rt[N],v[N];
void euler(int n){
  f[1]=1;
  for(int i=2;i<=n;i++){
    if(!v[i])p[++cnt]=i,f[i]=i-1;
    for(int j=1;j<=cnt&&i*p[j]<=n;j++){
      v[i*p[j]]=1;
      if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}
      f[i*p[j]]=f[i]*(p[j]-1);
    }
  }
  rt[2]=rt[4]=1;
  for(int i=2;i<=cnt;i++)
    for(int j=1;j*p[i]<=n;j*=p[i])
      rt[j*p[i]]=rt[j*2*p[i]]=1;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int qpow(int a,int k,int p){ // Fast pow
  int r=1;
  while (k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
void proc(int p){
  for(int i=2;i*i<=p;i++)
    if(p%i==0){
      fc[++ct]=i;
      while(p%i==0)p/=i;
    }
  if(p>1)fc[++ct]=p;
}
bool chk(int x,int p){
  if(qpow(x,f[p],p)!=1)return 0;
  for(int i=1;i<=ct;i++)
    if(qpow(x,f[p]/fc[i],p)==1)return 0;
  return 1;
}
int fdrt(int p){for(int i=1;i<p;i++)if(chk(i,p))return i;return 0;}
void gtrt(int p,int x){
  int r=1;
  for(int i=1;i<=f[p];i++){
    r=r*x%p;
    if(gcd(i,f[p])==1)ans[++tot]=r;
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  euler(1e6);
  int t=read();
  while(t--){
    int p=read(),d=read();
    if(rt[p]){
      cnt=ct=0;
      proc(f[p]);
      int zx=fdrt(p);
      gtrt(p,zx);
      sort(ans+1,ans+cnt+1);
      printf("%lld\n",cnt);
      for(int i=1;i<=cnt/d;i++)printf("%lld ",ans[i*d]);
      puts("");
    }
    else puts("0");
  }
  return 0;
}