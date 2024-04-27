#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5005;
int n,ans,a[N],low[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)
    if(a[i]>low[ans])low[++ans]=a[i];
    else{
      int l=1,r=ans;
      while(l<r){
        int mid=(l+r)/2;
        if(low[mid]<a[i])l=mid+1;
        else r=mid;
      }
      low[l]=a[i];
    }  
  printf("%d",ans);
  return 0;
}