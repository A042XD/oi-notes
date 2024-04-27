#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e5+5;
int n,a[N],m;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
struct qr{
  int x,y,ans;
  friend bool operator<(qr a,qr b){
    
    return a.y<b.y;
  }
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  m=read();
  
  return 0;
}