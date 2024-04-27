#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5;
int a[N],b[N],n,low[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)b[read()]=i;

  int ans=0;
  for(int i=1;i<=n;i++)
    if(low[ans]<b[a[i]])low[++ans]=b[a[i]];
    else{
      int l=1,r=ans;
      while(l<r){
        int mid=(l+r)/2;
        if(low[mid]<=b[a[i]])l=mid+1;
        else r=mid;
      }
      if(low[l]>b[a[i]])low[l]=b[a[i]];
    }

  printf("%d",ans);
  return 0;
}