#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e5+5;
int n,a[N];
int ms(){
  int i=1,j=0,k=0;
  while(i<=n&&j<=n&&k<=n)
    if(a[(i+k)%n]==a[(j+k)%n])k++;
    else{
      if(a[(i+k)%n]>a[(j+k)%n])i+=k+1;
      else j+=k+1;
      if(i==j)i++;
      k=0;
    }
  return min(i,j);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i-1]=read();
  int mtp=ms();
  for(int i=0;i<n;i++)printf("%d ",a[(i+mtp)%n]);
  return 0;
}