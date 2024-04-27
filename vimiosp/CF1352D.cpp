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
const int N=1005;
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
    int l=1,r=n,ansl=0,ansr=0,a1=0,a2=0,cnt=0;
    ansl=a1=a[1],l=2,cnt=1;
    //printf("    %d %d %d\n",ansl,l,cnt);
    while(l<=r){
      a2=0;
      while(l<=r&&a2<=a1)a2+=a[r--];
      ansr+=a2;
      cnt++;
      if(l>r)break;
      //printf("     %d %d %d\n",ansr,r,cnt);
      a1=0;
      while(l<=r&&a1<=a2)a1+=a[l++];
      ansl+=a1;
      cnt++;
      //printf("    %d %d %d\n",ansl,l,cnt);
    }
    printf("%lld %lld %lld\n",cnt,ansl,ansr);
  }
  return 0;
}