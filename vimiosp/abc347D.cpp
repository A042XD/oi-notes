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
const int N=0;
int a,b,c;
int ce(int x){
  int ans=0;
  while(x){
    ans+=(x%2==1);
    x/=2;
  }
  return ans;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  a=read(),b=read(),c=read();
  int ca=a,cb=b,cc=ce(c);
  if(cc>ca+cb)printf("-1"),exit(0);
  
  //printf("   %lld %lld\n",ca,cb);
  int p=59,x=0,y=0;
  for(;~p&&cc;p--){
    if((c*1ll>>p)%2==1){
      if(ca>cb)ca--,x+=(1ll<<p);
      else cb--,y+=(1ll<<p);
      cc--;
    }
  }
  if(ca!=cb)printf("-1"),exit(0);
  if(ca>60-ce(c))printf("-1"),exit(0);
  //printf("    %lld %lld\n",ca,cb);
  for(p=59;~p&&ca;p--)
    if((c*1ll>>p)%2==0){
      x+=(1ll<<p);
      y+=(1ll<<p);
      ca--,cb--;
    }
  
  printf("%lld %lld",x,y);
  //printf("\n %lld\n %lld %lld",x^y,ce(x),ce(y));
  return 0;
}