#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int k;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  k=read();bool f=0;
  for(int i=100;i<=999;i++)
    if(i/10%k==0&&i%100%k==0&&i%k==0)
      f=1,printf("%d\n",i);
  if(!f)puts("None!");
  return 0;
}