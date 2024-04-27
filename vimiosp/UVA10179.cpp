#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=0;
#define int long long // Data type
int phi(int n){
  int ans=n;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      ans=ans/i*(i-1);
      while(n%i==0)n/=i;
    }
  if(n>=2)ans=ans/n*(n-1);
  return ans;
}
int n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){  
  while(n=read()){
    printf("%d\n",phi(n));
  }

  return 0;
}