#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int t,n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read();
    if(n&1)printf("7"),n-=3;
    while(n)printf("1"),n-=2;
    puts("");
  }  
  return 0;
}