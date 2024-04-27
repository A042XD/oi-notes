#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=2e5+5;
int c,n,q[2][N],h=1,t;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  c=read(),n=read();
  while(n--){
    int op=read(),x=read();
    if(op==1){
      while(h<=t&&q[0][t]<x)t--;
      q[0][++t]=x,q[1][t]=q[1][t-1]+x;
    }
    else if(op==2){
      while(h<=t&&q[1][t]<)
    }
  }
  return 0;
}