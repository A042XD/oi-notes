#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e6+5;
int n,a[N];
struct r{int a,b;}t[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    t[i].a=read(),t[i].b=read();
  }  
  int ans=0,c=0,f=0;
  for(int i=1;i<=n;i++){
    if(ans>=t[i].a-t[i-1].a)ans-=t[i].a-t[i-1].a;
    else ans=0;
    ans+=t[i].b,c=max(c,ans);
  }
  f=t[n].a+ans;
  printf("%lld %lld",f,c);
  return 0;
}