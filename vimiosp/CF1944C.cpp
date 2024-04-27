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
    for(int i=0;i<=n;i++)a[i]=0;
    for(int i=1;i<=n;i++)a[read()]++;
    int ans=0,r1=0,r2=0;
    while(ans<n){
      if(a[ans]==0)r1++;
      if(a[ans]==1)r2++;
      if(r1==1||r2==2)break;
      ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}