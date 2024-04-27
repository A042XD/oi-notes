#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=15;
int n,a[N],m[N],p=1,ans;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void exgcd(int a,int b,int&x,int&y){
  if(!b)x=1,y=0;
  else exgcd(b,a%b,y,x),y=y-a/b*x;
}
int inv(int a,int b){int x,y;exgcd(a,b,x,y);return(x%b+b)%b;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)m[i]=read(),a[i]=read(),p=p*m[i];
  for(int i=1;i<=n;i++)ans+=a[i]*(p/m[i])*inv(p/m[i],m[i]);
  printf("%lld\n",ans%p);
  return 0;
}