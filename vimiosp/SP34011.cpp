#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int t=read();
  for(int s=1;s<=t;s++){
    int a=read(),b=read(),c=read();
    printf("Case %d: %lld\n",s,a*(1ll*b*(b+1)/2)*(1ll*c*(c+1)/2));
  }
  return 0;
}