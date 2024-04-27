#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=25;
int n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  int c=0;
  for(int i=1;i<=n;i++){
    int x=read(),y=read();
    if(5*x-3*y>40)c++;
  }
  printf("%d",c);
  if(c==n)puts("+");
  return 0;
}