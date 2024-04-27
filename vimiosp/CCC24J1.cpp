#include<iostream>
#include<algorithm>

using namespace std;
int r,g,b;
int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

int main(){
  r=read(),g=read(),b=read();
  printf("%d",r*3+g*4+b*5);
  return 0;
}