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
    for(int i=1;i<=n;i++)a[i]=read();
    if(n==1){puts("YES");continue;}
    bool f=1;
    for(int i=1;i<=n;i+=2)if(a[i]%2!=a[1]%2)f=0;
    for(int i=2;i<=n;i+=2)if(a[i]%2!=a[2]%2)f=0;
    puts(f?"YES":"NO");
  }
  return 0;
}