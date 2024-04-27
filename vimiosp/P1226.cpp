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
int a,b,p;
int qpow(int a,int b,int p){
  int r=1;
  while(b){
    if(b&1)r=r*a%p;
    a=a*a%p,b/=2;
  }
  return r;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}


signed main(){
  a=read(),b=read(),p=read();
  printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));
  return 0;
}