#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=4e5+5,p=1e9+7;
int t,n,f[N],x[N],y[N];
bool v[N];
int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))f[x]=y;}
int qpow(int a,int k){
  int r=1;
  while(k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();int dfx=0,ans=0,w=0;
    for(int i=1;i<=n;i++)f[i]=i,v[i]=0;
    for(int i=1;i<=n;i++)x[i]=read();
    for(int i=1;i<=n;i++)y[i]=read();
    for(int i=1;i<=n;i++){
      mrg(x[i],y[i]);
      if(x[i]==y[i])w++;
    }
    for(int i=1;i<=n;i++)v[fd(i)]=1;
    for(int i=1;i<=n;i++)ans+=v[i];
    printf("%lld\n",qpow(2,ans-w));
  }
  return 0;
}