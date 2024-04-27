#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=105;
int t,n1,n2,n0;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n0=read(),n1=read(),n2=read();
    if(!n1&&n0){
      printf("0");
    }
    if(!n1&&n2){
      printf("1");
    }
    if(n1&&n1%2==0)printf("1"),n1--;
    for(int i=1;i<=n0;i++)printf("0");
    if(n1)printf("01"),n1--;
    while(n1)printf("01"),n1-=2;
    for(int i=1;i<=n2;i++)printf("1");
    puts("");
  }
  return 0;
}