#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e5+5;
int t,n,a[N];
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
    bool f=0;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
      if(a[i]<0){
        puts("NO");
        f=1;
        break;
      }
      if(i+1>=n&&a[i]!=0){
        puts("NO");
        f=1;
        break;
      }
      a[i+1]-=a[i]*2;
      a[i+2]-=a[i];
      a[i]=0;
    }
    if(!f)puts("YES");
  }
  return 0;
}