#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
int a;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  a=read();
  bool f=0;
  if(a%10)f=1;
  printf("%lld",a/10+f*(a>0)); 
  return 0;
}