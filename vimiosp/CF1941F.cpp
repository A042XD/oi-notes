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
int t,n,m,k,a[N],b[N],c[N],d[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++)b[i]=read()*2;
    for(int i=1;i<=k;i++)c[i]=read()*2;
    for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
    sort(d+1,d+n,[](int a,int b){return a>b;});
    sort(b+1,b+m+1);
    sort(c+1,c+k+1);
    int ans=0;
    for(int i=2;i<=n;i++){
      if(a[i]-a[i-1]==d[1]){
        int sec=d[2];

        int mid=a[i]+a[i-1],mn=mid;
        for(int x=m,y=1;x>=1;x--){
          while(y<=k&&b[x]+c[y]<mid){
            y++;
          }
          if(y<=k){
            mn=min(mn,b[x]+c[y]-mid);
          }
          if(y>1){
            mn=min(mn,mid-(b[x]+c[y-1]));
          }
        }
        ans=min(d[1],max(sec,(a[i]-a[i-1]+mn)/2));
        break;
      }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)d[i]=0;
  }
  return 0;
}