#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int n,m,a,b;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,x,y;i<=n;i++){
    x=read(),y=read();
    if(x==1)a+=y;
    b+=y;
  }  
  printf("%.3lf",a*1.0/b*m);
  return 0;
}