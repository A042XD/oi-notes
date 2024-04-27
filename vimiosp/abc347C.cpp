#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=2e5+5;
int n,x,y,a[N],p[N],dp[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),x=read(),y=read();
  for(int i=1;i<=n;i++)a[i]=read(),p[i]=p[i-1]+a[i]-a[i-1];
  int l=1,r=1;
  dp[0]=1;
  for(l=1,r=1;r<=n;r++){
    while(l<r&&p[r]-p[l-1]>=x)l++;
    
  }
  return 0;
}