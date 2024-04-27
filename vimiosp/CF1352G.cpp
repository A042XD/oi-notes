#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1005;
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
    if(n<4){puts("-1");continue;}
    for(int i=(n-1)/2*2+1;i>=1;i-=2)printf("%d ",i);
    printf("4 2 ");
    for(int i=6;i<=n;i+=2)printf("%d ",i);
    puts("");
  }
  return 0;
}