#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int n,a,b;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),a=read(),b=read();
  if(a>1&&b>1)puts("NO"),exit(0);
  else if(a==1&&b==1){
    if(n==2||n==3)puts("NO");
    else{
      puts("YES");
      for(int i=1;i<=n;i++,putchar('\n'))
        for(int j=1;j<=n;j++)
          putchar(i==j+1||j==i+1?'1':'0');
    }
    exit(0);
  }
  else if(a>1){
    puts("YES");
    for(int i=1;i<=n;i++,putchar('\n'))
      for(int j=1;j<=n;j++)
        if(i>=a&&j>=a)putchar(i==j+1||i+1==j?'1':'0');
        else putchar('0');
  }
  else{
    puts("YES");
    for(int i=1;i<=n;i++,putchar('\n'))
      for(int j=1;j<=n;j++)
        if(i==j)putchar('0');
        else if(i>=b&&j>=b)putchar(i==j+1||i+1==j?'0':'1');
        else putchar('1');
  }
  return 0;
}