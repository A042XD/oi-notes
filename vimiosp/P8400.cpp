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
  int x=read(),y=read(),c=x*8+y*3;
  if(c>28)printf("%d",c-28);
  else printf("0");  
  return 0;
}