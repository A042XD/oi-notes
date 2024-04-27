#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
char s[10];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int t=read();
  while(t--){
    scanf("%s",s);int a=0;
    for(int i=0;s[i];i++)
      if(s[i]=='A')a++;
    if(a>2)puts("A");
    else puts("B");
  }  
  return 0;
}