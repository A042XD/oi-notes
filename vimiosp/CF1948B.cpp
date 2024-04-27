#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e3+5;
int q,n,h,t,a[N];
bool gt(int x){
  if(x<10)return h=t=x,1;
  bool f=0;
  t=h=x%10;
  while(x){
    x/=10;
    if(x%10>h)f=1;
    if(x>9||x)h=x%10;
  }
  return !f;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  q=read();
  while(q--){
    n=read();
    bool c=0;
    int mx=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
      bool tmp=gt(a[i]);
      if(tmp&&h>=mx)mx=t;
      else if(a[i]>=mx)mx=a[i];
      else c=1;
    }
    puts(c?"NO":"YES");
  }  
  return 0;
}